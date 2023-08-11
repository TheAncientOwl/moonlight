#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

namespace {

} // Anonymous namespace

// TODO: implement StructureSelect regex...
PARSER_REGEX(StructureSelect, "");

PARSER_LOGICS(StructureSelect)
{
    QUERY_OBJECT(obj, StructureSelect);

    // TODO: implement StructureSelect parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Helpers
