#pragma once

#include <string>

#define DEFINE_ENUM_TYPE(enum_name, ...) \
    namespace enum_name { \
        enum class EValue { __VA_ARGS__ }; \
        EValue toEnum(std::string_view str); \
        std::string_view toString(EValue type); \
    } \

namespace Moonlight::Common::Types {

DEFINE_ENUM_TYPE(StructureTypes,
    None,
    Table,
    Document
);

} // namespace Moonlight::Common::Types
