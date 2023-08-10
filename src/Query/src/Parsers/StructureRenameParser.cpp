#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

PARSER_MATCHER(StructureRename,
    "Structure[ ]*"
    "(("
    ".[ ]*rename[ ]*\\([ ]*structure[ ]*\\)[ ]*"
    ".[ ]*old_name[ ]*\\([ ]*[a-zA-Z0-9_]+[ ]*\\)[ ]*"
    ".[ ]*new_name[ ]*\\([ ]*[a-zA-Z0-9_]+[ ]*\\)[ ]*;"
    ")|("
    ".[ ]*rename[ ]*\\([ ]*field[ ]*\\)[ ]*"
    ".[ ]*old_name[ ]*\\([ ]*[a-zA-Z0-9_]+\\.[a-zA-Z0-9_]+[ ]*\\)[ ]*"
    ".[ ]*new_name[ ]*\\([ ]*[a-zA-Z0-9_]+\\.[a-zA-Z0-9_]+[ ]*\\)[ ]*;"
    "))"
);

PARSER_LOGICS(StructureRename)
{
    QUERY_OBJECT(obj, StructureRename);

    // TODO: implement StructureRename parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
