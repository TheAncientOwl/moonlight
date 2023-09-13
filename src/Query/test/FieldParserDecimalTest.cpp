#include <gtest/gtest.h>

#include "../src/common/SchemaFieldParsers.hpp"

#include "helpers/ParsedQueriesInit.hpp"
#include "helpers/ParsedQueriesCompare.hpp"

namespace Moonlight::QueryParser::Implementation::FieldParsers::Tests {

using namespace ParsedQuery;
using namespace std::literals;

TEST(FieldParserDecimalTest, parseSuccess01)
{
    const auto field = "some_field is Decimal[8] @default(14.29)";
    DecimalFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Decimal)
        .size(8)
        .metadata("14.29")
        .nullable(false);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDecimalTest, parseSuccess02)
{
    const auto field = "some_field is Decimal[16] @default(14.29)";
    DecimalFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Decimal)
        .size(16)
        .metadata("14.29")
        .nullable(false);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDecimalTest, parseSuccess03)
{
    const auto field = "some_field is Decimal[32] @default(14.29)";
    DecimalFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Decimal)
        .size(32)
        .metadata("14.29")
        .nullable(false);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDecimalTest, parseSuccess04)
{
    const auto field = "some_field is Decimal[64] @default(14.29)";
    DecimalFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Decimal)
        .size(64)
        .metadata("14.29")
        .nullable(false);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDecimalTest, parseSuccess05)
{
    const auto field = "some_field is Decimal?[8] @default(14.29)";
    DecimalFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Decimal)
        .size(8)
        .metadata("14.29")
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDecimalTest, parseSuccess06)
{
    const auto field = "some_field is Decimal?[16] @default(14.29)";
    DecimalFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Decimal)
        .size(16)
        .metadata("14.29")
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDecimalTest, parseSuccess07)
{
    const auto field = "some_field is Decimal?[32] @default(14.29)";
    DecimalFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Decimal)
        .size(32)
        .metadata("14.29")
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDecimalTest, parseSuccess08)
{
    const auto field = "some_field is Decimal?[64] @default(14.29)";
    DecimalFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Decimal)
        .size(64)
        .metadata("14.29")
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDecimalTest, parseSuccess09)
{
    const auto field = "some_field is Decimal?[8] @default(null)";
    DecimalFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Decimal)
        .size(8)
        .metadata(std::nullopt)
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDecimalTest, parseSuccess10)
{
    const auto field = "some_field is Decimal?[16] @default(null)";
    DecimalFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Decimal)
        .size(16)
        .metadata(std::nullopt)
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDecimalTest, parseSuccess11)
{
    const auto field = "some_field is Decimal?[32] @default(null)";
    DecimalFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Decimal)
        .size(32)
        .metadata(std::nullopt)
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDecimalTest, parseSuccess12)
{
    const auto field = "some_field is Decimal?[64] @default(null)";
    DecimalFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Decimal)
        .size(64)
        .metadata(std::nullopt)
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDecimalTest, parseSuccess13)
{
    const auto field = "some_field is Decimal[8] @default(-14.29)";
    DecimalFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Decimal)
        .size(8)
        .metadata("-14.29")
        .nullable(false);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDecimalTest, parseSuccess14)
{
    const auto field = "some_field is ArrayOf<Decimal[8]> @default(14.29)";
    DecimalFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Decimal)
        .size(8)
        .metadata("14.29")
        .nullable(false)
        .array(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDecimalTest, parseSuccess15)
{
    const auto field = "some_field is ArrayOf<Decimal?[8]> @default(14.29)";
    DecimalFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Decimal)
        .size(8)
        .metadata("14.29")
        .nullable(true)
        .array(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDecimalTest, noParseSuccess01)
{
    const auto field = "some_field is Decimal[128] @default(14.29)";
    DecimalFieldParser parser{};

    EXPECT_FALSE(parser.match(field));
}

TEST(FieldParserDecimalTest, noParseSuccess02)
{
    const auto field = "some_field is Decimal[32] @default()";
    DecimalFieldParser parser{};

    EXPECT_FALSE(parser.match(field));
}

TEST(FieldParserDecimalTest, noParseSuccess03)
{
    const auto field = "some_field is Decimal[32] @default(056)";
    DecimalFieldParser parser{};

    EXPECT_FALSE(parser.match(field));
}

TEST(FieldParserDecimalTest, noParseSuccess04)
{
    const auto field = "some_field is Decimal[32] @default(--23)";
    DecimalFieldParser parser{};

    EXPECT_FALSE(parser.match(field));
}

TEST(FieldParserDecimalTest, parseThrow01)
{
    const auto field = "some_field is Decimal[8] @default(null)";
    DecimalFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    EXPECT_THROW({ parser.parse(); }, std::runtime_error);
}

} // namespace Moonlight::QueryParser::Implementation::FieldParsers::Tests
