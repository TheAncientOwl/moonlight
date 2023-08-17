#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// TODO: implement matcher...
QUERY_COULD_MATCH(Drop)
{
    return false;
}

QUERY_PARSER(Drop)
{
    QUERY_OBJECT(obj, Drop);

    // TODO: implement Drop parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
