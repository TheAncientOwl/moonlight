#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

// TODO: implement Schema regex...
PARSER_REGEX(StructureRename, "");

PARSER_LOGICS(StructureRename)
{
    QUERY_OBJECT(obj, StructureRename);

    // TODO: implement StructureRename parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
