#include <gtest/gtest.h>

#include "QueryParser.hpp"
#include "helpers/ParsedQueriesInit.hpp"
#include "helpers/ParsedQueriesCompare.hpp"

namespace Moonlight::QueryParser::Implementation::Tests {

using namespace ParsedQuery;
using namespace std::literals;

using dtype = Primitives::EDataType;

TEST(SchemaParserTest, parseSuccess01)
{
    const auto query =
        "schema {"
        "name: SchemaName;"
        "inherits: [SchemaName1, SchemaName2];"
        " "
        "fields : ["
        "   field_11 is Boolean       @default(false),"
        "   field_12 is DateTime      @default(now),"
        R"( field_13 is String[15]    @default("empty"),)"
        "   field_14 is Integer[8]    @default(14),"
        "   field_15 is Decimal[8]    @default(3.14),"
        "   field_16 is Reference     @of(OtherSchemaName),"
        " "
        "   field_21 is Boolean?      @default(false),"
        "   field_22 is DateTime?     @default(now),"
        R"( field_23 is String?[15]   @default("empty"),)"
        "   field_24 is Integer?[8]   @default(14),"
        "   field_25 is Decimal?[8]   @default(3.14),"
        "   field_26 is Reference?    @of(OtherSchemaName),"
        " "
        "   field_31 is Boolean?      @default(null),"
        "   field_32 is DateTime?     @default(null),"
        "   field_33 is String?[15]   @default(null),"
        "   field_34 is Integer?[8]   @default(null),"
        "   field_35 is Decimal?[8]   @default(null),"
        "   field_36 is Reference?    @of(OtherSchemaName)"
        "];"
        " "
        "restrictions: ["
        R"(  field3 like "*@*.*",)"
        "    length(field3) = 13,"
        "    field1 unique,"
        "    field2 unique"
        "];"
        "};";

    const auto out = parseQuery(query).get<Schema>();

    const Schema expected = Init::SchemaInit{}
        .name("SchemaName")
        .inherits({ "SchemaName1", "SchemaName2" })
        .fields({
            Init::FieldInit{}.name("field_11").data_type(dtype::Boolean).metadata("false"),
            Init::FieldInit{}.name("field_12").data_type(dtype::DateTime).metadata("now"),
            Init::FieldInit{}.name("field_13").data_type(dtype::String).size(15).metadata(R"("empty")"),
            Init::FieldInit{}.name("field_14").data_type(dtype::Integer).size(8).metadata("14"),
            Init::FieldInit{}.name("field_15").data_type(dtype::Decimal).size(8).metadata("3.14"),
            Init::FieldInit{}.name("field_16").data_type(dtype::Reference).metadata("OtherSchemaName"),

            Init::FieldInit{}.name("field_21").data_type(dtype::Boolean).nullable(true).metadata("false"),
            Init::FieldInit{}.name("field_22").data_type(dtype::DateTime).nullable(true).metadata("now"),
            Init::FieldInit{}.name("field_23").data_type(dtype::String).size(15).nullable(true).metadata(R"("empty")"),
            Init::FieldInit{}.name("field_24").data_type(dtype::Integer).size(8).nullable(true).metadata("14"),
            Init::FieldInit{}.name("field_25").data_type(dtype::Decimal).size(8).nullable(true).metadata("3.14"),
            Init::FieldInit{}.name("field_26").data_type(dtype::Reference).nullable(true).metadata("OtherSchemaName"),

            Init::FieldInit{}.name("field_31").data_type(dtype::Boolean).nullable(true),
            Init::FieldInit{}.name("field_32").data_type(dtype::DateTime).nullable(true),
            Init::FieldInit{}.name("field_33").data_type(dtype::String).size(15).nullable(true),
            Init::FieldInit{}.name("field_34").data_type(dtype::Integer).size(8).nullable(true),
            Init::FieldInit{}.name("field_35").data_type(dtype::Decimal).size(8).nullable(true),
            Init::FieldInit{}.name("field_36").data_type(dtype::Reference).nullable(true).metadata("OtherSchemaName")
            })
        .restrictions({
                R"(field3 like "*@*.*")",
                "length(field3) = 13",
                "field1 unique",
                "field2 unique"
            });

    EXPECT_SCHEMA_EQ(out, expected);
}

TEST(SchemaParserTest, parseSuccess02)
{
    const auto query =
        "schema {"
        "name: SchemaName;"
        " "
        "fields : ["
        "   field_11 is Boolean       @default(false),"
        "   field_12 is DateTime      @default(now),"
        R"( field_13 is String[15]    @default("empty"),)"
        "   field_14 is Integer[8]    @default(14),"
        "   field_15 is Decimal[8]    @default(3.14),"
        "   field_16 is Reference     @of(OtherSchemaName),"
        " "
        "   field_21 is Boolean?      @default(false),"
        "   field_22 is DateTime?     @default(now),"
        R"( field_23 is String?[15]   @default("empty"),)"
        "   field_24 is Integer?[8]   @default(14),"
        "   field_25 is Decimal?[8]   @default(3.14),"
        "   field_26 is Reference?    @of(OtherSchemaName),"
        " "
        "   field_31 is Boolean?      @default(null),"
        "   field_32 is DateTime?     @default(null),"
        "   field_33 is String?[15]   @default(null),"
        "   field_34 is Integer?[8]   @default(null),"
        "   field_35 is Decimal?[8]   @default(null),"
        "   field_36 is Reference?    @of(OtherSchemaName)"
        "];"
        " "
        "restrictions: ["
        R"(  field3 like "*@*.*",)"
        "    length(field3) = 13,"
        "    field1 unique,"
        "    field2 unique"
        "];"
        "};";

    const auto out = parseQuery(query).get<Schema>();

    const Schema expected = Init::SchemaInit{}
        .name("SchemaName")
        .inherits({})
        .fields({
            Init::FieldInit{}.name("field_11").data_type(dtype::Boolean).metadata("false"),
            Init::FieldInit{}.name("field_12").data_type(dtype::DateTime).metadata("now"),
            Init::FieldInit{}.name("field_13").data_type(dtype::String).size(15).metadata(R"("empty")"),
            Init::FieldInit{}.name("field_14").data_type(dtype::Integer).size(8).metadata("14"),
            Init::FieldInit{}.name("field_15").data_type(dtype::Decimal).size(8).metadata("3.14"),
            Init::FieldInit{}.name("field_16").data_type(dtype::Reference).metadata("OtherSchemaName"),

            Init::FieldInit{}.name("field_21").data_type(dtype::Boolean).nullable(true).metadata("false"),
            Init::FieldInit{}.name("field_22").data_type(dtype::DateTime).nullable(true).metadata("now"),
            Init::FieldInit{}.name("field_23").data_type(dtype::String).size(15).nullable(true).metadata(R"("empty")"),
            Init::FieldInit{}.name("field_24").data_type(dtype::Integer).size(8).nullable(true).metadata("14"),
            Init::FieldInit{}.name("field_25").data_type(dtype::Decimal).size(8).nullable(true).metadata("3.14"),
            Init::FieldInit{}.name("field_26").data_type(dtype::Reference).nullable(true).metadata("OtherSchemaName"),

            Init::FieldInit{}.name("field_31").data_type(dtype::Boolean).nullable(true),
            Init::FieldInit{}.name("field_32").data_type(dtype::DateTime).nullable(true),
            Init::FieldInit{}.name("field_33").data_type(dtype::String).size(15).nullable(true),
            Init::FieldInit{}.name("field_34").data_type(dtype::Integer).size(8).nullable(true),
            Init::FieldInit{}.name("field_35").data_type(dtype::Decimal).size(8).nullable(true),
            Init::FieldInit{}.name("field_36").data_type(dtype::Reference).nullable(true).metadata("OtherSchemaName")
            })
        .restrictions({
                R"(field3 like "*@*.*")",
                "length(field3) = 13",
                "field1 unique",
                "field2 unique"
            });

    EXPECT_SCHEMA_EQ(out, expected);
}

TEST(SchemaParserTest, parseSuccess05)
{
    const auto query =
        "schema {"
        "name: SchemaName;"
        " "
        "fields : ["
        "   field_11 is Boolean       @default(false),"
        "   field_12 is DateTime      @default(now),"
        R"( field_13 is String[15]    @default("empty"),)"
        "   field_14 is Integer[8]    @default(14),"
        "   field_15 is Decimal[8]    @default(3.14),"
        "   field_16 is Reference     @of(OtherSchemaName),"
        " "
        "   field_21 is Boolean?      @default(false),"
        "   field_22 is DateTime?     @default(now),"
        R"( field_23 is String?[15]   @default("empty"),)"
        "   field_24 is Integer?[8]   @default(14),"
        "   field_25 is Decimal?[8]   @default(3.14),"
        "   field_26 is Reference?    @of(OtherSchemaName),"
        " "
        "   field_31 is Boolean?      @default(null),"
        "   field_32 is DateTime?     @default(null),"
        "   field_33 is String?[15]   @default(null),"
        "   field_34 is Integer?[8]   @default(null),"
        "   field_35 is Decimal?[8]   @default(null),"
        "   field_36 is Reference?    @of(OtherSchemaName)"
        "];"
        "};";

    const auto out = parseQuery(query).get<Schema>();

    const Schema expected = Init::SchemaInit{}
        .name("SchemaName")
        .inherits({})
        .fields({
            Init::FieldInit{}.name("field_11").data_type(dtype::Boolean).metadata("false"),
            Init::FieldInit{}.name("field_12").data_type(dtype::DateTime).metadata("now"),
            Init::FieldInit{}.name("field_13").data_type(dtype::String).size(15).metadata(R"("empty")"),
            Init::FieldInit{}.name("field_14").data_type(dtype::Integer).size(8).metadata("14"),
            Init::FieldInit{}.name("field_15").data_type(dtype::Decimal).size(8).metadata("3.14"),
            Init::FieldInit{}.name("field_16").data_type(dtype::Reference).metadata("OtherSchemaName"),

            Init::FieldInit{}.name("field_21").data_type(dtype::Boolean).nullable(true).metadata("false"),
            Init::FieldInit{}.name("field_22").data_type(dtype::DateTime).nullable(true).metadata("now"),
            Init::FieldInit{}.name("field_23").data_type(dtype::String).size(15).nullable(true).metadata(R"("empty")"),
            Init::FieldInit{}.name("field_24").data_type(dtype::Integer).size(8).nullable(true).metadata("14"),
            Init::FieldInit{}.name("field_25").data_type(dtype::Decimal).size(8).nullable(true).metadata("3.14"),
            Init::FieldInit{}.name("field_26").data_type(dtype::Reference).nullable(true).metadata("OtherSchemaName"),

            Init::FieldInit{}.name("field_31").data_type(dtype::Boolean).nullable(true),
            Init::FieldInit{}.name("field_32").data_type(dtype::DateTime).nullable(true),
            Init::FieldInit{}.name("field_33").data_type(dtype::String).size(15).nullable(true),
            Init::FieldInit{}.name("field_34").data_type(dtype::Integer).size(8).nullable(true),
            Init::FieldInit{}.name("field_35").data_type(dtype::Decimal).size(8).nullable(true),
            Init::FieldInit{}.name("field_36").data_type(dtype::Reference).nullable(true).metadata("OtherSchemaName")
            })
        .restrictions({});

    EXPECT_SCHEMA_EQ(out, expected);
}

TEST(SchemaParserTest, parseSuccess06)
{
    const auto query =
        "schema {"
        "name: SchemaName;"
        "inherits: [SchemaName1, SchemaName2];"
        " "
        "fields : ["
        "   field_11 is Boolean       @default(false),"
        "   field_12 is DateTime      @default(now),"
        R"( field_13 is String[15]    @default("em,pty"),)"
        "   field_14 is Integer[8]    @default(14),"
        "   field_15 is Decimal[8]    @default(3.14),"
        "   field_16 is Reference     @of(OtherSchemaName),"
        " "
        "   field_21 is Boolean?      @default(false),"
        "   field_22 is DateTime?     @default(now),"
        R"( field_23 is String?[15]   @default("em;pty"),)"
        "   field_24 is Integer?[8]   @default(14),"
        "   field_25 is Decimal?[8]   @default(3.14),"
        "   field_26 is Reference?    @of(OtherSchemaName),"
        " "
        "   field_31 is Boolean?      @default(null),"
        "   field_32 is DateTime?     @default(null),"
        "   field_33 is String?[15]   @default(null),"
        "   field_34 is Integer?[8]   @default(null),"
        "   field_35 is Decimal?[8]   @default(null),"
        "   field_36 is Reference?    @of(OtherSchemaName)"
        "];"
        " "
        "restrictions: ["
        R"(  field3 like "*@*.*",)"
        "    length(field3) = 13,"
        "    field1 unique,"
        "    field2 unique"
        "];"
        "};";

    const auto out = parseQuery(query).get<Schema>();

    const Schema expected = Init::SchemaInit{}
        .name("SchemaName")
        .inherits({ "SchemaName1", "SchemaName2" })
        .fields({
            Init::FieldInit{}.name("field_11").data_type(dtype::Boolean).metadata("false"),
            Init::FieldInit{}.name("field_12").data_type(dtype::DateTime).metadata("now"),
            Init::FieldInit{}.name("field_13").data_type(dtype::String).size(15).metadata(R"("em,pty")"),
            Init::FieldInit{}.name("field_14").data_type(dtype::Integer).size(8).metadata("14"),
            Init::FieldInit{}.name("field_15").data_type(dtype::Decimal).size(8).metadata("3.14"),
            Init::FieldInit{}.name("field_16").data_type(dtype::Reference).metadata("OtherSchemaName"),

            Init::FieldInit{}.name("field_21").data_type(dtype::Boolean).nullable(true).metadata("false"),
            Init::FieldInit{}.name("field_22").data_type(dtype::DateTime).nullable(true).metadata("now"),
            Init::FieldInit{}.name("field_23").data_type(dtype::String).size(15).nullable(true).metadata(R"("em;pty")"),
            Init::FieldInit{}.name("field_24").data_type(dtype::Integer).size(8).nullable(true).metadata("14"),
            Init::FieldInit{}.name("field_25").data_type(dtype::Decimal).size(8).nullable(true).metadata("3.14"),
            Init::FieldInit{}.name("field_26").data_type(dtype::Reference).nullable(true).metadata("OtherSchemaName"),

            Init::FieldInit{}.name("field_31").data_type(dtype::Boolean).nullable(true),
            Init::FieldInit{}.name("field_32").data_type(dtype::DateTime).nullable(true),
            Init::FieldInit{}.name("field_33").data_type(dtype::String).size(15).nullable(true),
            Init::FieldInit{}.name("field_34").data_type(dtype::Integer).size(8).nullable(true),
            Init::FieldInit{}.name("field_35").data_type(dtype::Decimal).size(8).nullable(true),
            Init::FieldInit{}.name("field_36").data_type(dtype::Reference).nullable(true).metadata("OtherSchemaName")
            })
        .restrictions({
                R"(field3 like "*@*.*")",
                "length(field3) = 13",
                "field1 unique",
                "field2 unique"
            });

    EXPECT_SCHEMA_EQ(out, expected);
}

TEST(SchemaParserTest, parseThrow01)
{
    const auto query =
        "schema {"
        "name: SchemaName;"
        "inherits: [Schema-Name1, SchemaName2];"
        " "
        "fields : ["
        "   field_11 is Boolean       @default(false),"
        "   field_12 is DateTime      @default(now),"
        R"( field_13 is String[15]    @default("empty"),)"
        "   field_14 is Integer[8]    @default(14),"
        "   field_15 is Decimal[8]    @default(3.14),"
        "   field_16 is Reference     @of(OtherSchemaName),"
        " "
        "   field_21 is Boolean?      @default(false),"
        "   field_22 is DateTime?     @default(now),"
        R"( field_23 is String?[15]   @default("empty"),)"
        "   field_24 is Integer?[8]   @default(14),"
        "   field_25 is Decimal?[8]   @default(3.14),"
        "   field_26 is Reference?    @of(OtherSchemaName),"
        " "
        "   field_31 is Boolean?      @default(null),"
        "   field_32 is DateTime?     @default(null),"
        "   field_33 is String?[15]   @default(null),"
        "   field_34 is Integer?[8]   @default(null),"
        "   field_35 is Decimal?[8]   @default(null),"
        "   field_36 is Reference?    @of(OtherSchemaName)"
        "];"
        " "
        "restrictions: ["
        R"(  field3 like "*@*.*",)"
        "    length(field3) = 13,"
        "    field1 unique,"
        "    field2 unique"
        "];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(SchemaParserTest, parseThrow02)
{
    const auto query =
        "schema {"
        "name: SchemaName;"
        "inherits: [SchemaName1, SchemaName2];"
        " "
        "fields : ["
        "];"
        " "
        "restrictions: ["
        R"(  field3 like "*@*.*",)"
        "    length(field3) = 13,"
        "    field1 unique,"
        "    field2 unique"
        "];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(SchemaParserTest, parseThrow03)
{
    const auto query =
        "schema {"
        "name: SchemaName;"
        "inherits: [];"
        " "
        "fields : ["
        "   field_11 is Boolean       @default(false),"
        "   field_12 is DateTime      @default(now),"
        R"( field_13 is String[15]    @default("empty"),)"
        "   field_14 is Integer[8]    @default(14),"
        "   field_15 is Decimal[8]    @default(3.14),"
        "   field_16 is Reference     @of(OtherSchemaName),"
        " "
        "   field_21 is Boolean?      @default(false),"
        "   field_22 is DateTime?     @default(now),"
        R"( field_23 is String?[15]   @default("empty"),)"
        "   field_24 is Integer?[8]   @default(14),"
        "   field_25 is Decimal?[8]   @default(3.14),"
        "   field_26 is Reference?    @of(OtherSchemaName),"
        " "
        "   field_31 is Boolean?      @default(null),"
        "   field_32 is DateTime?     @default(null),"
        "   field_33 is String?[15]   @default(null),"
        "   field_34 is Integer?[8]   @default(null),"
        "   field_35 is Decimal?[8]   @default(null),"
        "   field_36 is Reference?    @of(OtherSchemaName)"
        "];"
        " "
        "restrictions: ["
        R"(  field3 like "*@*.*",)"
        "    length(field3) = 13,"
        "    field1 unique,"
        "    field2 unique"
        "];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(SchemaParserTest, parseThrow04)
{
    const auto query =
        "schema {"
        "name: SchemaName;"
        "inherits: [SchemaName1, SchemaName2];"
        " "
        "fields : ["
        "   field_11 is Boolean       @default(false),"
        "   field_12 is DateTime      @default(now),"
        R"( field_13 is String[15]    @default("empty"),)"
        "   field_14 is Integer[8]    @default(14),"
        "   field_15 is Decimal[8]    @default(3.14),"
        "   field_16 is Reference     @of(OtherSchemaName),"
        " "
        "   field_21 is Boolean?      @default(false),"
        "   field_22 is DateTime?     @default(now),"
        R"( field_23 is String?[15]   @default("empty"),)"
        "   field_24 is Integer?[8]   @default(14),"
        "   field_25 is Decimal?[8]   @default(3.14),"
        "   field_26 is Reference?    @of(OtherSchemaName),"
        " "
        "   field_31 is Boolean?      @default(null),"
        "   field_32 is DateTime?     @default(null),"
        "   field_33 is String?[15]   @default(null),"
        "   field_34 is Integer?[8]   @default(null),"
        "   field_35 is Decimal?[8]   @default(null),"
        "   field_36 is Reference?    @of(OtherSchemaName)"
        "];"
        " "
        "restrictions: ["
        "];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(SchemaParserTest, parseThrow06)
{
    const auto query =
        "schema {"
        "name: SchemaName;"
        "inherits: [SchemaName1, SchemaName2];"
        " "
        "fields : ["
        "   field_11 is Boolean       @default(false),"
        "   field_12 is DateTime      @default(now),"
        R"( field_13 is String[15]    @default("empty"))"
        "   field_14 is Integer[8]    @default(14),"
        "   field_15 is Decimal[8]    @default(3.14),"
        "   field_16 is Reference     @of(OtherSchemaName),"
        " "
        "   field_21 is Boolean?      @default(false),"
        "   field_22 is DateTime?     @default(now),"
        R"( field_23 is String?[15]   @default("empty"),)"
        "   field_24 is Integer?[8]   @default(14),"
        "   field_25 is Decimal?[8]   @default(3.14),"
        "   field_26 is Reference?    @of(OtherSchemaName),"
        " "
        "   field_31 is Boolean?      @default(null),"
        "   field_32 is DateTime?     @default(null),"
        "   field_33 is String?[15]   @default(null),"
        "   field_34 is Integer?[8]   @default(null),"
        "   field_35 is Decimal?[8]   @default(null),"
        "   field_36 is Reference?    @of(OtherSchemaName)"
        "];"
        " "
        "restrictions: ["
        R"(  field3 like "*@*.*",)"
        "    length(field3) = 13,"
        "    field1 unique,"
        "    field2 unique"
        "];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

} // namespace Moonlight::QueryParser::Implementation::Tests
