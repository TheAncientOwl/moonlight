#include <gtest/gtest.h>

#include "Parsers/SchemaFieldParsers.hpp"

#include "helpers/QueryDataInit.hpp"
#include "helpers/QueryDataEquals.hpp"

namespace Moonlight::QueryParser::Implementation::FieldParsers::Tests {

using namespace QueryData;
using namespace std::literals;

TEST(FieldParserReferenceTest, parseSuccess01)
{
    const auto query = "some_field is Reference @of(OtherSchemaName)";
    ReferenceFieldParser parser{};

    ASSERT_TRUE(parser.match(query));

    const auto out = parser.parse();

    const QueryData::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Reference)
        .size(std::nullopt)
        .metadata(std::nullopt)
        .metadata("OtherSchemaName")
        .nullable(false);
}

TEST(FieldParserReferenceTest, parseSuccess02)
{
    const auto query = "some_field is ?Reference @of(OtherSchemaName)";
    ReferenceFieldParser parser{};

    ASSERT_TRUE(parser.match(query));

    const auto out = parser.parse();

    const QueryData::Field expected = Init::FieldInit{}
        .name("some_field")
        .data_type(Primitives::EDataType::Reference)
        .size(std::nullopt)
        .metadata(std::nullopt)
        .metadata("OtherSchemaName")
        .nullable(true);
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
