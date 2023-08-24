#include "Utils.hpp"

#include <stdexcept>
#include <cctype>
#include <string>
#include <regex>

namespace Moonlight::Utils {

using namespace std::literals;

void ltrim(std::string_view& str)
{
    if (!str.empty())
    {
        const auto begin{ str.find_first_not_of(WHITESPACE) };

        str = str.substr(std::min(begin, str.length()));
    }
}

void rtrim(std::string_view& str)
{
    if (!str.empty())
    {
        const auto end{ str.find_last_not_of(WHITESPACE) };

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

bool isValidIdentifier(std::string_view str)
{
    static const std::regex c_identifier_regex{ R"(\w+)" };

    return std::regex_match(str.begin(), str.end(), c_identifier_regex);
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

    if (query.empty())
    {
        throw std::runtime_error("Query body cannot be empty");
    }
}

/**
 * @brief split a string at ','
 *
 * @param str string to be splitted
 * @param modifier EscapeQuotes if quotes can be escaped using backslash char
 * @return std::vector<std::string_view> splits
 */
std::vector<std::string_view> splitAtComma(std::string_view str, EParserModifier modifier)
{
    std::vector<std::string_view> out{};

    trim(str);
    if (str.empty())
    {
        return out;
    }

    bool quoted_string{ false };
    const auto c_end{ std::cend(str) };
    const auto c_begin{ std::cbegin(str) };

    auto word_begin{ c_begin };
    auto word_end{ c_begin };

    const auto update_output = [&out, modifier](const char* word_begin, const char* word_end) {
        std::string_view word{ word_begin, static_cast<std::string_view::size_type>(std::distance(word_begin, word_end)) };
        trim(word);

        if (modifier == EParserModifier::EscapeQuotes && word.length() > 1 &&
            word.starts_with('"') && word.ends_with('"'))
        {
            word.remove_prefix(1);
            word.remove_suffix(1);
        }

        if (!word.empty())
        {
            out.push_back(word);
        }
        };

    while (word_end != c_end)
    {
        const auto current_char{ *word_end };
        const auto prev_char{ word_end != c_begin ? *std::prev(word_end) : ' ' };

        if (modifier == EParserModifier::EscapeQuotes && current_char == '"' && prev_char != '\\')
        {
            quoted_string = !quoted_string;
        }
        else if (current_char == ',' && !quoted_string)
        {
            quoted_string = false;

            update_output(word_begin, word_end);

            word_begin = std::next(word_end);
        }

        word_end = std::next(word_end);
    }

    if (word_begin != word_end)
    {
        update_output(word_begin, word_end);
    }

    return out;
}

/**
 * @brief Query format: [whitespace]keyword[:][whitespace]value[whitespace][;][query...].
 *
 * @param query string representation of the query
 * @param keyword keyword to be matched
 * @param modifier specifies if quotes escape ';' character
 * @return std::string_view - trimmed value
 */
std::string_view extractValue(std::string_view& query, std::string_view keyword, EParserModifier modifier)
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
    const auto find_end_pos = [modifier](std::string_view str) -> std::size_t {
        const auto c_end{ std::cend(str) };
        const auto c_begin{ std::cbegin(str) };

        bool quoted_string{ false };
        bool semicolon_found{ false };

        auto end_pos{ std::cbegin(str) };
        while (end_pos != c_end)
        {
            const auto current_char{ *end_pos };
            const auto prev_char{ end_pos != c_begin ? *std::prev(end_pos) : ' ' };

            if (modifier == EParserModifier::EscapeQuotes && current_char == '"' && prev_char != '\\')
            {
                quoted_string = !quoted_string;
            }
            else if (current_char == ';')
            {
                semicolon_found = true;
                if (!quoted_string)
                {
                    return std::distance(std::cbegin(str), end_pos);
                }
            }

            end_pos = std::next(end_pos);
        }

        if (std::cbegin(str) != end_pos && !quoted_string && semicolon_found)
        {
            return std::distance(std::cbegin(str), end_pos);
        }

        return std::string_view::npos;
        };

    const auto end_pos{ find_end_pos(query) };
    if (end_pos == std::string_view::npos)
    {
        throw std::runtime_error("Missing ';' @"s + std::string(query));
    }

    // 4. extract & remove value
    auto value{ query.substr(0, end_pos) };
    trim(value);
    if (value.empty())
    {
        throw std::runtime_error("Value cannot be empty @ keyword '"s + std::string(keyword) + "'"s);
    }
    query.remove_prefix(end_pos + 1);

    return value;
}

/**
 * @brief extract value and cleanup query
 *
 * @param query string representation of query in format "keyword: identifier; [query...]"
 */
std::string_view extractIdentifier(std::string_view& query, std::string_view keyword)
{
    const auto name{ extractValue(query, keyword) };

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
    const auto boolean_str{ extractValue(query, keyword) };

    if (equalsIgnoreCase(boolean_str, "true"))
    {
        return true;
    }
    else if (equalsIgnoreCase(boolean_str, "false"))
    {
        return false;
    }
    else
    {
        throw std::runtime_error("Invalid boolean value '"s + std::string(boolean_str) + "'"s);
    }
}

std::vector<std::string_view> extractList(std::string_view& query, std::string_view keyword, EParserModifier modifier)
{
    auto list_sequence{ extractValue(query, keyword, modifier) };

    if (list_sequence.front() != '[')
    {
        throw std::runtime_error("Missing '[' symbol in fields sequence");
    }

    if (list_sequence.back() != ']')
    {
        throw std::runtime_error("Missing ']' symbol in fields sequence");
    }

    list_sequence.remove_prefix(1);
    list_sequence.remove_suffix(1);

    const auto list = splitAtComma(list_sequence, modifier);
    if (list.empty())
    {
        throw std::runtime_error("List cannot be empty @ '"s + std::string(query) + "'"s);
    }
    return list;
}

/**
 * @brief
 *
 * @param query query representation in format "keyword: [ identifier1, identifier2, ... ]; [query...]"
 * @param keyword keyword to be matched
 * @return std::vector<std::string> identifiers
 */
std::vector<std::string> extractIdentifiersList(std::string_view& query, std::string_view keyword)
{
    const auto fields{ extractList(query, keyword) };

    std::vector<std::string> out{};
    out.reserve(fields.size());

    for (const auto field : fields)
    {
        if (isValidIdentifier(field))
        {
            out.emplace_back(field);
        }
        else
        {
            throw std::runtime_error("Invalid identifier '"s + std::string(field) + "'"s);
        }
    }
    return out;
}

} // namespace Moonlight::Utils
