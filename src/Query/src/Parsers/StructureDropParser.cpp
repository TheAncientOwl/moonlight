#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

PARSER_REGEX(StructureDrop,
    RegexBuilder{}
    .add("structure")
    .add(".[ ]*drop").paranthesis(IDENTIFIER)
    .add(".[ ]*cascade").paranthesis("(true|false)")
    .add(";").build()
);

PARSER_LOGICS(StructureDrop)
{
    QUERY_OBJECT(obj, StructureDrop);

    // TODO: implement StructureDrop parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
