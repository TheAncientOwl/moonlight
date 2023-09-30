#include "common/QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::Parser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

constexpr auto c_query_prefix{ "index" };

} // Anonymous namespace

QUERY_PARSER_CLASS_IMPL(Index, c_query_prefix)
{
    QUERY_OBJECT(obj, Index);

    cleanupQuery(query, c_query_prefix);

    obj.on_structure = extractIdentifier(query, "on");
    obj.name = extractIdentifier(query, "name");
    obj.on_fields = extractIdentifiersList(query, "fields");
    obj.unique = extractBoolean(query, "unique");

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::Parser::Implementation
