#include "common/QueryParsers.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::Parser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

constexpr auto c_query_prefix{ "update" };

std::vector<Objects::SetClauseItem> extractSetClause(std::string_view& query)
{
    const auto items = extractList(query, "set", EParserModifier::EscapeQuotes);

    std::vector<Objects::SetClauseItem> out{};
    out.reserve(items.size());

    for (const auto item : items)
    {
        const auto arrow_pos = item.find("=>");

        if (arrow_pos == std::string_view::npos)
        {
            throw std::runtime_error("Missing '=>' symbol in set clause @ '"s + std::string(item) + "'"s);
        }

        auto field = item.substr(0, arrow_pos);
        trim(field);
        if (field.empty())
        {
            throw std::runtime_error("Empty field in set clause @ '"s + std::string(item) + "'"s);
        }
        if (!isValidIdentifier(field))
        {
            throw std::runtime_error("Invalid identifier '"s + std::string(field) + "'"s);
        }

        if (arrow_pos + 2 >= query.length() - 1)
        {
            throw std::runtime_error("Missing expression in set clause @ '"s + std::string(item) + "'"s);
        }
        auto expression = item.substr(arrow_pos + 2);
        trim(expression);
        if (expression.empty())
        {
            throw std::runtime_error("Missing expression in set clause @ '"s + std::string(item) + "'"s);
        }

        out.emplace_back(std::string(field), std::string(expression));
    }

    return out;
}

} // Anonymous namespace

QUERY_PARSER_CLASS_IMPL(Update, c_query_prefix)
{
    QUERY_OBJECT(obj, Update);

    cleanupQuery(query, c_query_prefix);

    obj.name = extractIdentifier(query, "structure");
    obj.set = extractSetClause(query);
    obj.where = Objects::Helpers::parseWhereClause(extractValue(query, "where", EParserModifier::EscapeQuotes));

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::Parser::Implementation
