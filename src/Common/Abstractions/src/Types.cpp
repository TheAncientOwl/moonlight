#include <cctype>
#include <algorithm>

#include "Common/Utils/src/Utils.hpp"
#include "EnumDictionary.hpp"
#include "Types.hpp"

#define DEFINE_ENUM_DICTIONARY(enum_name, ...) \
    namespace enum_name { \
        Utils::EnumDictionary<EValue> dictionary{{ __VA_ARGS__ }}; \
        EValue toEnum(std::string_view str) { return dictionary.toEnum(str); } \
        std::string_view toString(EValue type) { return dictionary.toString(type); }\
    }

namespace Moonlight::Common::Types {

DEFINE_ENUM_DICTIONARY(StructureTypes,
    { EValue::Document, "document" },
    { EValue::Table, "table" },
    { EValue::None, "none" }
);

} // namespace Moonlight::Common::Types
