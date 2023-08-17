#pragma once

#include <string_view>

namespace Moonlight::Utils {

std::string_view ltrim(std::string_view str);
std::string_view rtrim(std::string_view str);
std::string_view trim(std::string_view str);

} // namespace Moonlight::Utils
