#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

constexpr auto c_query_prefix{ "update" };

QueryData::SetClause extractSetClause(std::string_view& query)
{
    QueryData::SetClause out{};

    const auto set_seq = extractValue(query, "set", EParserModifier::EscapeQuotes);

    out.data = set_seq;

    return out;
}

} // Anonymous namespace

QUERY_PARSER_CLASS_IMPL(Update, c_query_prefix)
{
    QUERY_OBJECT(obj, Update);

    cleanupQuery(query, c_query_prefix);

    obj.name = extractIdentifier(query, "structure");
    obj.set = extractSetClause(query);
    obj.where = QueryData::Helpers::parseWhereClause(extractValue(query, "where", EParserModifier::EscapeQuotes));

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
