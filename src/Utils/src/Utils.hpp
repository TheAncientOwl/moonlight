#pragma once

#include <string_view>

namespace Moonlight::Utils {

std::string_view ltrim(std::string_view str);
std::string_view rtrim(std::string_view str);
std::string_view trim(std::string_view str);

bool equalsIgnoreCase(std::string_view s1, std::string_view s2);
bool startsWithIgnoreCase(std::string_view src, std::string_view what);

} // namespace Moonlight::Utils
