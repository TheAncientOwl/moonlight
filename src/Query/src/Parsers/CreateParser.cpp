#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// ?Regex: https://regex101.com/r/g0dIlM/1
PARSER_REGEX(Create,
    R"(create\s*structure\s*\{)"
    R"(\s*name:\s*\w+\s*;)"
    R"(\s*type:\s*(?:table|document)\s*;)"
    R"(\s*based_on:\s*\w+\s*;)"
    R"(\s*volatile:\s*(?:true|false)\s*;)"
    R"(\s*\})");

PARSER_LOGICS(Create)
{
    QUERY_OBJECT(obj, Create);

    // TODO: implement Create parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
