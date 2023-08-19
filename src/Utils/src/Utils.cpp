#include "Utils.hpp"

#include <stdexcept>
#include <cctype>
#include <string>
#include <regex>

namespace Moonlight::Utils {

using namespace std::literals;

constexpr auto c_whitespace = " \n\r\t\f\v"sv;

void ltrim(std::string_view& str)
{
    if (!str.empty())
    {
        const auto start = str.find_first_not_of(c_whitespace);

        str = str.substr(std::min(start, str.length()));
    }
}

void rtrim(std::string_view& str)
{
    if (!str.empty())
    {
        const auto end = str.find_last_not_of(c_whitespace);

        str = str.substr(0, end + 1);
    }
}

void trim(std::string_view& str)
{
    ltrim(str);
    rtrim(str);
}

bool equalsIgnoreCase(std::string_view s1, std::string_view s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }

    for (std::size_t i = 0, length = s1.length(); i < length; i++)
    {
        if (toupper(s1[i]) != toupper(s2[i]))
        {
            return false;
        }
    }

    return true;
}

bool startsWithIgnoreCase(std::string_view src, std::string_view what)
{
    if (what.length() > src.length())
    {
        return false;
    }

    return equalsIgnoreCase(src.substr(0, what.length()), what);
}

/**
 * @brief -> query format: [whitespace]keyword[:][whitespace]value[whitespace][;][query...].
 *
 * @param query -> string representation of the query
 * @param keyword -> keyword to be removed
 * @return std::string_view -> trimmed value
 */
std::string_view extractValue(std::string_view& query, std::string_view keyword)
{
    // 1. check if query starts with the keyword
    ltrim(query);
    if (!startsWithIgnoreCase(query, keyword))
    {
        throw std::runtime_error("Invalid query, missing '"s + std::string(keyword) + "' keyword"s);
    }

    // 2. remove keyword + ':' symbol && assert query not empty
    query.remove_prefix(keyword.length());
    ltrim(query);
    if (query.empty() || !query.starts_with(':'))
    {
        throw std::runtime_error("Missing ':' symbol @ '"s + std::string(query) + "'"s);
    }
    query.remove_prefix(1);
    ltrim(query);
    if (query.empty())
    {
        throw std::runtime_error("Missing value for keyword '"s + std::string(keyword) + "'"s);
    }

    // 3. find ';' (end of value)
    const auto end_pos = query.find_first_of(';');
    if (end_pos == std::string_view::npos)
    {
        throw std::runtime_error("Missing ';' @"s + std::string(query));
    }

    // 4. extract & remove value
    auto value = query.substr(0, end_pos);
    trim(value);
    if (value.empty())
    {
        throw std::runtime_error("Value cannot be empty @ keyword '"s + std::string(keyword) + "'"s);
    }
    query.remove_prefix(end_pos + 1);

    return value;
}

bool isValidIdentifier(std::string_view str)
{
    static const std::regex c_identifier_regex(R"(\w+)");

    return std::regex_match(str.begin(), str.end(), c_identifier_regex);
}

/**
 * @brief extract value and cleanup query
 *
 * @param query string representation of query in format "keyword: identifier; [query...]"
 */
std::string_view extractIdentifier(std::string_view& query, std::string_view keyword)
{
    const auto name = extractValue(query, keyword);

    if (!isValidIdentifier(name))
    {
        throw std::runtime_error("Invalid identifier name @ '"s + std::string(name) + "'"s);
    }

    return name;
}

/**
 * @brief extract value and cleanup query
 *
 * @param query string representation of query in format "keyword: true|false; [query...]"
 */
bool extractBoolean(std::string_view& query, std::string_view keyword)
{
    const auto boolean = extractValue(query, keyword);

    if (equalsIgnoreCase(boolean, "true"))
    {
        return true;
    }
    else if (equalsIgnoreCase(boolean, "false"))
    {
        return false;
    }
    else
    {
        throw std::runtime_error("Invalid boolean value '"s + std::string(boolean) + "'"s);
    }
}

/**
 * @brief bring query to format: "content"
 *
 * @param query string representation of query in format: "prefix { content };"
 */
void cleanupQuery(std::string_view& query, std::string_view prefix)
{
    query.remove_prefix(prefix.length());
    ltrim(query);

    if (query.front() != '{')
    {
        throw std::runtime_error("Missing '{' symbol");
    }
    query.remove_prefix(1);

    if (query.back() != ';')
    {
        throw std::runtime_error("Missing ';' symbol");
    }
    query.remove_suffix(1);
    rtrim(query);

    if (query.back() != '}')
    {
        throw std::runtime_error("Missing '}' symbol");
    }
    query.remove_suffix(1);

    trim(query);
}

} // namespace Moonlight::Utils
