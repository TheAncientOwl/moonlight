#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

} // Anonymous namespace

QUERY_PARSER_CLASS_IMPL(Drop, "drop")
{
    QUERY_OBJECT(obj, Drop);

    cleanupQuery(query, "drop");

    obj.name = extractIdentifier(query, "structure");
    obj.cascade = extractBoolean(query, "cascade");

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
