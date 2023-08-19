#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

} // Anonymous namespace

// TODO: implement matcher...
QUERY_COULD_MATCH(Select)
{
    return false;
}

QUERY_PARSER(Select)
{
    QUERY_OBJECT(obj, Select);

    // TODO: implement Select parser...

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
