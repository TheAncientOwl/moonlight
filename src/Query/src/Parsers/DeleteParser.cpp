#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

} // Anonymous namespace

QUERY_COULD_MATCH(Delete)
{
    return startsWithIgnoreCase(query, "delete");
}

QUERY_PARSER(Delete)
{
    QUERY_OBJECT(obj, Delete);

    cleanupQuery(query, "delete");

    obj.from = extractIdentifier(query, "from");
    obj.where = QueryData::Helpers::parseWhereClause(extractValue(query, "where", EParserModifier::EscapeQuotes));

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
