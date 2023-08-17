#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// TODO: implement matcher...
QUERY_COULD_MATCH(Update)
{
    return false;
}

QUERY_PARSER(Update)
{
    QUERY_OBJECT(obj, Update);

    // TODO: implement Update parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
