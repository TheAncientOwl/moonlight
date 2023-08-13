#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

// TODO: implement Structure regex...
PARSER_REGEX(Create, "");

PARSER_LOGICS(Create)
{
    QUERY_OBJECT(obj, Create);

    // TODO: implement Create parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
