#pragma once

#include "QueryData.hpp"

#include <variant>

namespace Moonlight::QueryData {

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
    struct QueryDataToEnumMap { static const Primitives::EQueryType value; };
};

template<typename Data>
inline Data& Moonlight::QueryData::QueryObject::get()
{
    return std::get<Data>(m_data);
}

template<typename Data>
inline const Data& Moonlight::QueryData::QueryObject::get() const
{
    return std::get<Data>(m_data);
}

template<typename Data>
QueryObject QueryObject::make()
{
    QueryObject obj{};
    obj.m_type = QueryDataToEnumMap<Data>::value;
    obj.m_data = Data();

    return obj;
}

} // namespace Moonlight::QueryData
