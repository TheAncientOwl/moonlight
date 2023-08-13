#include <gtest/gtest.h>

#include "QueryParser.hpp"

#define ASSERT_MATCH(query) ASSERT_TRUE(MigrateParser{}.match(query))
#define ASSERT_NO_MATCH(query) ASSERT_FALSE(MigrateParser{}.match(query))

namespace Moonlight::QueryParser::Implementation::Tests {

TEST(RegexMigrateMatchParser, match)
{
    ASSERT_MATCH(
        "migrate {"
        "    structure: StructureName;"
        "    to: NewSchemaName;"
        "}"
    );

    ASSERT_MATCH(
        "migrate {"
        "    structure: StructureName;"
        "    to: NewSchemaName;"
        "    mappings: ["
        "        old_field1 => new_field1,"
        "        old_field2 => new_field2"
        "    ];"
        "}"
    );

    ASSERT_MATCH(
        "migrate {"
        "    structure: StructureName;"
        "    to: NewSchemaName;"
        "    mappings: ["
        "        old_field1 => new_field1,"
        "        old_field2 => new_field2,"
        "        old_field3 => new_field3"
        "    ];"
        "}"
    );
}

TEST(RegexMigrateMatchParser, noMatch)
{
    ASSERT_NO_MATCH(
        "migrate {"
        "    structure: Structure-Name;"
        "    to: NewSchemaName;"
        "}"
    );

    ASSERT_NO_MATCH(
        "migrate {"
        "    structure: StructureName;"
        "    to: NewSchemaName;"
        "    mappings: ["
        "    ];"
        "}"
    );

    ASSERT_NO_MATCH(
        "migrate {"
        "    structure: StructureName;"
        "    to: NewSchemaName;"
        "    mappings: ["
        "        old_field1 => new_field1,"
        "        old_field2 => new_field2"
        "old_field3 => new_field3"
        "    ];"
        "}"
    );
}

} // namespace Moonlight::QueryParser::Implementation::Tests
