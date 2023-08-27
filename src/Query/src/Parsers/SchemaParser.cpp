#include "../QueryParser.hpp"

#include "SchemaFieldParsers.hpp"

#include "Utils/src/Utils.hpp"

#include <array>

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

constexpr auto c_query_prefix{ "schema" };

std::vector<std::string> extractInherits(std::string_view& query)
{
    std::vector<std::string> out{};

    try
    {
        out = extractIdentifiersList(query, "inherits");
    }
    catch (const std::runtime_error& e)
    {
        if (!equalsIgnoreCase(e.what(), "Invalid query, missing 'inherits' keyword"))
        {
            throw e;
        }
    }

    return out;
}

QueryData::Field parseField(std::string_view field)
{
    using namespace FieldParsers;
    static HierarchyMap<IFieldParser, FIELD_PARSERS> s_parsers{};

    const auto parser_ptr = s_parsers.findIf([field](auto& field_parser) -> bool {
        bool is_match = field_parser.match(std::string(field));

        if (!is_match)
        {
            field_parser.clear();
        }

        return is_match;
        });

    if (!parser_ptr)
    {
        throw std::runtime_error("Invalid field declaration"s + std::string(field));
    }

    const auto parsed_field = parser_ptr->parse();
    parser_ptr->clear();

    return parsed_field;
}

std::vector<QueryData::Field> extractFields(std::string_view& query)
{

    const auto fields{ extractList(query, "fields", EParserModifier::EscapeQuotes) };

    std::vector<QueryData::Field> out{};
    out.reserve(fields.size());

    for (const auto field : fields)
    {
        out.emplace_back(parseField(field));
    }

    return out;
}

std::vector<std::string> extractRestrictions(std::string_view& query)
{
    std::vector<std::string> out{};

    try
    {
        const auto checks = extractList(query, "restrictions", EParserModifier::EscapeQuotes);
        out.reserve(checks.size());

        for (const auto check : checks)
        {
            out.emplace_back(check);
        }
    }
    catch (const std::runtime_error& e)
    {
        if (!equalsIgnoreCase(e.what(), "Invalid query, missing 'restrictions' keyword"))
        {
            throw e;
        }
    }

    return out;
}

} // Anonymous namespace

QUERY_PARSER_CLASS_IMPL(Schema, c_query_prefix)
{
    QUERY_OBJECT(obj, Schema);

    cleanupQuery(query, c_query_prefix);

    obj.name = extractIdentifier(query, "name");
    obj.inherits = extractInherits(query);
    obj.fields = extractFields(query);
    obj.restrictions = extractRestrictions(query);

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
