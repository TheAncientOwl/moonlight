#include <gtest/gtest.h>

#include "Primitives.hpp"

namespace Moonlight::Primitives {

TEST(MoonlightPrimitivesTest, StructureType)
{
    using namespace StructureType;
    using Literal = StructureType::Literal;

    ASSERT_EQ(Literal::Undefined, to_literal(to_string(Literal::Undefined)));
    ASSERT_EQ(Literal::Table, to_literal(to_string(Literal::Table)));
    ASSERT_EQ(Literal::Document, to_literal(to_string(Literal::Document)));
}

TEST(MoonlightPrimitivesTest, StructureRenameType)
{
    using namespace StructureRenameType;
    using Literal = StructureRenameType::Literal;

    ASSERT_EQ(Literal::Undefined, to_literal(to_string(Literal::Undefined)));
    ASSERT_EQ(Literal::Structure, to_literal(to_string(Literal::Structure)));
    ASSERT_EQ(Literal::Field, to_literal(to_string(Literal::Field)));
}


TEST(MoonlightPrimitivesTest, DatabaseOperationType)
{
    using namespace DatabaseOperationType;
    using Literal = DatabaseOperationType::Literal;

    ASSERT_EQ(Literal::Undefined, to_literal(to_string(Literal::Undefined)));
    ASSERT_EQ(Literal::Create, to_literal(to_string(Literal::Create)));
    ASSERT_EQ(Literal::Drop, to_literal(to_string(Literal::Drop)));
    ASSERT_EQ(Literal::Backup, to_literal(to_string(Literal::Backup)));
}

TEST(MoonlightPrimitivesTest, DataType)
{
    using namespace DataType;
    using Literal = DataType::Literal;

    ASSERT_EQ(Literal::Undefined, to_literal(to_string(Literal::Undefined)));
    ASSERT_EQ(Literal::String, to_literal(to_string(Literal::String)));
    ASSERT_EQ(Literal::Decimal, to_literal(to_string(Literal::Decimal)));
    ASSERT_EQ(Literal::Integer, to_literal(to_string(Literal::Integer)));
    ASSERT_EQ(Literal::DateTime, to_literal(to_string(Literal::DateTime)));
    ASSERT_EQ(Literal::Reference, to_literal(to_string(Literal::Reference)));
}

TEST(MoonlightPrimitivesTest, SelectSortType)
{
    using namespace SelectSortType;
    using Literal = SelectSortType::Literal;

    ASSERT_EQ(Literal::Undefined, to_literal(to_string(Literal::Undefined)));
    ASSERT_EQ(Literal::Asc, to_literal(to_string(Literal::Asc)));
    ASSERT_EQ(Literal::Desc, to_literal(to_string(Literal::Desc)));
}

} // namespace Moonlight::Primitives
