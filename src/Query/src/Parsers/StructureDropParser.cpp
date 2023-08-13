#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

// TODO: implement Schema regex...
PARSER_REGEX(StructureDrop, "");

PARSER_LOGICS(StructureDrop)
{
    QUERY_OBJECT(obj, StructureDrop);

    // TODO: implement StructureDrop parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
