#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// ?Regex: https://regex101.com/r/5sJBmN/1
PARSER_REGEX(Schema,
    R"(schema\s*\w+\s*\{(?:\s*inherits:\s*\[\s*(?:\w+(?:,|\s)+)+\]\s*;)?\s*fields:\s*\[\s*(?:\w+\s*is\s*!?(?:Boolean|DateTime|String\[\d+\]|(?:Int|Float)\[(?:8|16|32|64)\]|Reference)\s*@(?:default|of)\(.+\)(?:,|\s)+)+\]\s*;(?:\s*checks:\s*\[\s*(?:[^\]]*(?:,|\s)+)+\]\s*;)?(?:\s*unique:\s*\[\s*(?:\w+(?:,|\s)+)+\]\s*;)?\s*\})"
);

PARSER_LOGICS(Schema)
{
    QUERY_OBJECT(obj, Schema);

    // TODO: implement Schema parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
