#include <gtest/gtest.h>

#include "QueryParser.hpp"

#define ASSERT_MATCH(query) ASSERT_TRUE(SchemaParser{}.match(query))
#define ASSERT_NO_MATCH(query) ASSERT_FALSE(SchemaParser{}.match(query))

namespace Moonlight::QueryParser::Implementation::Tests {

TEST(RegexSchemaMatchTest, match)
{
    ASSERT_MATCH(
        "schema SchemaName {"
        "    inherits: [ SchemaName1, SchemaName2 ];"
        "    fields: ["
        "        field_11 is Boolean             @default(false),"
        "        field_12 is DateTime            @default(now()),"
        R"(        field_13 is String[15]          @default("empty"),)"
        "        field_14 is Int[32]     @default(14),"
        "        field_15 is Float[64]   @default(3.14),"
        "        field_16 is Reference           @of(OtherSchemaName),"
        "        field_21 is !Boolean            @default(false),"
        "        field_22 is !DateTime           @default(now()),"
        R"(        field_23 is !String[15]         @default("empty"),)"
        "        field_24 is !Int[8]    @default(14),"
        "        field_25 is !Float[16]  @default(3.14),"
        "        field_26 is !Reference          @of(OtherSchemaName)"
        "    ];"
        "    checks: ["
        R"(        field3 like "*@*.*",)"
        "        length(field3) = 13"
        "    ];"
        "    unique: [ field1, field2 ];"
        "}"
    );

    ASSERT_MATCH(
        "schema SchemaName {"
        "    inherits: [ SchemaName1, SchemaName2 ];"
        "    fields: ["
        "        field_11 is Boolean             @default(false),"
        "        field_12 is DateTime            @default(now()),"
        R"(        field_13 is String[15]          @default("empty"),)"
        "        field_14 is Int[32]     @default(14),"
        "        field_15 is Float[64]   @default(3.14),"
        "        field_16 is Reference           @of(OtherSchemaName),"
        "        field_21 is !Boolean            @default(false),"
        "        field_22 is !DateTime           @default(now()),"
        R"(        field_23 is !String[15]         @default("empty"),)"
        "        field_24 is !Int[8]    @default(14),"
        "        field_25 is !Float[16]  @default(3.14),"
        "        field_26 is !Reference          @of(OtherSchemaName)"
        "    ];"
        "}"
    );

    ASSERT_MATCH(
        "schema SchemaName {"
        "    fields: ["
        "        field_11 is Boolean             @default(false),"
        "        field_12 is DateTime            @default(now()),"
        R"(        field_13 is String[15]          @default("empty"),)"
        "        field_14 is Int[32]     @default(14),"
        "        field_15 is Float[64]   @default(3.14),"
        "        field_16 is Reference           @of(OtherSchemaName),"
        "        field_21 is !Boolean            @default(false),"
        "        field_22 is !DateTime           @default(now()),"
        R"(        field_23 is !String[15]         @default("empty"),)"
        "        field_24 is !Int[8]    @default(14),"
        "        field_25 is !Float[16]  @default(3.14),"
        "        field_26 is !Reference          @of(OtherSchemaName)"
        "    ];"
        "}"
    );
}

TEST(RegexSchemaMatchTest, noMatch)
{
    ASSERT_NO_MATCH(
        "schema SchemaName {"
        "    inherits: [ SchemaName1, SchemaName2 ];"
        "    fields: ["
        "        field_11 is Bool             @default(false),"
        "        field_12 is DateTime            @default(now()),"
        R"(        field_13 is String[15]          @default("empty"),)"
        "        field_14 is Int[32]     @default(14),"
        "        field_15 is Float[64]   @default(3.14),"
        "        field_16 is Reference           @of(OtherSchemaName),"
        "        field_21 is !Boolean            @default(false),"
        "        field_22 is !DateTime           @default(now()),"
        R"(        field_23 is !String[15]         @default("empty"),)"
        "        field_24 is !Int[8]    @default(14),"
        "        field_25 is !Float[16]  @default(3.14),"
        "        field_26 is !Reference          @of(OtherSchemaName)"
        "    ];"
        "    checks: ["
        R"(        field3 like "*@*.*",)"
        "        length(field3) = 13"
        "    ];"
        "    unique: [ field1, field2 ];"
        "}"
    );

    ASSERT_NO_MATCH(
        "schema SchemaName {"
        "    inherits: [ SchemaName1, SchemaName2 ];"
        "    fields: ["
        "        field_11 is Boolean             @default(false),"
        "        field_12 is Date            @default(now()),"
        R"(        field_13 is String[15]          @default("empty"),)"
        "        field_14 is Int[32]     @default(14),"
        "        field_15 is Float[64]   @default(3.14),"
        "        field_16 is Refference           @of(OtherSchemaName),"
        "        field_21 is !Boolean            @default(false),"
        "        field_22 is !DateTime           @default(now()),"
        R"(        field_23 is !String[15]         @default("empty"),)"
        "        field_24 is !Int[8]    @default(14),"
        "        field_25 is !Float[16]  @default(3.14),"
        "        field_26 is !Reference          (OtherSchemaName)"
        "    ];"
        "}"
    );

    ASSERT_NO_MATCH(
        "schema SchemaName {"
        "    fields: ["
        "        field_11 is Boolean             @default(false),"
        "        field_12 is DateTime            @default(now()),"
        R"(        field_13 is String[15]          @default("empty"),)"
        "        field_14 is Int[32]     @default(14),"
        "        field_15 is Float[64]   @default(3.14),"
        "        field_16 is Reference           @of(OtherSchemaName),"
        "        field_21 is !Boolean            @default(false),"
        "        field_22 is !DateTime           @default(now()),"
        R"(        field_23 !String[15]         @default("empty"),)"
        "        field_24 is !Int[8]    @default(14),"
        "        field_25 is !Float[16]  @default(3.14),"
        "        field_26 is !Reference          @of(OtherSchemaName)"
        "    ];"
        "}"
    );
}

} // namespace Moonlight::QueryParser::Implementation::Tests
