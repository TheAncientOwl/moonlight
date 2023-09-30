#pragma once

#include "QueryObject.hpp"

#include <stdexcept>

namespace Moonlight::Parser {

using QueryObject = Objects::QueryObject;

QueryObject parseQuery(std::string_view query);

} // namespace Moonlight::Parser
