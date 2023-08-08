#include <gtest/gtest.h>

#include "Primitives.hpp"

namespace Moonlight::Primitives {

TEST(MoonlightPrimitivesTest, StructureType)
{
    using namespace StructureType;
    using Literal = StructureType::Literal;

    ASSERT_EQ(Literal::Undefined, parse(parse(Literal::Undefined)));
    ASSERT_EQ(Literal::Table, parse(parse(Literal::Table)));
    ASSERT_EQ(Literal::Document, parse(parse(Literal::Document)));
}

TEST(MoonlightPrimitivesTest, StructureRenameType)
{
    using namespace StructureRenameType;
    using Literal = StructureRenameType::Literal;

    ASSERT_EQ(Literal::Undefined, parse(parse(Literal::Undefined)));
    ASSERT_EQ(Literal::Structure, parse(parse(Literal::Structure)));
    ASSERT_EQ(Literal::Field, parse(parse(Literal::Field)));
}


TEST(MoonlightPrimitivesTest, DatabaseOperationType)
{
    using namespace DatabaseOperationType;
    using Literal = DatabaseOperationType::Literal;

    ASSERT_EQ(Literal::Undefined, parse(parse(Literal::Undefined)));
    ASSERT_EQ(Literal::Create, parse(parse(Literal::Create)));
    ASSERT_EQ(Literal::Drop, parse(parse(Literal::Drop)));
    ASSERT_EQ(Literal::Backup, parse(parse(Literal::Backup)));
}

TEST(MoonlightPrimitivesTest, DataType)
{
    using namespace DataType;
    using Literal = DataType::Literal;

    ASSERT_EQ(Literal::Undefined, parse(parse(Literal::Undefined)));
    ASSERT_EQ(Literal::String, parse(parse(Literal::String)));
    ASSERT_EQ(Literal::Decimal, parse(parse(Literal::Decimal)));
    ASSERT_EQ(Literal::Integer, parse(parse(Literal::Integer)));
    ASSERT_EQ(Literal::DateTime, parse(parse(Literal::DateTime)));
    ASSERT_EQ(Literal::Reference, parse(parse(Literal::Reference)));
}

TEST(MoonlightPrimitivesTest, SelectSortType)
{
    using namespace SelectSortType;
    using Literal = SelectSortType::Literal;

    ASSERT_EQ(Literal::Undefined, parse(parse(Literal::Undefined)));
    ASSERT_EQ(Literal::Asc, parse(parse(Literal::Asc)));
    ASSERT_EQ(Literal::Desc, parse(parse(Literal::Desc)));
}

} // namespace Moonlight::Primitives
