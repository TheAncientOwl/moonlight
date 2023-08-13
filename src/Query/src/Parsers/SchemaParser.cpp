#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

// TODO: implement Schema regex...
PARSER_REGEX(Schema, "");

PARSER_LOGICS(Schema)
{
    QUERY_OBJECT(obj, Schema);

    // TODO: implement Schema parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
