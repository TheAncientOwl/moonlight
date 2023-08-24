#include "QueryParser.hpp"

#include "Utils/src/Utils.hpp"

#include <array>
#include <memory>

namespace Moonlight::QueryParser {

using namespace Utils;
using namespace Implementation;

QueryObject parseQuery(std::string_view query)
{
    static const HierarchyMap<IQueryParser, QUERY_PARSERS> s_parsers{};

    trim(query);
    const auto parser_ptr = s_parsers.findIf([query](const auto& parser) -> bool {
        return startsWithIgnoreCase(query, parser.queryPrefix());
        });

    if (!parser_ptr)
    {
        throw std::runtime_error("Invalid query syntax.");
    }

    return parser_ptr->parse(query);
}

namespace Implementation {

IQueryParser::~IQueryParser() {}

} // namespace Implementation

} // namespace Moonlight::QueryParser
