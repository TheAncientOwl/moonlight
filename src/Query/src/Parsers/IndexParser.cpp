#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// TODO: implement matcher...
QUERY_COULD_MATCH(Index)
{
    return false;
}

QUERY_PARSER(Index)
{
    QUERY_OBJECT(obj, Index);

    // TODO: implement Index parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
