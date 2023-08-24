#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

constexpr auto c_query_prefix{ "update" };

} // Anonymous namespace

QUERY_PARSER_CLASS_IMPL(Update, c_query_prefix)
{
    QUERY_OBJECT(obj, Update);

    cleanupQuery(query, c_query_prefix);

    // TODO: implement Update parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
