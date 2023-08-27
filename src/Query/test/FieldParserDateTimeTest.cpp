#include <gtest/gtest.h>

#include "Parsers/SchemaFieldParsers.hpp"

#include "helpers/QueryDataInit.hpp"
#include "helpers/QueryDataEquals.hpp"

namespace Moonlight::QueryParser::Implementation::FieldParsers::Tests {

using namespace QueryData;
using namespace std::literals;

TEST(FieldParserDateTimeTest, parseSuccess01)
{
    const auto query = "some_field is DateTime @default(now)";
    DateTimeFieldParser parser{};

    EXPECT_TRUE(parser.match(query));

    const auto out = parser.parse();

    const QueryData::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::DateTime)
        .metadata("now")
        .size(std::nullopt)
        .nullable(false);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDateTimeTest, parseSuccess02)
{
    const auto query = "some_field is DateTime @default(22/29/2023)";
    DateTimeFieldParser parser{};

    EXPECT_TRUE(parser.match(query));

    const auto out = parser.parse();

    const QueryData::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::DateTime)
        .metadata("22/29/2023")
        .size(std::nullopt)
        .nullable(false);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDateTimeTest, parseSuccess03)
{
    const auto query = "some_field is DateTime @default(22.29.2023)";
    DateTimeFieldParser parser{};

    EXPECT_TRUE(parser.match(query));

    const auto out = parser.parse();

    const QueryData::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::DateTime)
        .metadata("22.29.2023")
        .size(std::nullopt)
        .nullable(false);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDateTimeTest, parseSuccess04)
{
    const auto query = "some_field is DateTime @default(22-29-2023)";
    DateTimeFieldParser parser{};

    EXPECT_TRUE(parser.match(query));

    const auto out = parser.parse();

    const QueryData::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::DateTime)
        .metadata("22-29-2023")
        .size(std::nullopt)
        .nullable(false);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDateTimeTest, parseSuccess05)
{
    const auto query = "some_field is DateTime? @default(now)";
    DateTimeFieldParser parser{};

    EXPECT_TRUE(parser.match(query));

    const auto out = parser.parse();

    const QueryData::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::DateTime)
        .metadata("now")
        .size(std::nullopt)
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDateTimeTest, parseSuccess06)
{
    const auto query = "some_field is DateTime? @default(null)";
    DateTimeFieldParser parser{};

    EXPECT_TRUE(parser.match(query));

    const auto out = parser.parse();

    const QueryData::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::DateTime)
        .metadata(std::nullopt)
        .size(std::nullopt)
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDateTimeTest, parseSuccess07)
{
    const auto query = "some_field is ArrayOf<DateTime> @default(now)";
    DateTimeFieldParser parser{};

    EXPECT_TRUE(parser.match(query));

    const auto out = parser.parse();

    const QueryData::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::DateTime)
        .metadata("now")
        .size(std::nullopt)
        .nullable(false)
        .array(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDateTimeTest, parseSuccess08)
{
    const auto query = "some_field is ArrayOf<DateTime?> @default(now)";
    DateTimeFieldParser parser{};

    EXPECT_TRUE(parser.match(query));

    const auto out = parser.parse();

    const QueryData::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::DateTime)
        .metadata("now")
        .size(std::nullopt)
        .nullable(true)
        .array(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserDateTimeTest, noParseSuccess01)
{
    const auto query = R"(some_field is DateTime @default("09/10/2000"))";
    DateTimeFieldParser parser{};

    EXPECT_FALSE(parser.match(query));
}

TEST(FieldParserDateTimeTest, noParseSuccess02)
{
    const auto query = "(some_field is DateTime @default(something))";
    DateTimeFieldParser parser{};

    EXPECT_FALSE(parser.match(query));
}

TEST(FieldParserDateTimeTest, noParseSuccess03)
{
    const auto query = "(some_field is DateTime @default())";
    DateTimeFieldParser parser{};

    EXPECT_FALSE(parser.match(query));
}

TEST(FieldParserDateTimeTest, parseThrow01)
{
    const auto query = "some_field is DateTime @default(null)";
    DateTimeFieldParser parser{};

    EXPECT_TRUE(parser.match(query));

    EXPECT_THROW({ parser.parse(); }, std::runtime_error);
}

} // namespace Moonlight::QueryParser::Implementation::FieldParsers::Tests
