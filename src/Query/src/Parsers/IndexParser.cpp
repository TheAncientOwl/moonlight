#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

PARSER_REGEX(Index,
    RegexBuilder{}
    .add("Index")
    .add(".[ ]*create_on").paranthesis(IDENTIFIER)
    .add(".[ ]*named").paranthesis(IDENTIFIER)
    .add(".[ ]*on_fields").paranthesis(
        RegexBuilder{}
        .add("(")
        .add(IDENTIFIER)
        .add("(,| )*")
        .add(")+")
        .build()
    )

    .beginOptional()
    .add(".[ ]*unique").paranthesis("(true|false)")
    .endOptional()

    .add(";").build()
);

PARSER_LOGICS(Index)
{
    QUERY_OBJECT(obj, Index);

    // TODO: implement Index parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
