#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// TODO: implement matcher...
QUERY_COULD_MATCH(Schema)
{
    return false;
}

QUERY_PARSER(Schema)
{
    QUERY_OBJECT(obj, Schema);

    // TODO: implement Schema parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
