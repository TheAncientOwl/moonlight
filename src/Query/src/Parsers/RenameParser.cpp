#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// TODO: implement matcher...
QUERY_COULD_MATCH(Rename)
{
    return false;
};

QUERY_PARSER(Rename)
{
    QUERY_OBJECT(obj, Rename);

    // TODO: implement Rename parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
