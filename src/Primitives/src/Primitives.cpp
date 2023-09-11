#include "Primitives.hpp"

#include <cctype>
#include <algorithm>
#include <stdexcept>
#include <vector>

#define MOONLIGHT_PRIMITIVE_CONVERTOR(name, ...) \
namespace name { \
    const Implementation::LiteralToStringMap<Literal> map{ { \
        __VA_ARGS__ \
    } };\
    std::string to_string(Literal literal) { return map.findByLiteral(literal); } \
    Literal to_literal(std::string str) { return map.findByString(str); } \
}

namespace Moonlight::Primitives {

namespace Implementation {

template<typename Literal>
class LiteralToStringMap
{
public:
    static_assert(std::is_enum<Literal>());

    using container = std::vector<std::pair<Literal, std::string>>;

public:
    LiteralToStringMap(container data);
    std::string findByLiteral(Literal literal) const;
    Literal findByString(std::string str) const;

private:
    container m_data;
};

template<typename Literal>
LiteralToStringMap<Literal>::LiteralToStringMap(LiteralToStringMap<Literal>::container data)
    : m_data(std::move(data))
{}

template<typename Literal>
std::string LiteralToStringMap<Literal>::findByLiteral(Literal literal) const
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
Literal LiteralToStringMap<Literal>::findByString(std::string str) const
{
    std::transform(str.begin(), str.end(), str.begin(), tolower);

    const auto it = std::find_if(m_data.begin(), m_data.end(),
        [&str](const auto& value) {
            return value.second == str;
        });

    if (it == m_data.end())
        throw std::runtime_error("Cannot parse primitive from string");

    return it->first;
}

} // namespace Implementation

MOONLIGHT_PRIMITIVE_CONVERTOR(StructureType,
    std::make_pair(Literal::Undefined, "undefined"),
    std::make_pair(Literal::Table, "table"),
    std::make_pair(Literal::Document, "document")
)

MOONLIGHT_PRIMITIVE_CONVERTOR(StructureRenameType,
    std::make_pair(Literal::Undefined, "undefined"),
    std::make_pair(Literal::Structure, "structure"),
    std::make_pair(Literal::Field, "field"),
    std::make_pair(Literal::Database, "database")
)

MOONLIGHT_PRIMITIVE_CONVERTOR(DatabaseOperationType,
    std::make_pair(Literal::Undefined, "undefined"),
    std::make_pair(Literal::Create, "create"),
    std::make_pair(Literal::Drop, "drop"),
    std::make_pair(Literal::Backup, "backup")
)

MOONLIGHT_PRIMITIVE_CONVERTOR(DataType,
    std::make_pair(Literal::Undefined, "undefined"),
    std::make_pair(Literal::String, "string"),
    std::make_pair(Literal::Boolean, "boolean"),
    std::make_pair(Literal::Decimal, "decimal"),
    std::make_pair(Literal::Integer, "integer"),
    std::make_pair(Literal::DateTime, "datetime"),
    std::make_pair(Literal::Reference, "reference")
)

MOONLIGHT_PRIMITIVE_CONVERTOR(SelectSortType,
    std::make_pair(Literal::Undefined, "undefined"),
    std::make_pair(Literal::Asc, "asc"),
    std::make_pair(Literal::Desc, "desc")
)

MOONLIGHT_PRIMITIVE_CONVERTOR(QueryType,
    std::make_pair(Literal::Undefined, "undefined"),
    std::make_pair(Literal::Schema, "schena"),
    std::make_pair(Literal::Create, "create"),
    std::make_pair(Literal::Migrate, "migrate"),
    std::make_pair(Literal::Drop, "drop"),
    std::make_pair(Literal::Delete, "delete"),
    std::make_pair(Literal::Update, "update"),
    std::make_pair(Literal::Database, "database"),
    std::make_pair(Literal::Rename, "rename"),
    std::make_pair(Literal::Select, "select"),
    std::make_pair(Literal::Insert, "insert"),
    std::make_pair(Literal::Index, "index"),
    std::make_pair(Literal::View, "view")
)

MOONLIGHT_PRIMITIVE_CONVERTOR(BooleanOperators,
    std::make_pair(Literal::Undefined, "undefined"),
    std::make_pair(Literal::Or, "or"),
    std::make_pair(Literal::And, "and"),
    std::make_pair(Literal::Eval, "eval"),
    )

} // namespace Moonlight::Primitives
