#include "../QueryParser.hpp"

#include "SchemaFieldParsers.hpp"

#include "Utils/src/Utils.hpp"

#include <array>

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

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
    static const std::array<std::unique_ptr<FieldParsers::IFieldParser>, 6> s_parsers = {
        std::make_unique<FieldParsers::StringFieldParser>(),
        std::make_unique<FieldParsers::DateTimeFieldParser>(),
        std::make_unique<FieldParsers::BooleanFieldParser>(),
        std::make_unique<FieldParsers::IntegerFieldParser>(),
        std::make_unique<FieldParsers::DecimalFieldParser>(),
        std::make_unique<FieldParsers::ReferenceFieldParser>()
    };

    const auto parser = std::find_if(s_parsers.begin(), s_parsers.end(),
        [field](const auto& field_parser) {
            return field_parser->match(std::string(field));
        }
    );

    if (parser == std::cend(s_parsers))
    {
        throw std::runtime_error("Invalid field declaration"s + std::string(field));
    }

    return parser->get()->parse();
}

std::vector<QueryData::Field> extractFields(std::string_view& query)
{

    const auto fields = extractList(query, "fields", EParserModifier::EscapeQuotes);

    std::vector<QueryData::Field> out{};
    out.reserve(fields.size());

    for (const auto field : fields)
    {
        out.emplace_back(parseField(field));
    }

    return out;
}

std::vector<std::string> extractChecks(std::string_view& query)
{
    std::vector<std::string> out{};

    try
    {
        const auto checks = extractList(query, "checks", EParserModifier::EscapeQuotes);

        out.reserve(checks.size());

        for (const auto check : checks)
        {
            out.emplace_back(check);
        }
    }
    catch (const std::runtime_error& e)
    {
        if (!equalsIgnoreCase(e.what(), "Invalid query, missing 'checks' keyword"))
        {
            throw e;
        }
    }

    return out;
}

std::vector<std::string> extractUnique(std::string_view& query)
{
    std::vector<std::string> out{};

    try
    {
        out = extractIdentifiersList(query, "unique");
    }
    catch (const std::runtime_error& e)
    {
        if (!equalsIgnoreCase(e.what(), "Invalid query, missing 'unique' keyword"))
        {
            throw e;
        }
    }

    return out;
}

} // Anonymous namespace

QUERY_PARSER_CLASS_IMPL(Schema, "schema")
{
    QUERY_OBJECT(obj, Schema);

    cleanupQuery(query, "schema");

    obj.name = extractIdentifier(query, "name");
    obj.inherits = extractInherits(query);
    obj.fields = extractFields(query);
    obj.checks = extractChecks(query);
    obj.unique = extractUnique(query);

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
