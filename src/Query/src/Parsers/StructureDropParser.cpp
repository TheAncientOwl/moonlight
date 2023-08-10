#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

PARSER_MATCHER(StructureDrop,
    "Structure[ ]*"
    ".[ ]*drop[ ]*\\([ ]*[a-zA-Z0-9]+[ ]*\\)[ ]*"
    ".[ ]*cascade[ ]*\\([ ]*(true|false)[ ]*\\)[ ]*;"
);

PARSER_LOGICS(StructureDrop)
{
    QUERY_OBJECT(obj, StructureDrop);

    // TODO: implement StructureDrop parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
