#include <gtest/gtest.h>

#include "Primitives.hpp"

namespace Moonlight::Primitives {

TEST(PrimitivesTest, StructureType)
{
    using namespace StructureType;
    using Literal = StructureType::Literal;

    ASSERT_EQ(Literal::Undefined, to_literal(to_string(Literal::Undefined)));
    ASSERT_EQ(Literal::Table, to_literal(to_string(Literal::Table)));
    ASSERT_EQ(Literal::Document, to_literal(to_string(Literal::Document)));
}

TEST(PrimitivesTest, StructureRenameType)
{
    using namespace StructureRenameType;
    using Literal = StructureRenameType::Literal;

    ASSERT_EQ(Literal::Undefined, to_literal(to_string(Literal::Undefined)));
    ASSERT_EQ(Literal::Structure, to_literal(to_string(Literal::Structure)));
    ASSERT_EQ(Literal::Field, to_literal(to_string(Literal::Field)));
    ASSERT_EQ(Literal::Database, to_literal(to_string(Literal::Database)));
}

TEST(PrimitivesTest, DatabaseOperationType)
{
    using namespace DatabaseOperationType;
    using Literal = DatabaseOperationType::Literal;

    ASSERT_EQ(Literal::Undefined, to_literal(to_string(Literal::Undefined)));
    ASSERT_EQ(Literal::Create, to_literal(to_string(Literal::Create)));
    ASSERT_EQ(Literal::Drop, to_literal(to_string(Literal::Drop)));
    ASSERT_EQ(Literal::Backup, to_literal(to_string(Literal::Backup)));
}

TEST(PrimitivesTest, DataType)
{
    using namespace DataType;
    using Literal = DataType::Literal;

    ASSERT_EQ(Literal::Undefined, to_literal(to_string(Literal::Undefined)));
    ASSERT_EQ(Literal::String, to_literal(to_string(Literal::String)));
    ASSERT_EQ(Literal::Boolean, to_literal(to_string(Literal::Boolean)));
    ASSERT_EQ(Literal::Decimal, to_literal(to_string(Literal::Decimal)));
    ASSERT_EQ(Literal::Integer, to_literal(to_string(Literal::Integer)));
    ASSERT_EQ(Literal::DateTime, to_literal(to_string(Literal::DateTime)));
    ASSERT_EQ(Literal::Reference, to_literal(to_string(Literal::Reference)));
}

TEST(PrimitivesTest, SelectSortType)
{
    using namespace SelectSortType;
    using Literal = SelectSortType::Literal;

    ASSERT_EQ(Literal::Undefined, to_literal(to_string(Literal::Undefined)));
    ASSERT_EQ(Literal::Asc, to_literal(to_string(Literal::Asc)));
    ASSERT_EQ(Literal::Desc, to_literal(to_string(Literal::Desc)));
}

TEST(PrimitivesTest, QueryType)
{
    using namespace QueryType;
    using Literal = QueryType::Literal;

    ASSERT_EQ(Literal::Undefined, to_literal(to_string(Literal::Undefined)));
    ASSERT_EQ(Literal::Schema, to_literal(to_string(Literal::Schema)));
    ASSERT_EQ(Literal::Create, to_literal(to_string(Literal::Create)));
    ASSERT_EQ(Literal::Migrate, to_literal(to_string(Literal::Migrate)));
    ASSERT_EQ(Literal::Drop, to_literal(to_string(Literal::Drop)));
    ASSERT_EQ(Literal::Delete, to_literal(to_string(Literal::Delete)));
    ASSERT_EQ(Literal::Update, to_literal(to_string(Literal::Update)));
    ASSERT_EQ(Literal::Database, to_literal(to_string(Literal::Database)));
    ASSERT_EQ(Literal::Rename, to_literal(to_string(Literal::Rename)));
    ASSERT_EQ(Literal::Select, to_literal(to_string(Literal::Select)));
    ASSERT_EQ(Literal::Insert, to_literal(to_string(Literal::Insert)));
    ASSERT_EQ(Literal::Index, to_literal(to_string(Literal::Index)));
    ASSERT_EQ(Literal::View, to_literal(to_string(Literal::View)));
}

} // namespace Moonlight::Primitives
