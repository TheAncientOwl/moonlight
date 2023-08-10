#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

PARSER_MATCHER(StructureCreate,
    "Structure[ ]*"
    ".[ ]*create[ ]*\\([ ]*(table|document)[ ]*\\)[ ]*"
    ".[ ]*based_on[ ]*\\([ ]*[a-zA-Z0-9_]+[ ]*\\)[ ]*"
    ".[ ]*named[ ]*\\([ ]*[a-zA-Z0-9_]+[ ]*\\)[ ]*"
    ".[ ]*volatile[ ]*\\([ ]*(true|false)[ ]*\\)[ ]*;"
);

PARSER_LOGICS(StructureCreate)
{
    QUERY_OBJECT(obj, StructureCreate);

    // TODO: implement StructureCreate parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
