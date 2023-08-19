#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

} // Anonymous namespace

QUERY_COULD_MATCH(Drop)
{
    return startsWithIgnoreCase(query, "drop");
}

QUERY_PARSER(Drop)
{
    QUERY_OBJECT(obj, Drop);

    cleanupQuery(query, "drop");

    obj.name = extractIdentifier(query, "structure");
    obj.cascade = extractBoolean(query, "cascade");

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
