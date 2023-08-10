#include "QueryParser.hpp"

#include <array>
#include <stdexcept>

namespace Moonlight::QueryParser {

QueryObject parseQuery(std::string_view query)
{
    PLAIN_QUERY_OBJECT;

    static const std::array<std::unique_ptr<Helpers::IQueryParser>, 11> s_parsers{
        std::make_unique<Helpers::StructureDropParser>(),
        std::make_unique<Helpers::StructureCreateParser>(),
        std::make_unique<Helpers::StructureRenameParser>(),
        std::make_unique<Helpers::DatabaseParser>(),
        std::make_unique<Helpers::IndexParser>(),
        std::make_unique<Helpers::StructureMigrateParser>(),
        std::make_unique<Helpers::SchemaParser>(),
        std::make_unique<Helpers::StructureDeleteParser>(),
        std::make_unique<Helpers::StructureUpdateParser>(),
        std::make_unique<Helpers::StructureSelectParser>(),
        std::make_unique<Helpers::ViewParser>()
    };
    static const auto s_parsers_end = s_parsers.end();

    const auto parser = std::find_if(s_parsers.begin(), s_parsers.end(),
        [query](const auto& parser) {
            return parser->match(query);
        });

    if (parser == s_parsers_end)
    {
        throw std::runtime_error("Invalid query syntax.");
    }

    query_obj = parser->get()->parse(query);

    RETURN_QUERY_OBJECT;
}

namespace Helpers {

IQueryParser::~IQueryParser() {}

} // namespace Helpers

} // namespace Moonlight::QueryParser
