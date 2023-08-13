#include "QueryParser.hpp"

#include <array>
#include <stdexcept>

namespace Moonlight::QueryParser {

QueryObject parseQuery(std::string_view query)
{
    PLAIN_QUERY_OBJECT;

    static const std::array<std::unique_ptr<Helpers::IQueryParser>, 11> s_parsers{
        std::make_unique<Helpers::DropParser>(),
        std::make_unique<Helpers::CreateParser>(),
        std::make_unique<Helpers::RenameParser>(),
        std::make_unique<Helpers::DatabaseParser>(),
        std::make_unique<Helpers::IndexParser>(),
        std::make_unique<Helpers::MigrateParser>(),
        std::make_unique<Helpers::SchemaParser>(),
        std::make_unique<Helpers::DeleteParser>(),
        std::make_unique<Helpers::UpdateParser>(),
        std::make_unique<Helpers::SelectParser>(),
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
