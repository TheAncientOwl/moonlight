#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

// TODO: implement Schema regex...
PARSER_REGEX(Migrate, "");

PARSER_LOGICS(Migrate)
{
    QUERY_OBJECT(obj, Migrate);

    // TODO: implement Migrate parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
