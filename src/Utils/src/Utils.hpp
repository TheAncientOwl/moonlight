#pragma once

#include <string_view>

namespace Moonlight::Utils {

void ltrim(std::string_view& str);
void rtrim(std::string_view& str);
void trim(std::string_view& str);

bool equalsIgnoreCase(std::string_view s1, std::string_view s2);
bool startsWithIgnoreCase(std::string_view src, std::string_view what);

} // namespace Moonlight::Utils
