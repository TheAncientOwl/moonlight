#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// ?Regex: https://regex101.com/r/kOwmeb/1
PARSER_REGEX(Drop, R"(drop\s*\{\s*structure:\s*\w+\s*;\s*cascade:\s*(true|false)\s*;\s*\})");

PARSER_LOGICS(Drop)
{
    QUERY_OBJECT(obj, Drop);

    // TODO: implement Drop parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
