#include "Utils.hpp"

#include <cctype>

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

} // namespace Moonlight::Utils
