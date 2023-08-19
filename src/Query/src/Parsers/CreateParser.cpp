#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

} // Anonymous namespace

// TODO: implement matcher...
QUERY_COULD_MATCH(Create)
{
    return false;
}

QUERY_PARSER(Create)
{
    QUERY_OBJECT(obj, Create);

    // TODO: implement Create parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
