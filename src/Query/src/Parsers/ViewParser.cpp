#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// TODO: implement matcher...
QUERY_COULD_MATCH(View)
{
    return false;
}

QUERY_PARSER(View)
{
    QUERY_OBJECT(obj, View);

    // TODO: implement View parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
