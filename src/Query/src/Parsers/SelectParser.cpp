#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// TODO: implement matcher...
PARSER_MATCHER(Select)
{
    return false;
}

PARSER_LOGICS(Select)
{
    QUERY_OBJECT(obj, Select);

    // TODO: implement Select parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
