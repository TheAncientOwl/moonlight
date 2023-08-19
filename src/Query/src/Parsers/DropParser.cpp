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

} // Anonymous namespace

QUERY_COULD_MATCH(Drop)
{
    return startsWithIgnoreCase(query, "drop");
}

QUERY_PARSER(Drop)
{
    QUERY_OBJECT(obj, Drop);

    cleanup(query);

    obj.name = extractIdentifier(query, "structure");
    obj.cascade = extractBoolean(query, "cascade");

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
