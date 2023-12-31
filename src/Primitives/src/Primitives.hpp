#pragma once

#include <string>

#define MOONLIGHT_PRIMITIVE(name, ...) \
namespace name { \
    enum class Literal : std::uint8_t \
    { \
        __VA_ARGS__ \
    }; \
    std::string_view to_string(Literal primitive); \
    Literal to_literal(std::string_view str); \
} \
using E ## name = name::Literal;

namespace Moonlight::Primitives {

MOONLIGHT_PRIMITIVE(StructureType,
    Undefined = 0,
    Table = 1,
    Document = 2
)

MOONLIGHT_PRIMITIVE(StructureRenameType,
    Undefined = 0,
    Structure = 1,
    Field = 2,
    Database = 3
)

MOONLIGHT_PRIMITIVE(DatabaseOperationType,
    Undefined = 0,
    Create = 1,
    Drop = 2,
    Backup = 3
)

MOONLIGHT_PRIMITIVE(DataType,
    Undefined = 0,
    String = 1,
    Boolean = 2,
    Decimal = 3,
    Integer = 4,
    DateTime = 5,
    Reference = 6
)

MOONLIGHT_PRIMITIVE(SelectSortType,
    Undefined = 0,
    Asc = 1,
    Desc = 2
)

MOONLIGHT_PRIMITIVE(QueryType,
    Undefined = 0,
    Schema = 1,
    Create = 2,
    Migrate = 3,
    Drop = 4,
    Delete = 5,
    Update = 6,
    Database = 7,
    Rename = 8,
    Select = 9,
    Insert = 10,
    Index = 11,
    View = 12
)

MOONLIGHT_PRIMITIVE(BooleanOperators,
    Undefined = 0,
    Or = 1,
    And = 2,
    Eval = 3
)

} // namespace Moonlight::Primitives
