#include <gtest/gtest.h>

#include "Parsers/SchemaFieldParsers.hpp"

#include "helpers/QueryDataInit.hpp"
#include "helpers/QueryDataEquals.hpp"

namespace Moonlight::QueryParser::Implementation::FieldParsers::Tests {

using namespace QueryData;
using namespace std::literals;

TEST(FieldParserStringTest, parseSuccess01)
{
    const auto field = R"(some_field is String[15] @default("empty"))";
    StringFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const QueryData::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::String)
        .size(15)
        .metadata(R"("empty")")
        .nullable(false);
}

TEST(FieldParserStringTest, parseSuccess02)
{
    const auto field = R"(some_field is String[15] @default("emp\"ty"))";
    StringFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const QueryData::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::String)
        .size(15)
        .metadata(R"("emp\"ty")")
        .nullable(false);
}

TEST(FieldParserStringTest, parseSuccess03)
{
    const auto field = R"(some_field is String[15] @default("emp;ty"))";
    StringFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const QueryData::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::String)
        .size(15)
        .metadata(R"("emp;ty")")
        .nullable(false);
}

TEST(FieldParserStringTest, parseSuccess04)
{
    const auto field = R"(some_field is String[15] @default("null"))";
    StringFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const QueryData::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::String)
        .size(15)
        .metadata(R"("null")")
        .nullable(false);
}

TEST(FieldParserStringTest, parseSuccess05)
{
    const auto field = R"(some_field is String?[15] @default(null))";
    StringFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const QueryData::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::String)
        .size(15)
        .metadata(std::nullopt)
        .nullable(false);
}

TEST(FieldParserStringTest, parseSuccess06)
{
    const auto field = R"(some_field is String?[15] @default("empty"))";
    StringFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const QueryData::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::String)
        .size(15)
        .metadata(R"("empty")")
        .nullable(true);
}

TEST(FieldParserStringTest, parseSuccess07)
{
    const auto field = R"(some_field is String [  15   ] @default (  "empty"  ))";
    StringFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const QueryData::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::String)
        .size(15)
        .metadata(R"("empty")")
        .nullable(false);
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

} // namespace Moonlight::QueryParser::Implementation::FieldParsers::Tests