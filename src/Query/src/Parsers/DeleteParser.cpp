#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// TODO: implement matcher...
PARSER_MATCHER(Delete)
{
    return false;
}

PARSER_LOGICS(Delete)
{
    QUERY_OBJECT(obj, Delete);

    // TODO: implement Delete parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
