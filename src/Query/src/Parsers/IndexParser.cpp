#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

} // Anonymous namespace

QUERY_COULD_MATCH(Index)
{
    return startsWithIgnoreCase(query, "index");
}

QUERY_PARSER(Index)
{
    QUERY_OBJECT(obj, Index);

    cleanupQuery(query, "index");

    obj.on_structure = extractIdentifier(query, "on");
    obj.name = extractIdentifier(query, "name");
    obj.on_fields = extractIdentifiersList(query, "fields");
    obj.unique = extractBoolean(query, "unique");

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
