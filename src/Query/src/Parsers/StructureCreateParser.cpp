#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

PARSER_REGEX(StructureCreate, regex(
    "structure",
    ".[ ]*create", functionArgs("(table|document)"),
    ".[ ]*based_on", functionArgs(IDENTIFIER),
    ".[ ]*named", functionArgs(IDENTIFIER),
    optional(".[ ]*volatile", functionArgs(BOOLEAN)),
    ";"
));

PARSER_LOGICS(StructureCreate)
{
    QUERY_OBJECT(obj, StructureCreate);

    // TODO: implement StructureCreate parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
