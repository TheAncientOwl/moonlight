#pragma once

#include <string_view>
#include <memory>
#include <vector>
#include <array>
#include <optional>
#include <functional>

#define WHITESPACE " \n\r\t\f\v"sv

namespace Moonlight::Utils {

void ltrim(std::string_view& str);
void rtrim(std::string_view& str);
void trim(std::string_view& str);

bool equalsIgnoreCase(std::string_view s1, std::string_view s2);
bool startsWithIgnoreCase(std::string_view src, std::string_view what);

bool isValidIdentifier(std::string_view str);
void cleanupQuery(std::string_view& query, std::string_view prefix);

enum class EParserModifier
{
    None = 0,
    EscapeQuotes = 1
};

std::vector<std::string_view> splitAtComma(std::string_view str, EParserModifier modifier = EParserModifier::None);

std::string_view extractValue(std::string_view& query, std::string_view keyword, EParserModifier modifier = EParserModifier::None);
std::string_view extractIdentifier(std::string_view& query, std::string_view keyword);
bool extractBoolean(std::string_view& query, std::string_view keyword);
std::vector<std::string_view> extractList(std::string_view& query, std::string_view keyword, EParserModifier modifier = EParserModifier::None);
std::vector<std::string> extractIdentifiersList(std::string_view& query, std::string_view keyword);

template<typename Base, typename... Derived>
class HierarchyMap
{
public:
    using BasePtr = std::shared_ptr<Base>;
    using ConstBasePtr = const BasePtr;
    using Container = std::array<BasePtr, sizeof...(Derived)>;

public:
    HierarchyMap();

    BasePtr findIf(std::function<bool(Base& current)> valid);
    ConstBasePtr findIf(std::function<bool(const Base& current)> valid) const;

private:
    Container m_data;
};

template<typename Base, typename ...Derived>
inline HierarchyMap<Base, Derived...>::HierarchyMap()
    : m_data({ (std::make_unique<Derived>())... })
{}

template<typename Base, typename ...Derived>
inline HierarchyMap<Base, Derived...>::BasePtr HierarchyMap<Base, Derived...>::findIf(std::function<bool(Base& current)> valid)
{
    auto value_it = std::find_if(m_data.begin(), m_data.end(), [&valid](auto& it) -> bool { return valid(*it); });

    if (value_it != m_data.end())
    {
        return *value_it;
    }

    return nullptr;
}

template<typename Base, typename ...Derived>
inline HierarchyMap<Base, Derived...>::ConstBasePtr HierarchyMap<Base, Derived...>::findIf(std::function<bool(const Base& current)> valid) const
{
    const auto value_it = std::find_if(m_data.begin(), m_data.end(), [&valid](const auto& it) -> bool { return valid(*it); });

    if (value_it != m_data.end())
    {
        return *value_it;
    }

    return nullptr;
}

} // namespace Moonlight::Utils
