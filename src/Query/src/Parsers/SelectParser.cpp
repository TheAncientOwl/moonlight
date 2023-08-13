#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

// TODO: implement Select regex...
PARSER_REGEX(Select, "");

PARSER_LOGICS(Select)
{
    QUERY_OBJECT(obj, Select);

    // TODO: implement Select parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
