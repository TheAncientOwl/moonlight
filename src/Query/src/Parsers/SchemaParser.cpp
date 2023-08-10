#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

// TODO: implement Schema regex...
PARSER_MATCHER(Schema, "");

PARSER_LOGICS(Schema)
{
    QUERY_OBJECT(obj, Schema);

    // TODO: implement Schema parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
