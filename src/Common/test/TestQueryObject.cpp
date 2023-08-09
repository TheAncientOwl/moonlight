#include <gtest/gtest.h>

#include "../QueryObject/QueryObject.hpp"

#define ASSERT_MAKE_QUERY_OBJECT(Type, Enum) \
    ASSERT_EQ(QueryObject::make<Type>().type(), Primitives::EQueryType::Enum);

namespace Moonlight::QueryData {

TEST(MoonlightQueryDataTest, MakeObjects)
{
    ASSERT_MAKE_QUERY_OBJECT(StructureDrop, Drop);
    ASSERT_MAKE_QUERY_OBJECT(StructureCreate, Create);
    ASSERT_MAKE_QUERY_OBJECT(StructureRename, Rename);
    ASSERT_MAKE_QUERY_OBJECT(Database, Database);
    ASSERT_MAKE_QUERY_OBJECT(Index, Index);
    ASSERT_MAKE_QUERY_OBJECT(StructureMigrate, Migrate);
    ASSERT_MAKE_QUERY_OBJECT(Schema, Schema);
    ASSERT_MAKE_QUERY_OBJECT(StructureDelete, Delete);
    ASSERT_MAKE_QUERY_OBJECT(StructureUpdate, Update);
    ASSERT_MAKE_QUERY_OBJECT(StructureSelect, Select);
    ASSERT_MAKE_QUERY_OBJECT(View, View);
}

} // namespace Moonlight::QueryData
