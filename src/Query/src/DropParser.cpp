#include "common/QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

constexpr auto c_query_prefix{ "drop" };

} // Anonymous namespace

QUERY_PARSER_CLASS_IMPL(Drop, c_query_prefix)
{
    QUERY_OBJECT(obj, Drop);

    cleanupQuery(query, c_query_prefix);

    obj.name = extractIdentifier(query, "structure");
    obj.cascade = extractBoolean(query, "cascade");

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
