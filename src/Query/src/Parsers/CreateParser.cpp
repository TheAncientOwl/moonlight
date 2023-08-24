#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

Primitives::EStructureType extractType(std::string_view& query)
{
    const auto type = extractValue(query, "type");

    return Primitives::StructureType::to_literal(std::string(type));
}

} // Anonymous namespace

QUERY_PARSER_CLASS_IMPL(Create, "create structure")
{
    QUERY_OBJECT(obj, Create);

    cleanupQuery(query, "create structure");

    obj.name = extractIdentifier(query, "name");
    obj.type = extractType(query);
    obj.schema = extractIdentifier(query, "based_on");
    obj.is_volatile = extractBoolean(query, "volatile");

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
