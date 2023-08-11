#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

// TODO: implement StructureUpdate regex...
PARSER_REGEX(StructureUpdate, "");

PARSER_LOGICS(StructureUpdate)
{
    QUERY_OBJECT(obj, StructureUpdate);

    // TODO: implement StructureUpdate parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
