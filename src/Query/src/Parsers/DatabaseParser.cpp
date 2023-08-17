#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// TODO: implement matcher...
QUERY_COULD_MATCH(Database)
{
    return false;
}

QUERY_PARSER(Database)
{
    QUERY_OBJECT(obj, Database);

    // TODO: implement Database parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
