#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// ?Regex: https://regex101.com/r/Vk7rKT/1
PARSER_REGEX(Index,
    R"(index\s*\{)"
    R"(\s*on:\s*\w+\s*;)"
    R"(\s*name:\s*\w+\s*;)"
    R"(\s*fields:\s*\[\s*(?:\w+(?:,|\s)+)+\]\s*;)"
    R"(\s*unique:\s*(?:true|false)\s*;)"
    R"(\s*\})"
);

PARSER_LOGICS(Index)
{
    QUERY_OBJECT(obj, Index);

    // TODO: implement Index parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
