#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

// TODO: implement Schema regex...
PARSER_REGEX(Drop, "");

PARSER_LOGICS(Drop)
{
    QUERY_OBJECT(obj, Drop);

    // TODO: implement Drop parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
