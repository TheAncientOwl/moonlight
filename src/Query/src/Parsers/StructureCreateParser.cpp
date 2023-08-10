#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

// TODO: implement StructureCreate regex...
PARSER_MATCHER(StructureCreate, "");

PARSER_LOGICS(StructureCreate)
{
    QUERY_OBJECT(obj, StructureCreate);

    // TODO: implement StructureCreate parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
