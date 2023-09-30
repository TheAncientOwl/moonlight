#include <gtest/gtest.h>

#include "common/QueryObject.hpp"

#define ASSERT_MAKE_QUERY_OBJECT(Type, Enum) \
    ASSERT_EQ(QueryObject::make<Type>().type(), Primitives::EQueryType::Enum);

namespace Moonlight::Parser::Objects {

TEST(QueryDataTest, MakeObjects)
{
    ASSERT_MAKE_QUERY_OBJECT(Drop, Drop);
    ASSERT_MAKE_QUERY_OBJECT(Create, Create);
    ASSERT_MAKE_QUERY_OBJECT(Rename, Rename);
    ASSERT_MAKE_QUERY_OBJECT(Database, Database);
    ASSERT_MAKE_QUERY_OBJECT(Index, Index);
    ASSERT_MAKE_QUERY_OBJECT(Migrate, Migrate);
    ASSERT_MAKE_QUERY_OBJECT(Schema, Schema);
    ASSERT_MAKE_QUERY_OBJECT(Delete, Delete);
    ASSERT_MAKE_QUERY_OBJECT(Update, Update);
    ASSERT_MAKE_QUERY_OBJECT(Select, Select);
    ASSERT_MAKE_QUERY_OBJECT(View, View);
    ASSERT_MAKE_QUERY_OBJECT(Insert, Insert);
}

} // namespace Moonlight::Parser::Objects
