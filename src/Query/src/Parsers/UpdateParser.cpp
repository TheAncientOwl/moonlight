#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// TODO: implement Update regex...
PARSER_REGEX(Update, "");

PARSER_LOGICS(Update)
{
    QUERY_OBJECT(obj, Update);

    // TODO: implement Update parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
