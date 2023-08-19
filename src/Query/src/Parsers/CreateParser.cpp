#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

/**
 * @brief bring query to format: "content"
 *
 * @param query string representation of query in format: "create structure { content }"
 */
void cleanup(std::string_view& query)
{
    query.remove_prefix("create"sv.length());
    ltrim(query);

    if (!startsWithIgnoreCase(query, "structure"))
    {
        throw std::runtime_error("Missing structure keyword in query definition @ '"s + std::string(query) + "'"s);
    }
    query.remove_prefix("structure"sv.length());
    ltrim(query);

    if (query.front() != '{')
    {
        throw std::runtime_error("Missing '{' symbol");
    }
    query.remove_prefix(1);

    if (query.back() != '}')
    {
        throw std::runtime_error("Missing '}' symbol");
    }
    query.remove_suffix(1);

    trim(query);
}

Primitives::EStructureType extractType(std::string_view& query)
{
    const auto type = extractValue(query, "type");

    return Primitives::StructureType::to_literal(std::string(type));
}

} // Anonymous namespace

QUERY_COULD_MATCH(Create)
{
    return startsWithIgnoreCase(query, "create");
}

QUERY_PARSER(Create)
{
    QUERY_OBJECT(obj, Create);

    cleanup(query);

    obj.name = extractIdentifier(query, "name");
    obj.type = extractType(query);
    obj.schema = extractIdentifier(query, "based_on");
    obj.is_volatile = extractBoolean(query, "volatile");

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
