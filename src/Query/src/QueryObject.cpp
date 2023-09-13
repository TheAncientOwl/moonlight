#include "common/QueryObject.hpp"

#define MAP_QUERY_DATA_TO_ENUM(ParsedQuery, Enum) \
    template <> const EQueryType \
    QueryObject::ParsedQueryToEnumMap<ParsedQuery>::value = EQueryType::Enum;

namespace Moonlight::ParsedQuery {

using EQueryType = Primitives::EQueryType;

Primitives::EQueryType Moonlight::ParsedQuery::QueryObject::type() const
{
    return m_type;
}

template<typename T>
const EQueryType QueryObject::ParsedQueryToEnumMap<T>::value = EQueryType::Undefined;

MAP_QUERY_DATA_TO_ENUM(Drop, Drop)
MAP_QUERY_DATA_TO_ENUM(Create, Create)
MAP_QUERY_DATA_TO_ENUM(Rename, Rename)
MAP_QUERY_DATA_TO_ENUM(Database, Database)
MAP_QUERY_DATA_TO_ENUM(Index, Index)
MAP_QUERY_DATA_TO_ENUM(Migrate, Migrate)
MAP_QUERY_DATA_TO_ENUM(Schema, Schema)
MAP_QUERY_DATA_TO_ENUM(Delete, Delete)
MAP_QUERY_DATA_TO_ENUM(Update, Update)
MAP_QUERY_DATA_TO_ENUM(Select, Select)
MAP_QUERY_DATA_TO_ENUM(View, View)
MAP_QUERY_DATA_TO_ENUM(Insert, Insert)

} // namespace Moonlight::ParsedQuery
