#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

/**
 * @brief bring query to format: "content"
 *
 * @param query string representation of query in format: "drop { content }"
 */
void cleanup(std::string_view& query)
{
    query.remove_prefix("drop"sv.length());
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

/**
 * @brief extract value and cleanup query
 *
 * @param query string representation of query in format "structure: StructureName; [query...]"
 */
std::string_view extractStructureName(std::string_view& query)
{
    const auto name = extractValue(query, "structure");

    if (!isValidIdentifier(name))
    {
        throw std::runtime_error("Invalid identifier name @ '"s + std::string(name) + "'"s);
    }

    return name;
}

/**
 * @brief extract boolean and cleanup query
 *
 * @param query string representation of query in format "cascade: true|false; [query...]"
 */
bool extractCascade(std::string_view& query)
{
    const auto boolean = extractValue(query, "cascade");

    if (equalsIgnoreCase(boolean, "true"))
    {
        return true;
    }
    else if (equalsIgnoreCase(boolean, "false"))
    {
        return false;
    }
    else
    {
        throw std::runtime_error("Invalid boolean value '"s + std::string(boolean) + "'"s);
    }
}

} // Anonymous namespace

QUERY_COULD_MATCH(Drop)
{
    return startsWithIgnoreCase(query, "drop");
}

QUERY_PARSER(Drop)
{
    QUERY_OBJECT(obj, Drop);

    cleanup(query);

    obj.name = extractStructureName(query);
    obj.cascade = extractCascade(query);

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
