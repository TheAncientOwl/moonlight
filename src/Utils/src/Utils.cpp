#include "Utils.hpp"

namespace Moonlight::Utils {

using namespace std::literals;

constexpr auto c_whitespace = " \n\r\t\f\v"sv;

std::string_view ltrim(std::string_view str)
{
    const auto start = str.find_first_not_of(c_whitespace);
    return (start == std::string_view::npos) ? "" : str.substr(start);
}

std::string_view rtrim(std::string_view str)
{
    const auto end = str.find_last_not_of(c_whitespace);
    return (end == std::string_view::npos) ? "" : str.substr(0, end + 1);
}

std::string_view trim(std::string_view str)
{
    return ltrim(rtrim(str));
}

} // namespace Moonlight::Utils
