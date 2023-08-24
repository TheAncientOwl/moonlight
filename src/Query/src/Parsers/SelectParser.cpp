#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

constexpr auto c_query_prefix = "select";

} // Anonymous namespace

QUERY_PARSER_CLASS_IMPL(Select, c_query_prefix)
{
    QUERY_OBJECT(obj, Select);

    cleanupQuery(query, c_query_prefix);

    // TODO: implement Select parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
