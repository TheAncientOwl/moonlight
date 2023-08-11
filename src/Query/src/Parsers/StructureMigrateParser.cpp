#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

PARSER_REGEX(StructureMigrate,
    RegexBuilder{}
    .add("Structure")
    .add(".[ ]*migrate").paranthesis(IDENTIFIER)
    .add(".[ ]*to").paranthesis(IDENTIFIER)

    .beginOptional()
    .add(".[ ]*migrate_dictionary")
    .paranthesis(
        RegexBuilder{}
        .add("(")
        .add(IDENTIFIER "[ ]*=>[ ]*" IDENTIFIER)
        .add("(,| )*")
        .add(")+")
        .build(),
        "\\{", "\\}"
    )
    .endOptional()

    .add(";").build()
);

PARSER_LOGICS(StructureMigrate)
{
    QUERY_OBJECT(obj, StructureMigrate);

    // TODO: implement StructureMigrate parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
