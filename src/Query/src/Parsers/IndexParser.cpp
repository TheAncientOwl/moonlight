#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// TODO: implement Index regex...
PARSER_REGEX(Index, "");

PARSER_LOGICS(Index)
{
    QUERY_OBJECT(obj, Index);

    // TODO: implement Index parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
