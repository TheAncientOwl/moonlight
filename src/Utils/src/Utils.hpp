#pragma once

#include <string_view>

#define WHITESPACE " \n\r\t\f\v"sv

namespace Moonlight::Utils {

void ltrim(std::string_view& str);
void rtrim(std::string_view& str);
void trim(std::string_view& str);

bool equalsIgnoreCase(std::string_view s1, std::string_view s2);
bool startsWithIgnoreCase(std::string_view src, std::string_view what);

std::string_view extractValue(std::string_view& query, std::string_view keyword);

bool isValidIdentifier(std::string_view str);

} // namespace Moonlight::Utils
