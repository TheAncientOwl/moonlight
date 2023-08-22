#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

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

} // Anonymous namespace

QUERY_COULD_MATCH(Schema)
{
    return startsWithIgnoreCase(query, "schema");
}

QUERY_PARSER(Schema)
{
    QUERY_OBJECT(obj, Schema);

    cleanupQuery(query, "schema");

    obj.name = extractIdentifier(query, "name");
    obj.inherits = extractInherits(query);

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
