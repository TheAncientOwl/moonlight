#pragma once

#include <string_view>
#include <vector>

#define WHITESPACE " \n\r\t\f\v"sv

namespace Moonlight::Utils {

void ltrim(std::string_view& str);
void rtrim(std::string_view& str);
void trim(std::string_view& str);

bool equalsIgnoreCase(std::string_view s1, std::string_view s2);
bool startsWithIgnoreCase(std::string_view src, std::string_view what);

bool isValidIdentifier(std::string_view str);

enum class EParserModifier
{
    None = 0,
    EscapeQuotes = 1
};

std::string_view extractValue(std::string_view& query, std::string_view keyword, EParserModifier modifier = EParserModifier::None);
std::string_view extractIdentifier(std::string_view& query, std::string_view keyword);
bool extractBoolean(std::string_view& query, std::string_view keyword);
std::vector<std::string> extractIdentifiersList(std::string_view& query, std::string_view keyword);

void cleanupQuery(std::string_view& query, std::string_view prefix);
std::vector<std::string_view> splitAtComma(std::string_view str, EParserModifier modifier = EParserModifier::None);

} // namespace Moonlight::Utils
