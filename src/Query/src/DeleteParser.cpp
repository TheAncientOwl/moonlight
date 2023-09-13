#include "common/QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

constexpr auto c_query_prefix{ "delete" };

} // Anonymous namespace


QUERY_PARSER_CLASS_IMPL(Delete, c_query_prefix)
{
    QUERY_OBJECT(obj, Delete);

    cleanupQuery(query, c_query_prefix);

    obj.from = extractIdentifier(query, "from");
    obj.where = ParsedQuery::Helpers::parseWhereClause(extractValue(query, "where", EParserModifier::EscapeQuotes));

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
