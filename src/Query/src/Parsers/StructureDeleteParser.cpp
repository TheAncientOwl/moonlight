#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

// TODO: implement StructureDelete regex...
PARSER_MATCHER(StructureDelete, "");

PARSER_LOGICS(StructureDelete)
{
    QUERY_OBJECT(obj, StructureDelete);

    // TODO: implement StructureDelete parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
