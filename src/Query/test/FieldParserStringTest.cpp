#include <gtest/gtest.h>

#include "../src/common/SchemaFieldParsers.hpp"

#include "helpers/ParsedQueriesInit.hpp"
#include "helpers/ParsedQueriesCompare.hpp"

namespace Moonlight::Parser::Implementation::FieldParsers::Tests {

using namespace Objects;
using namespace Objects::Init;
using namespace std::literals;

TEST(FieldParserStringTest, parseSuccess01)
{
    const auto field = R"(some_field is String[15] @default("empty"))";
    StringFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const Field expected = FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::String)
        .size(15)
        .metadata(R"("empty")")
        .nullable(false);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserStringTest, parseSuccess02)
{
    const auto field = R"(some_field is String[15] @default("emp\"ty"))";
    StringFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const Field expected = FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::String)
        .size(15)
        .metadata(R"("emp\"ty")")
        .nullable(false);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserStringTest, parseSuccess03)
{
    const auto field = R"(some_field is String[15] @default("emp;ty"))";
    StringFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const Field expected = FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::String)
        .size(15)
        .metadata(R"("emp;ty")")
        .nullable(false);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserStringTest, parseSuccess04)
{
    const auto field = R"(some_field is String[15] @default("null"))";
    StringFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const Field expected = FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::String)
        .size(15)
        .metadata(R"("null")")
        .nullable(false);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserStringTest, parseSuccess05)
{
    const auto field = R"(some_field is String?[15] @default(null))";
    StringFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const Field expected = FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::String)
        .size(15)
        .metadata(std::nullopt)
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserStringTest, parseSuccess06)
{
    const auto field = R"(some_field is String?[15] @default("empty"))";
    StringFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const Field expected = FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::String)
        .size(15)
        .metadata(R"("empty")")
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserStringTest, parseSuccess07)
{
    const auto field = R"(some_field is String [  15   ] @default (  "empty"  ))";
    StringFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const Field expected = FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::String)
        .size(15)
        .metadata(R"("empty")")
        .nullable(false);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserStringTest, parseSuccess08)
{
    const auto field = R"(some_field is ArrayOf<String[15]> @default("empty"))";
    StringFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const Field expected = FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::String)
        .size(15)
        .metadata(R"("empty")")
        .nullable(false)
        .array(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserStringTest, parseSuccess09)
{
    const auto field = R"(some_field is ArrayOf<String?[15]> @default("empty"))";
    StringFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const Field expected = FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::String)
        .size(15)
        .metadata(R"("empty")")
        .nullable(true)
        .array(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserStringTest, noParseSuccess01)
{
    const auto field = R"(some_field is String[015] @default("empty"))";
    StringFieldParser parser{};

    EXPECT_FALSE(parser.match(field));
}

TEST(FieldParserStringTest, noParseSuccess02)
{
    const auto field = R"(some field is String[15] @default("empty"))";
    StringFieldParser parser{};

    EXPECT_FALSE(parser.match(field));
}

TEST(FieldParserStringTest, noParseSuccess03)
{
    const auto field = R"(some_field is String[15] @default())";
    StringFieldParser parser{};

    EXPECT_FALSE(parser.match(field));
}

TEST(FieldParserStringTest, noParseSuccess04)
{
    const auto field = R"(some_field is String[15] @default(""))";
    StringFieldParser parser{};

    EXPECT_FALSE(parser.match(field));
}

TEST(FieldParserStringTest, parseThrow01)
{
    const auto field = R"(some_field is String[9999999999999999999999] @default("empty"))";
    StringFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    EXPECT_THROW({ parser.parse(); }, std::runtime_error);
}

TEST(FieldParserStringTest, parseThrow02)
{
    const auto field = R"(some_field is String[15] @default(null))";
    StringFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    EXPECT_THROW({ parser.parse(); }, std::runtime_error);
}

} // namespace Moonlight::Parser::Implementation::FieldParsers::Tests
