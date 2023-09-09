#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

constexpr auto c_query_prefix{ "insert into" };

} // Anonymous namespace

QUERY_PARSER_CLASS_IMPL(Insert, c_query_prefix)
{
    QUERY_OBJECT(obj, Insert);

    cleanupQuery(query, c_query_prefix);

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation 
