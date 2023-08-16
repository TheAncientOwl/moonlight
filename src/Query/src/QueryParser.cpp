#include "QueryParser.hpp"

#include <array>
#include <stdexcept>
#include <memory>

namespace Moonlight::QueryParser {

QueryObject parseQuery(std::string_view query)
{
    PLAIN_QUERY_OBJECT;

    static const std::array<std::unique_ptr<Implementation::IQueryParser>, 11> s_parsers{
        std::make_unique<Implementation::DropParser>(),
        std::make_unique<Implementation::CreateParser>(),
        std::make_unique<Implementation::RenameParser>(),
        std::make_unique<Implementation::DatabaseParser>(),
        std::make_unique<Implementation::IndexParser>(),
        std::make_unique<Implementation::MigrateParser>(),
        std::make_unique<Implementation::SchemaParser>(),
        std::make_unique<Implementation::DeleteParser>(),
        std::make_unique<Implementation::UpdateParser>(),
        std::make_unique<Implementation::SelectParser>(),
        std::make_unique<Implementation::ViewParser>()
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

namespace Implementation {

IQueryParser::~IQueryParser() {}

} // namespace Implementation

} // namespace Moonlight::QueryParser
