#pragma once

#include "ParsedQueries.hpp"

#include <variant>

namespace Moonlight::ParsedQuery {

class QueryObject
{
public: // methods
    Primitives::EQueryType type() const;

    template<typename Data>
    Data& get();

    template<typename Data>
    const Data& get() const;

public: // make
    template<typename Data>
    static QueryObject make();

private: // fields
    Primitives::EQueryType m_type;

    std::variant <
        Drop,
        Create,
        Rename,
        Database,
        Index,
        Migrate,
        Schema,
        Delete,
        Update,
        Select,
        View
    > m_data;

    template<typename T>
    struct ParsedQueryToEnumMap { static const Primitives::EQueryType value; };
};

template<typename Data>
inline Data& Moonlight::ParsedQuery::QueryObject::get()
{
    return std::get<Data>(m_data);
}

template<typename Data>
inline const Data& Moonlight::ParsedQuery::QueryObject::get() const
{
    return std::get<Data>(m_data);
}

template<typename Data>
QueryObject QueryObject::make()
{
    QueryObject obj{};
    obj.m_type = ParsedQueryToEnumMap<Data>::value;
    obj.m_data = Data();

    return obj;
}

} // namespace Moonlight::ParsedQuery
