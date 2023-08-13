#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// ?Regex: https://regex101.com/r/8DhhKL/1
PARSER_REGEX(Rename,
    R"(rename\s*(?:)"
    R"((?:structure\s*\{\s*old_name:\s*\w+\s*;\s*new_name:\s*\w+\s*;)|)"
    R"((?:field\s*\{\s*old_name:\s*\w+\.\w+\s*;\s*new_name:\s*\w+\.\w+\s*;))"
    R"()\s*})"
);

PARSER_LOGICS(Rename)
{
    QUERY_OBJECT(obj, Rename);

    // TODO: implement Rename parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
