#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

PARSER_REGEX(StructureMigrate, regex(
    "structure",
    ".[ ]*migrate", functionArgs(IDENTIFIER),
    ".[ ]*to", functionArgs(IDENTIFIER),
    optional(".[ ]*migrate_dictionary", functionArgs(listOf(IDENTIFIER "[ ]*=>[ ]*" IDENTIFIER))),
    ";"
));

PARSER_LOGICS(StructureMigrate)
{
    QUERY_OBJECT(obj, StructureMigrate);

    // TODO: implement StructureMigrate parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
