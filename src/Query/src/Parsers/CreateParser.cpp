#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// TODO: implement matcher...
QUERY_COULD_MATCH(Create)
{
    return false;
}

QUERY_PARSER(Create)
{
    QUERY_OBJECT(obj, Create);

    // TODO: implement Create parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
