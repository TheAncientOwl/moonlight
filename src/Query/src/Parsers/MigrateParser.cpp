#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// TODO: implement matcher...
QUERY_COULD_MATCH(Migrate)
{
    return false;
}

QUERY_PARSER(Migrate)
{
    QUERY_OBJECT(obj, Migrate);

    // TODO: implement Migrate parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
