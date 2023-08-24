#include "QueryParser.hpp"

#include "Utils/src/Utils.hpp"

#include <array>
#include <memory>

namespace Moonlight::QueryParser {

using namespace Utils;

QueryObject parseQuery(std::string_view query)
{
    PLAIN_QUERY_OBJECT;

    trim(query);

    using namespace Implementation;
    static const HierarchyMap<IQueryParser, QUERY_PARSERS> s_parsers{};

    const auto parser_ptr = s_parsers.findIf([query](const auto& parser) -> bool {
        return startsWithIgnoreCase(query, parser.queryPrefix());
        });

    if (!parser_ptr)
    {
        throw std::runtime_error("Invalid query syntax.");
    }

    query_obj = parser_ptr->parse(query);

    RETURN_QUERY_OBJECT;
}

namespace Implementation {

IQueryParser::~IQueryParser() {}

} // namespace Implementation

} // namespace Moonlight::QueryParser
