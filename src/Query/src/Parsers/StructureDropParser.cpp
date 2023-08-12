#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

PARSER_REGEX(StructureDrop, regex(
    "structure",
    ".[ ]*drop", functionArgs(IDENTIFIER),
    ".[ ]*cascade", functionArgs(BOOLEAN),
    ";"
));

PARSER_LOGICS(StructureDrop)
{
    QUERY_OBJECT(obj, StructureDrop);

    // TODO: implement StructureDrop parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
