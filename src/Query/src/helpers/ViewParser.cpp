#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

constexpr auto c_query_prefix{ "view" };

} // Anonymous namespace

QUERY_PARSER_CLASS_IMPL(View, c_query_prefix)
{
    QUERY_OBJECT(obj, View);

    cleanupQuery(query, c_query_prefix);

    // TODO: implement View parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
