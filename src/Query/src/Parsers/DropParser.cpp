#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// TODO: implement matcher...
PARSER_MATCHER(Drop)
{
    return false;
}

PARSER_LOGICS(Drop)
{
    QUERY_OBJECT(obj, Drop);

    // TODO: implement Drop parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
