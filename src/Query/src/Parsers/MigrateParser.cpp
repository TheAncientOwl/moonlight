#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// ?Regex: https://regex101.com/r/1WeJpP/1
PARSER_REGEX(Migrate,
    R"(migrate\s*\{)"
    R"(\s*structure:\s*\w+\s*;)"
    R"(\s*to:\s*\w+\s*;)"
    R"((?:\s*mappings:\s*\[\s*(?:\w+\s*=>\s*\w+(?:,|\s)+)+\]\s*;)?)"
    R"(\s*\})"
);

PARSER_LOGICS(Migrate)
{
    QUERY_OBJECT(obj, Migrate);

    // TODO: implement Migrate parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
