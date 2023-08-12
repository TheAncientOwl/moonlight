#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

PARSER_REGEX(StructureRename, regex(
    "structure",
    ".[ ]*rename",
    variant(
        functionArgs("structure"),
        ".[ ]*old_name", functionArgs(IDENTIFIER),
        ".[ ]*new_name", functionArgs(IDENTIFIER),
        VARIANT_OR,
        functionArgs("field"),
        ".[ ]*old_name", functionArgs(IDENTIFIER "\\." IDENTIFIER),
        ".[ ]*new_name", functionArgs(IDENTIFIER "\\." IDENTIFIER)
    ),
    ";"
));

PARSER_LOGICS(StructureRename)
{
    QUERY_OBJECT(obj, StructureRename);

    // TODO: implement StructureRename parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
