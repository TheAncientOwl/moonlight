#include <string>
#include <cctype>

#include "Utils.hpp"

namespace Moonlight::Common::Utils {

void trim(std::string_view& str)
{
    trimLeft(str);
    trimRight(str);
}

void trimLeft(std::string_view& str)
{
    while (!str.empty() && str.starts_with(' '))
    {
        str.remove_prefix(1);
    }
}

void trimRight(std::string_view& str)
{
    while (!str.empty() && str.ends_with(' '))
    {
        str.remove_suffix(1);
    }
}

void trimLeftAnyOf(std::string_view& src, std::string_view what)
{
    while (what.find(src.front()) != std::string_view::npos)
    {
        src.remove_prefix(1);
    }
}

bool startsWithIgnoreCase(std::string_view src, std::string_view what)
{
    if (what.length() > src.length()) return false;

    for (std::size_t i = 0, length = what.length(); i < length; i++)
    {
        if (toupper(what[i]) != toupper(src[i]))
        {
            return false;
        }
    }

    return true;
}

bool equalsIgnoreCase(std::string_view s1, std::string_view s2)
{
    const auto length1 = s1.length();
    const auto length2 = s2.length();

    if (length1 != length2)
    {
        return false;
    }

    for (std::size_t i = 0; i < length1; i++)
    {
        if (toupper(s1[i]) != toupper(s2[i]))
        {
            return false;
        }
    }

    return true;
}

std::vector<std::string_view> splitAt(std::string_view src, char c)
{
    std::vector<std::string_view> parts{};

    auto first = std::cbegin(src);
    auto last = std::find(first, std::cend(src), c);

    for (const auto end = std::cend(src); last != end;
        first = std::next(last), last = std::find(first, std::cend(src), c))
    {
        if (first != last)
            parts.emplace_back(first, std::distance(first, last));
    }

    if (first != last)
    {
        if (std::string_view last_part(first, std::distance(first, last));
            !last_part.empty())
        {
            parts.push_back(last_part);
        }
    }

    return parts;
}

} // namespace Moonlight::Common::Utils
