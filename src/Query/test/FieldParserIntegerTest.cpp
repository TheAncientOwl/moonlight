#include <gtest/gtest.h>

#include "../src/common/SchemaFieldParsers.hpp"

#include "helpers/ParsedQueriesInit.hpp"
#include "helpers/ParsedQueriesCompare.hpp"

namespace Moonlight::QueryParser::Implementation::FieldParsers::Tests {

using namespace ParsedQuery;
using namespace std::literals;

TEST(FieldParserIntegerTest, parseSuccess01)
{
    const auto field = "some_field is Integer[8] @default(14)";
    IntegerFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Integer)
        .size(8)
        .metadata("14")
        .nullable(false);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserIntegerTest, parseSuccess02)
{
    const auto field = "some_field is Integer[16] @default(14)";
    IntegerFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Integer)
        .size(16)
        .metadata("14")
        .nullable(false);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserIntegerTest, parseSuccess03)
{
    const auto field = "some_field is Integer[32] @default(14)";
    IntegerFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Integer)
        .size(32)
        .metadata("14")
        .nullable(false);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserIntegerTest, parseSuccess04)
{
    const auto field = "some_field is Integer[64] @default(14)";
    IntegerFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Integer)
        .size(64)
        .metadata("14")
        .nullable(false);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserIntegerTest, parseSuccess05)
{
    const auto field = "some_field is Integer?[8] @default(14)";
    IntegerFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Integer)
        .size(8)
        .metadata("14")
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserIntegerTest, parseSuccess06)
{
    const auto field = "some_field is Integer?[16] @default(14)";
    IntegerFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Integer)
        .size(16)
        .metadata("14")
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserIntegerTest, parseSuccess07)
{
    const auto field = "some_field is Integer?[32] @default(14)";
    IntegerFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Integer)
        .size(32)
        .metadata("14")
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserIntegerTest, parseSuccess08)
{
    const auto field = "some_field is Integer?[64] @default(14)";
    IntegerFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Integer)
        .size(64)
        .metadata("14")
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserIntegerTest, parseSuccess09)
{
    const auto field = "some_field is Integer?[8] @default(null)";
    IntegerFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Integer)
        .size(8)
        .metadata(std::nullopt)
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserIntegerTest, parseSuccess10)
{
    const auto field = "some_field is Integer?[16] @default(null)";
    IntegerFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Integer)
        .size(16)
        .metadata(std::nullopt)
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserIntegerTest, parseSuccess11)
{
    const auto field = "some_field is Integer?[32] @default(null)";
    IntegerFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Integer)
        .size(32)
        .metadata(std::nullopt)
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserIntegerTest, parseSuccess12)
{
    const auto field = "some_field is Integer?[64] @default(null)";
    IntegerFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Integer)
        .size(64)
        .metadata(std::nullopt)
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserIntegerTest, parseSuccess13)
{
    const auto field = "some_field is Integer[8] @default(-14)";
    IntegerFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Integer)
        .size(8)
        .metadata("-14")
        .nullable(false);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserIntegerTest, parseSuccess14)
{
    const auto field = "some_field is ArrayOf<Integer[8]> @default(14)";
    IntegerFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Integer)
        .size(8)
        .metadata("14")
        .nullable(false)
        .array(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserIntegerTest, parseSuccess15)
{
    const auto field = "some_field is ArrayOf<Integer?[8]> @default(14)";
    IntegerFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Integer)
        .size(8)
        .metadata("14")
        .nullable(true)
        .array(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserIntegerTest, noParseSuccess01)
{
    const auto field = "some_field is Integer[128] @default(14)";
    IntegerFieldParser parser{};

    EXPECT_FALSE(parser.match(field));
}

TEST(FieldParserIntegerTest, noParseSuccess02)
{
    const auto field = "some_field is Integer[32] @default()";
    IntegerFieldParser parser{};

    EXPECT_FALSE(parser.match(field));
}

TEST(FieldParserIntegerTest, noParseSuccess03)
{
    const auto field = "some_field is Integer[32] @default(056)";
    IntegerFieldParser parser{};

    EXPECT_FALSE(parser.match(field));
}

TEST(FieldParserIntegerTest, noParseSuccess04)
{
    const auto field = "some_field is Integer[32] @default(--23)";
    IntegerFieldParser parser{};

    EXPECT_FALSE(parser.match(field));
}

TEST(FieldParserIntegerTest, parseThrow01)
{
    const auto field = "some_field is Integer[8] @default(null)";
    IntegerFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    EXPECT_THROW({ parser.parse(); }, std::runtime_error);
}

} // namespace Moonlight::QueryParser::Implementation::FieldParsers::Tests
