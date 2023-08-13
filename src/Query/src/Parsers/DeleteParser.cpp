#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

// TODO: implement Delete regex...
PARSER_REGEX(Delete, "");

PARSER_LOGICS(Delete)
{
    QUERY_OBJECT(obj, Delete);

    // TODO: implement Delete parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
