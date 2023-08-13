#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// ?Regex: https://regex101.com/r/PL4uPR/1
PARSER_REGEX(Database,
    R"(database\s*(?:)"
    R"((?:(?:create|drop)\s*\{)"
    R"(\s*name:\s*\w+\s*;)|)"
    R"((?:backup\s*\{)"
    R"(\s*name:\s*\w+\s*;)"
    R"(\s*to_disk:\s*(?:".*")\s*;)"
    R"(\s*with_differential:\s*(?:true|false)\s*;))"
    R"()\s*\})"
);

PARSER_LOGICS(Database)
{
    QUERY_OBJECT(obj, Database);

    // TODO: implement Database parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
