#include "common/QueryParsers.hpp"

#include "Utils/src/Utils.hpp"

#include <regex>
#include <functional>

namespace Moonlight::Parser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

constexpr auto c_query_prefix{ "select" };

Objects::Alias parseStructureAlias(std::string seq)
{
    static const std::regex s_regex(R"((\w+)\s+as\s+(\w+))", std::regex_constants::icase);

    Objects::Alias out{};

    std::smatch match{};
    if (std::regex_match(seq, match, s_regex))
    {
        out.original = match.str(1);
        out.alias = match.str(2);
    }
    else if (isValidIdentifier(seq))
    {
        out.original = std::move(seq);
        out.alias = out.original;
    }
    else
    {
        throw std::runtime_error("Invalid structure alias @ '"s + seq + "'"s);
    }

    return out;
}

Objects::Alias parseFieldAlias(std::string seq)
{
    static const std::regex s_regex(R"((\w+\.\w+)\s+as\s+(\w+))", std::regex_constants::icase);
    static const std::regex s_field_regex(R"(\w+\.\w+)", std::regex_constants::icase);

    Objects::Alias out{};

    std::smatch match{};
    if (std::regex_match(seq, match, s_regex))
    {
        out.original = match.str(1);
        out.alias = match.str(2);
    }
    else if (std::regex_match(seq, s_field_regex))
    {
        out.original = std::move(seq);
        out.alias = out.original;
    }
    else
    {
        throw std::runtime_error("Invalid field alias @ '"s + seq + "'"s);
    }

    return out;
}

Objects::Join parseJoin(std::string seq)
{
    static const std::regex s_regex(R"((\w+)\s*=>\s*(\w+)\s+on\s+(\w+))", std::regex_constants::icase);

    Objects::Join out{};

    std::smatch match{};
    if (std::regex_match(seq, match, s_regex))
    {
        out.child = match.str(1);
        out.father = match.str(2);
        out.reference_field = match.str(3);
    }
    else
    {
        throw std::runtime_error("Invalid join @ '"s + seq + "'"s);
    }

    return out;
}

Objects::OrderBy parseOrderBy(std::string seq)
{
    static const std::regex s_field_regex(R"(\w+\.\w+)", std::regex_constants::icase);

    const std::string_view seq_sv = seq;
    const auto whitespace_pos = seq_sv.find_first_of(WHITESPACE);

    auto field = seq_sv.substr(0, whitespace_pos);
    auto type = seq_sv.substr(whitespace_pos + 1);

    trim(field);
    trim(type);

    if (field.empty())
    {
        throw std::runtime_error("Missing field @ '"s + seq + "'"s);
    }

    if (type.empty())
    {
        throw std::runtime_error("Missing sort type @ '"s + seq + "'"s);
    }

    Objects::OrderBy out{};

    out.field = field;
    out.type = Primitives::SelectSortType::to_literal(std::string(type));

    if (!std::regex_match(out.field, s_field_regex))
    {
        throw std::runtime_error("Invalid field @ '"s + seq + "'"s);
    }

    return out;
}

template<typename T>
std::vector<T> extractAndParseList(std::string_view& query, std::string_view keyword, std::function<T(std::string)> parse)
{
    const auto aliases = extractList(query, keyword);

    std::vector<T> out{};
    out.reserve(aliases.size());

    for (const auto alias : aliases)
    {
        out.emplace_back(parse(std::string(alias)));
    }

    return out;
}

} // Anonymous namespace

QUERY_PARSER_CLASS_IMPL(Select, c_query_prefix)
{
    QUERY_OBJECT(obj, Select);

    cleanupQuery(query, c_query_prefix);

    obj.from = extractAndParseList<Objects::Alias>(query, "from", parseStructureAlias);
    obj.fields = extractAndParseList<Objects::Alias>(query, "fields", parseFieldAlias);
    obj.join = extractAndParseList<Objects::Join>(query, "join", parseJoin);
    obj.where = Objects::Helpers::parseWhereClause(extractValue(query, "where"));
    obj.order_by = extractAndParseList<Objects::OrderBy>(query, "order_by", parseOrderBy);

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::Parser::Implementation
