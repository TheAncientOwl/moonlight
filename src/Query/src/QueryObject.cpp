#include "QueryObject.hpp"

#define MAP_QUERY_DATA_TO_ENUM(QueryData, Enum) \
    template <> const EQueryType \
    QueryObject::QueryDataToEnumMap<QueryData>::value = EQueryType::Enum;

namespace Moonlight::QueryData {

using EQueryType = Primitives::EQueryType;

Primitives::EQueryType Moonlight::QueryData::QueryObject::type() const
{
    return m_type;
}

template<typename T>
const EQueryType QueryObject::QueryDataToEnumMap<T>::value = EQueryType::Undefined;

MAP_QUERY_DATA_TO_ENUM(StructureDrop, Drop)
MAP_QUERY_DATA_TO_ENUM(StructureCreate, Create)
MAP_QUERY_DATA_TO_ENUM(StructureRename, Rename)
MAP_QUERY_DATA_TO_ENUM(Database, Database)
MAP_QUERY_DATA_TO_ENUM(Index, Index)
MAP_QUERY_DATA_TO_ENUM(StructureMigrate, Migrate)
MAP_QUERY_DATA_TO_ENUM(Schema, Schema)
MAP_QUERY_DATA_TO_ENUM(StructureDelete, Delete)
MAP_QUERY_DATA_TO_ENUM(StructureUpdate, Update)
MAP_QUERY_DATA_TO_ENUM(StructureSelect, Select)
MAP_QUERY_DATA_TO_ENUM(View, View)

} // namespace Moonlight::QueryData
