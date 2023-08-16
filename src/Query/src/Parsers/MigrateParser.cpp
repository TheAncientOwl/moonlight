#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// TODO: implement matcher...
PARSER_MATCHER(Migrate)
{
    return false;
}

PARSER_LOGICS(Migrate)
{
    QUERY_OBJECT(obj, Migrate);

    // TODO: implement Migrate parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
