#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

PARSER_REGEX(Database, regex(
    "database",
    variant(
        ".[ ]*create", functionArgs(IDENTIFIER),
        VARIANT_OR,
        ".[ ]*drop", functionArgs(IDENTIFIER),
        VARIANT_OR,
        ".[ ]*backup", functionArgs(IDENTIFIER),
        ".[ ]*to_disk", functionArgs(PATH_IDENTIFIER),
        optional(".[ ]*with_differential", functionArgs(BOOLEAN))
    ),
    ";"
));
//     RegexBuilder{}
//     .add("Database")

//     .beginCase()
//     .add(".[ ]*create").paranthesis(IDENTIFIER)

//     .orCase()
//     .add(".[ ]*drop").paranthesis(IDENTIFIER)

//     .orCase()
//     .add(".[ ]*backup").paranthesis(IDENTIFIER)
//     .add(".[ ]*to_disk").paranthesis(PATH_IDENTIFIER)
//     .beginOptional()
//     .add(".[ ]*with_differential").paranthesis("(true|false)")
//     .endOptional()

//     .endCase()
//     .add(";").build()
// );

PARSER_LOGICS(Database)
{
    QUERY_OBJECT(obj, Database);

    // TODO: implement Database parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
