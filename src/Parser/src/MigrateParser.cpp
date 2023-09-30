#include "common/QueryParsers.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::Parser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

constexpr auto c_query_prefix{ "migrate" };

std::pair<std::string_view, std::string_view> parseMapping(std::string_view mapping)
{
    const auto left_end{ mapping.find_first_of(WHITESPACE) };
    const auto right_begin{ mapping.find_last_of(WHITESPACE) };

    if (left_end == std::string_view::npos || right_begin == std::string_view::npos || left_end == right_begin)
    {
        throw std::runtime_error("Missing ' ' in mapping '"s + std::string(mapping) + "'"s);
    }

    std::string_view middle{ mapping.substr(left_end, right_begin - left_end + 1) };
    trim(middle);
    if (middle != "=>"sv)
    {
        throw std::runtime_error("Missing '=>' symbol in mapping '"s + std::string(mapping) + "'"s);
    }

    auto left{ mapping.substr(0, left_end) };
    auto right{ mapping.substr(right_begin + 1) };

    const auto validate_field = [mapping](std::string_view field) {
        if (field.empty())
        {
            throw std::runtime_error("Empty field @ '"s + std::string(mapping) + "'"s);
        }

        if (!isValidIdentifier(field))
        {
            throw std::runtime_error("Invalid field identifier @ '"s + std::string(mapping) + "'"s);
        }
        };

    validate_field(left);
    validate_field(right);

    return std::make_pair(left, right);
}

std::vector<std::pair<std::string, std::string>> extractMappings(std::string_view& query)
{
    // 1. cleanup & validate format
    auto mappings_str{ extractValue(query, "mappings") };

    if (mappings_str.length() > 1 && mappings_str.front() != '[')
    {
        throw std::runtime_error("Missing '[' symbol @ '"s + std::string(mappings_str) + "'"s);
    }
    mappings_str.remove_prefix(1);

    if (mappings_str.length() > 1 && mappings_str.back() != ']')
    {
        throw std::runtime_error("Missing ']' symbol @ '"s + std::string(mappings_str) + "'"s);
    }
    mappings_str.remove_suffix(1);

    trim(mappings_str);
    if (mappings_str.empty())
    {
        throw std::runtime_error("Mappings clause cannot be empty");
    }

    // 2. split & validate identifiers
    const auto mappings{ splitAtComma(mappings_str) };

    std::vector<std::pair<std::string, std::string>> out{};
    out.reserve(mappings.size());

    for (const auto& mapping : mappings)
    {
        out.emplace_back(parseMapping(mapping));
    }
    return out;
}

} // Anonymous namespace

QUERY_PARSER_CLASS_IMPL(Migrate, c_query_prefix)
{
    QUERY_OBJECT(obj, Migrate);

    cleanupQuery(query, c_query_prefix);

    obj.structure_name = extractIdentifier(query, "structure");
    obj.new_schema = extractIdentifier(query, "to");
    obj.mappings = extractMappings(query);

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::Parser::Implementation
