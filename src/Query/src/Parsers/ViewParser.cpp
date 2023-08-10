#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

// TODO: implement View regex...
PARSER_MATCHER(View, "");

PARSER_LOGICS(View)
{
    QUERY_OBJECT(obj, View);

    // TODO: implement View parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
