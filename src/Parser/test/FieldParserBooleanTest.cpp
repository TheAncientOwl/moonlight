#include <gtest/gtest.h>

#include "../src/common/FieldParsers.hpp"

#include "helpers/ObjectsInit.hpp"
#include "helpers/ObjectsCompare.hpp"

namespace Moonlight::Parser::Implementation::FieldParsers::Tests {

using namespace Objects;
using namespace Objects::Init;
using namespace std::literals;

TEST(FieldParserBooleanTest, parseSuccess01)
{
    const auto field = "some_field is Boolean @default(false)";
    BooleanFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const Field expected = FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Boolean)
        .metadata("false")
        .size(std::nullopt)
        .nullable(false);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserBooleanTest, parseSuccess02)
{
    const auto field = "some_field is Boolean @default(true)";

    BooleanFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const Field expected = FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Boolean)
        .metadata("true")
        .size(std::nullopt)
        .nullable(false);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserBooleanTest, parseSuccess03)
{
    const auto field = "some_field is Boolean? @default(false)";

    BooleanFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const Field expected = FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Boolean)
        .metadata("false")
        .size(std::nullopt)
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserBooleanTest, parseSuccess04)
{
    const auto field = "some_field is Boolean? @default(true)";

    BooleanFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const Field expected = FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Boolean)
        .metadata("true")
        .size(std::nullopt)
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserBooleanTest, parseSuccess05)
{
    const auto field = "some_field is Boolean? @default(null)";

    BooleanFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const Field expected = FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Boolean)
        .metadata(std::nullopt)
        .size(std::nullopt)
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserBooleanTest, parseSuccess06)
{
    const auto field = "some_field is ArrayOf<Boolean> @default(false)";
    BooleanFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const Field expected = FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Boolean)
        .metadata("false")
        .size(std::nullopt)
        .nullable(false)
        .array(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserBooleanTest, parseSuccess07)
{
    const auto field = "some_field is ArrayOf<Boolean?> @default(false)";
    BooleanFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    const auto out = parser.parse();

    const Field expected = FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Boolean)
        .metadata("false")
        .size(std::nullopt)
        .nullable(true)
        .array(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserBooleanTest, noParseSuccess01)
{
    const auto field = "some_field is Booolean @default(false)";
    BooleanFieldParser parser{};

    EXPECT_FALSE(parser.match(field));
}

TEST(FieldParserBooleanTest, noParseSuccess02)
{
    const auto field = "some_-field is Boolean @default(false)";
    BooleanFieldParser parser{};

    EXPECT_FALSE(parser.match(field));
}

TEST(FieldParserBooleanTest, noParseSuccess03)
{
    const auto field = "some field is Boolean @default(false)";
    BooleanFieldParser parser{};

    EXPECT_FALSE(parser.match(field));
}

TEST(FieldParserBooleanTest, noParseSuccess04)
{
    const auto field = "some_field is Boolean @default(maybe)";
    BooleanFieldParser parser{};

    EXPECT_FALSE(parser.match(field));
}

TEST(FieldParserBooleanTest, noParseSuccess05)
{
    const auto field = "some_field is Boolean @default()";
    BooleanFieldParser parser{};

    EXPECT_FALSE(parser.match(field));
}

TEST(FieldParserBooleanTest, noParseSuccess06)
{
    const auto field = "some_field Boolean @default(true)";
    BooleanFieldParser parser{};

    EXPECT_FALSE(parser.match(field));
}

TEST(FieldParserBooleanTest, noParseSuccess07)
{
    const auto field = "some_field is @default(true)";
    BooleanFieldParser parser{};

    EXPECT_FALSE(parser.match(field));
}

TEST(FieldParserBooleanTest, noParseSuccess08)
{
    const auto field = "some_field is Boolean (true)";
    BooleanFieldParser parser{};

    EXPECT_FALSE(parser.match(field));
}

TEST(FieldParserBooleanTest, parseSuccessThrow01)
{
    const auto field = "some_field is Boolean @default(null)";
    BooleanFieldParser parser{};

    EXPECT_TRUE(parser.match(field));

    EXPECT_THROW({ parser.parse(); }, std::runtime_error);
}

} // namespace Moonlight::Parser::Implementation::FieldParsers::Tests
