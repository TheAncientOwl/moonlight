#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

constexpr auto c_query_prefix{ "create structure" };

Primitives::EStructureType extractType(std::string_view& query)
{
    const auto type_seq{ extractValue(query, "type") };

    return Primitives::StructureType::to_literal(std::string(type_seq));
}

} // Anonymous namespace

QUERY_PARSER_CLASS_IMPL(Create, c_query_prefix)
{
    QUERY_OBJECT(obj, Create);

    cleanupQuery(query, c_query_prefix);

    obj.name = extractIdentifier(query, "name");
    obj.type = extractType(query);
    obj.schema = extractIdentifier(query, "based_on");
    obj.is_volatile = extractBoolean(query, "volatile");

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
