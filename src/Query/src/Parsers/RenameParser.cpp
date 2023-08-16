#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// TODO: implement matcher...
PARSER_MATCHER(Rename)
{
    return false;
};

PARSER_LOGICS(Rename)
{
    QUERY_OBJECT(obj, Rename);

    // TODO: implement Rename parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
