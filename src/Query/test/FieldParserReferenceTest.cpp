#include <gtest/gtest.h>

#include "../src/helpers/SchemaFieldParsers.hpp"

#include "helpers/ParsedQueriesInit.hpp"
#include "helpers/ParsedQueriesCompare.hpp"

namespace Moonlight::QueryParser::Implementation::FieldParsers::Tests {

using namespace ParsedQuery;
using namespace std::literals;

TEST(FieldParserReferenceTest, parseSuccess01)
{
    const auto query = "some_field is Reference @of(OtherSchemaName)";
    ReferenceFieldParser parser{};

    ASSERT_TRUE(parser.match(query));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Reference)
        .size(std::nullopt)
        .metadata(std::nullopt)
        .metadata("OtherSchemaName")
        .nullable(false);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserReferenceTest, parseSuccess02)
{
    const auto query = "some_field is Reference? @of(OtherSchemaName)";
    ReferenceFieldParser parser{};

    ASSERT_TRUE(parser.match(query));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Reference)
        .size(std::nullopt)
        .metadata(std::nullopt)
        .metadata("OtherSchemaName")
        .nullable(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserReferenceTest, parseSuccess03)
{
    const auto query = "some_field is ArrayOf<Reference> @of(OtherSchemaName)";
    ReferenceFieldParser parser{};

    ASSERT_TRUE(parser.match(query));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Reference)
        .size(std::nullopt)
        .metadata(std::nullopt)
        .metadata("OtherSchemaName")
        .nullable(false)
        .array(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserReferenceTest, parseSuccess04)
{
    const auto query = "some_field is ArrayOf<Reference?> @of(OtherSchemaName)";
    ReferenceFieldParser parser{};

    ASSERT_TRUE(parser.match(query));

    const auto out = parser.parse();

    const ParsedQuery::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Reference)
        .size(std::nullopt)
        .metadata(std::nullopt)
        .metadata("OtherSchemaName")
        .nullable(true)
        .array(true);

    EXPECT_SCHEMA_FIELD_EQ(out, expected);
}

TEST(FieldParserReferenceTest, noParseSuccess01)
{
    const auto query = "some_field is Reference @of()";
    ReferenceFieldParser parser{};

    ASSERT_FALSE(parser.match(query));
}

TEST(FieldParserReferenceTest, parseThrow01)
{
    // Cannot throw
}

} // namespace Moonlight::QueryParser::Implementation::FieldParsers::Tests
