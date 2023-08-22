#include <gtest/gtest.h>

#include "QueryParser.hpp"
#include "helpers/QueryDataInit.hpp"
#include "helpers/QueryDataEquals.hpp"

namespace Moonlight::QueryParser::Implementation::Tests {

using namespace QueryData;
using namespace std::literals;

TEST(SchemaParserTest, parseSuccess01)
{
    const auto query =
        "schema {"
        "name: SchemaName;"
        "inherits: [SchemaName1, SchemaName2];"
        " "
        "fields : ["
        "   field_11 is Boolean       @default(false),"
        "   field_12 is DateTime      @default(now()),"
        R"( field_13 is String[15]    @default("empty"),)"
        "   field_14 is Int[8]        @default(14),"
        "   field_15 is Float[8]      @default(3.14),"
        "   field_16 is Reference     @of(OtherSchemaName),"
        " "
        "   field_21 is ?Boolean      @default(false),"
        "   field_22 is ?DateTime     @default(now()),"
        R"( field_23 is ?String[15]   @default("empty"),)"
        "   field_24 is ?Int[8]       @default(14),"
        "   field_25 is ?Float[8]     @default(3.14),"
        "   field_26 is ?Reference    @of(OtherSchemaName),"
        " "
        "   field_31 is ?Boolean      @default(null),"
        "   field_32 is ?DateTime     @default(null),"
        "   field_33 is ?String[15]   @default(null),"
        "   field_34 is ?Int[8]       @default(null),"
        "   field_35 is ?Float[8]     @default(null),"
        "   field_36 is ?Reference    @of(OtherSchemaName)"
        "];"
        " "
        "checks: ["
        R"(  field3 like " * @ * .*",)"
        "    length(field3) = 13,"
        "] ;"
        " "
        "unique: [field1, field2] ;"
        "};";

    const auto out = parseQuery(query).get<Schema>();

    const Schema expected = Init::SchemaInit{}
        .name("SchemaName")
        .inherits({ "SchemaName1", "SchemaName2" });

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
        "   field_12 is DateTime      @default(now()),"
        R"( field_13 is String[15]    @default("empty"),)"
        "   field_14 is Int[8]        @default(14),"
        "   field_15 is Float[8]      @default(3.14),"
        "   field_16 is Reference     @of(OtherSchemaName),"
        " "
        "   field_21 is ?Boolean      @default(false),"
        "   field_22 is ?DateTime     @default(now()),"
        R"( field_23 is ?String[15]   @default("empty"),)"
        "   field_24 is ?Int[8]       @default(14),"
        "   field_25 is ?Float[8]     @default(3.14),"
        "   field_26 is ?Reference    @of(OtherSchemaName),"
        " "
        "   field_31 is ?Boolean      @default(null),"
        "   field_32 is ?DateTime     @default(null),"
        "   field_33 is ?String[15]   @default(null),"
        "   field_34 is ?Int[8]       @default(null),"
        "   field_35 is ?Float[8]     @default(null),"
        "   field_36 is ?Reference    @of(OtherSchemaName)"
        "];"
        " "
        "checks: ["
        R"(  field3 like " * @ * .*",)"
        "    length(field3) = 13,"
        "] ;"
        " "
        "unique: [field1, field2] ;"
        "};";

    const auto out = parseQuery(query).get<Schema>();

    const Schema expected = Init::SchemaInit{}
        .name("SchemaName")
        .inherits({});

    EXPECT_SCHEMA_EQ(out, expected);
}

} // namespace Moonlight::QueryParser::Implementation::Tests
