#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

// TODO: implement Schema regex...
PARSER_REGEX(StructureMigrate, "");

PARSER_LOGICS(StructureMigrate)
{
    QUERY_OBJECT(obj, StructureMigrate);

    // TODO: implement StructureMigrate parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
