#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

PARSER_REGEX(Index, regex(
    "index",
    ".[ ]*create_on", functionArgs(IDENTIFIER),
    ".[ ]*named", functionArgs(IDENTIFIER),
    ".[ ]*on_fields", functionArgs(listOf(IDENTIFIER)),
    optional(".[ ]*unique", functionArgs(BOOLEAN)),
    ";"
));

PARSER_LOGICS(Index)
{
    QUERY_OBJECT(obj, Index);

    // TODO: implement Index parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
