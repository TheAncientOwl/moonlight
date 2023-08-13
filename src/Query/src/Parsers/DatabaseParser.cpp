#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// TODO: implement Database regex...
PARSER_REGEX(Database, "");

PARSER_LOGICS(Database)
{
    QUERY_OBJECT(obj, Database);

    // TODO: implement Database parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
