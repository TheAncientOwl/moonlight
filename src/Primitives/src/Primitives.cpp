#include "Primitives.hpp"

#include <cctype>
#include <stdexcept>
#include <vector>
#include <string_view>

#include "Utils/src/Utils.hpp"

#define MOONLIGHT_PRIMITIVE_CONVERTOR(name, ...) \
namespace name { \
    namespace Internal { \
        const Implementation::LiteralToStringMap<Literal> map{ { \
            __VA_ARGS__ \
        } };\
    } \
    std::string_view to_string(Literal literal) { return Internal::map.findByLiteral(literal); } \
    Literal to_literal(std::string_view str) { return Internal::map.findByString(str); } \
}

namespace Moonlight::Primitives {

namespace Implementation {

template<typename Literal>
class LiteralToStringMap
{
public:
    static_assert(std::is_enum<Literal>());

    using container = std::vector<std::pair<Literal, std::string_view>>;

public:
    LiteralToStringMap(container data);
    std::string_view findByLiteral(Literal literal) const;
    Literal findByString(std::string_view str) const;

private:
    container m_data;
};

template<typename Literal>
LiteralToStringMap<Literal>::LiteralToStringMap(LiteralToStringMap<Literal>::container data)
    : m_data(std::move(data))
{}

template<typename Literal>
std::string_view LiteralToStringMap<Literal>::findByLiteral(Literal literal) const
{
    const auto it = std::find_if(m_data.begin(), m_data.end(),
        [literal](const auto& value) {
            return value.first == literal;
        });

    if (it == m_data.end())
        throw std::runtime_error("Cannot parse primitive from literal");

    return it->second;
}

template<typename Literal>
Literal LiteralToStringMap<Literal>::findByString(std::string_view str) const
{
    const auto it = std::find_if(m_data.begin(), m_data.end(),
        [&str](const auto& value) {
            return Utils::equalsIgnoreCase(value.second, str);
        });

    if (it == m_data.end())
        throw std::runtime_error("Cannot parse primitive from string");

    return it->first;
}

} // namespace Implementation

MOONLIGHT_PRIMITIVE_CONVERTOR(StructureType,
    { Literal::Undefined, "undefined" },
    { Literal::Table, "table" },
    { Literal::Document, "document" }
)

MOONLIGHT_PRIMITIVE_CONVERTOR(StructureRenameType,
    { Literal::Undefined, "undefined" },
    { Literal::Structure, "structure" },
    { Literal::Field, "field" },
    { Literal::Database, "database" }
)

MOONLIGHT_PRIMITIVE_CONVERTOR(DatabaseOperationType,
    { Literal::Undefined, "undefined" },
    { Literal::Create, "create" },
    { Literal::Drop, "drop" },
    { Literal::Backup, "backup" }
)

MOONLIGHT_PRIMITIVE_CONVERTOR(DataType,
    { Literal::Undefined, "undefined" },
    { Literal::String, "string" },
    { Literal::Boolean, "boolean" },
    { Literal::Decimal, "decimal" },
    { Literal::Integer, "integer" },
    { Literal::DateTime, "datetime" },
    { Literal::Reference, "reference" }
)

MOONLIGHT_PRIMITIVE_CONVERTOR(SelectSortType,
    { Literal::Undefined, "undefined" },
    { Literal::Asc, "asc" },
    { Literal::Desc, "desc" }
)

MOONLIGHT_PRIMITIVE_CONVERTOR(QueryType,
    { Literal::Undefined, "undefined" },
    { Literal::Schema, "schena" },
    { Literal::Create, "create" },
    { Literal::Migrate, "migrate" },
    { Literal::Drop, "drop" },
    { Literal::Delete, "delete" },
    { Literal::Update, "update" },
    { Literal::Database, "database" },
    { Literal::Rename, "rename" },
    { Literal::Select, "select" },
    { Literal::Insert, "insert" },
    { Literal::Index, "index" },
    { Literal::View, "view" }
)

MOONLIGHT_PRIMITIVE_CONVERTOR(BooleanOperators,
    { Literal::Undefined, "undefined" },
    { Literal::Or, "or" },
    { Literal::And, "and" },
    { Literal::Eval, "eval" },
    )

} // namespace Moonlight::Primitives
