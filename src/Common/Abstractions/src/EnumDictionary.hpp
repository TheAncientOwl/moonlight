#pragma once

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <string_view>

#include "Common/Utils/src/Utils.hpp"

namespace Moonlight::Common::Utils {

template<typename EnumType>
class EnumDictionary
{
public:
    static_assert(std::is_enum<EnumType>::value, "not an enum");

    using container = std::vector<std::pair<EnumType, std::string_view>>;

    EnumDictionary(container values);

    std::string_view toString(EnumType value);
    EnumType toEnum(std::string_view value);

private:
    container m_values;
};

template<typename EnumType>
inline EnumDictionary<EnumType>::EnumDictionary(container values)
    : m_values(std::move(values))
{}

template<typename EnumType>
inline std::string_view EnumDictionary<EnumType>::toString(EnumType value)
{
    const auto it = std::find_if(m_values.begin(), m_values.end(),
        [value](const auto& element) {
            return value == element.first;
        });

    if (it == m_values.end())
    {
        throw std::runtime_error("EnumDictionary key not found");
    }

    return it->second;
}

template<typename EnumType>
inline EnumType EnumDictionary<EnumType>::toEnum(std::string_view value)
{
    const auto it = std::find_if(m_values.begin(), m_values.end(),
        [value](const auto& element) {
            return Utils::equalsIgnoreCase(value, element.second);
        });

    if (it == m_values.end())
    {
        throw std::runtime_error("EnumDictionary value not found");
    }

    return it->first;
}

} // namespace Moonlight::Common::Utils
