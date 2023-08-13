#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

// TODO: implement Schema regex...
PARSER_REGEX(Rename, "");

PARSER_LOGICS(Rename)
{
    QUERY_OBJECT(obj, Rename);

    // TODO: implement Rename parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
