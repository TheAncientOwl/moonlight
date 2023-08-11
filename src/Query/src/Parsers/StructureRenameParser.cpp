#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

PARSER_REGEX(StructureRename,
    RegexBuilder{}
    .add("Structure")
    .add(".[ ]*rename")

    .beginCase()
    .paranthesis("structure")
    .add(".[ ]*old_name").paranthesis(IDENTIFIER)
    .add(".[ ]*new_name").paranthesis(IDENTIFIER)

    .orCase()
    .paranthesis("field")
    .add(".[ ]*old_name").paranthesis(IDENTIFIER "\\." IDENTIFIER)
    .add(".[ ]*new_name").paranthesis(IDENTIFIER "\\." IDENTIFIER)

    .endCase()
    .add(";").build()
);

PARSER_LOGICS(StructureRename)
{
    QUERY_OBJECT(obj, StructureRename);

    // TODO: implement StructureRename parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
