#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

std::vector<std::string> extractFields(std::string_view& query)
{
    // 1. cleanup & validate format
    auto fields_str = extractValue(query, "fields");

    if (fields_str.length() > 1 && fields_str.front() != '[')
    {
        throw std::runtime_error("Missing '[' symbol @ '"s + std::string(fields_str) + "'"s);
    }
    fields_str.remove_prefix(1);

    if (fields_str.length() > 1 && fields_str.back() != ']')
    {
        throw std::runtime_error("Missing ']' symbol @ '"s + std::string(fields_str) + "'"s);
    }
    fields_str.remove_suffix(1);

    trim(fields_str);
    if (fields_str.empty())
    {
        throw std::runtime_error("Fields clause cannot be empty");
    }

    // 2. split & validate identifiers
    const auto fields = splitAtComma(fields_str);

    std::vector<std::string> out{};
    for (const auto field : fields)
    {
        if (isValidIdentifier(field))
        {
            out.emplace_back(field);
        }
        else
        {
            throw std::runtime_error("Invalid field identifier '"s + std::string(field) + "'"s);
        }
    }
    return out;
}

} // Anonymous namespace

QUERY_COULD_MATCH(Index)
{
    return startsWithIgnoreCase(query, "index");
}

QUERY_PARSER(Index)
{
    QUERY_OBJECT(obj, Index);

    cleanupQuery(query, "index");

    obj.on_structure = extractIdentifier(query, "on");
    obj.name = extractIdentifier(query, "name");
    obj.on_fields = extractFields(query);
    obj.unique = extractBoolean(query, "unique");

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation
