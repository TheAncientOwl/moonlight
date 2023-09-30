#include "common/QueryParsers.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::Parser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

constexpr auto c_query_prefix{ "insert into" };

std::vector<std::string> extractFields(std::string_view& query)
{
    std::vector<std::string> out{};

    try
    {
        const auto fields{ extractList(query, "fields", EParserModifier::EscapeQuotes) };

        out.reserve(fields.size());

        for (auto field : fields)
        {
            out.emplace_back(field);
        }
    }
    catch (const std::runtime_error& e)
    {
        if (!equalsIgnoreCase(e.what(), "Invalid query, missing 'fields' keyword"))
        {
            throw e;
        }
    }

    return out;
}

std::vector<std::string> extractValues(std::string_view& query)
{
    const auto values{ extractList(query, "values", EParserModifier::EscapeQuotes) };

    std::vector<std::string> out{};
    out.reserve(values.size());

    for (auto value : values)
    {
        out.emplace_back(value);
    }

    return out;
}

} // Anonymous namespace

QUERY_PARSER_CLASS_IMPL(Insert, c_query_prefix)
{
    QUERY_OBJECT(obj, Insert);

    cleanupQuery(query, c_query_prefix);

    obj.structure = extractIdentifier(query, "structure");
    obj.fields = extractFields(query);
    obj.values = extractValues(query);

    if (obj.fields.size() > 0 && obj.fields.size() != obj.values.size())
    {
        throw std::runtime_error("Number of fields must be equal to the number of values provided");
    }

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::Parser::Implementation 
