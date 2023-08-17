#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

namespace {

} // Anonymous namespace

QUERY_COULD_MATCH(Drop)
{
    return Utils::startsWithIgnoreCase(query, "drop");
}

QUERY_PARSER(Drop)
{
    QUERY_OBJECT(obj, Drop);

    // TODO: implement Drop parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
