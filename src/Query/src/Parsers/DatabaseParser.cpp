#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

} // Anonymous namespace

// TODO: implement matcher...
QUERY_COULD_MATCH(Database)
{
    return false;
}

QUERY_PARSER(Database)
{
    QUERY_OBJECT(obj, Database);

    // TODO: implement Database parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
