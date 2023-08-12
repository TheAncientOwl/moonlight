#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

PARSER_REGEX(Database, regex(
    "database",
    variant(
        ".[ ]*create", functionArgs(IDENTIFIER),
        VARIANT_OR,
        ".[ ]*drop", functionArgs(IDENTIFIER),
        VARIANT_OR,
        ".[ ]*backup", functionArgs(IDENTIFIER),
        ".[ ]*to_disk", functionArgs(PATH_IDENTIFIER),
        optional(".[ ]*with_differential", functionArgs(BOOLEAN))
    ),
    ";"
));

PARSER_LOGICS(Database)
{
    QUERY_OBJECT(obj, Database);

    // TODO: implement Database parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
