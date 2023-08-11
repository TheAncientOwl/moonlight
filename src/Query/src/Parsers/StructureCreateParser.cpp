#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

PARSER_REGEX(StructureCreate,
    RegexBuilder{}
    .add("Structure")
    .add(".[ ]*create").paranthesis("(table|document)")
    .add(".[ ]*based_on").paranthesis(IDENTIFIER)
    .add(".[ ]*named").paranthesis(IDENTIFIER)
    .add(".[ ]*volatile").paranthesis("(true|false)")
    .add(";").build()
);

PARSER_LOGICS(StructureCreate)
{
    QUERY_OBJECT(obj, StructureCreate);

    // TODO: implement StructureCreate parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
