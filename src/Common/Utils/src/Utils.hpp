#pragma once

#include <string_view>
#include <vector>

namespace Moonlight::Common::Utils {

void trim(std::string_view& str);
void trimLeft(std::string_view& str);
void trimRight(std::string_view& str);

bool startsWithIgnoreCase(std::string_view src, std::string_view what);
bool equalsIgnoreCase(std::string_view s1, std::string_view s2);
std::vector<std::string_view> splitAt(std::string_view str, char c);

} // namespace Moonlight::Common::Utils
