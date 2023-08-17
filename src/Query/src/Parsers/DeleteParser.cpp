#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// TODO: implement matcher...
QUERY_COULD_MATCH(Delete)
{
    return false;
}

QUERY_PARSER(Delete)
{
    QUERY_OBJECT(obj, Delete);

    // TODO: implement Delete parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
