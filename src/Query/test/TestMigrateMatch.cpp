#include <gtest/gtest.h>

#include "QueryParser.hpp"

#define ASSERT_MATCH(query) ASSERT_TRUE(StructureMigrateParser().match(query))
#define ASSERT_NO_MATCH(query) ASSERT_FALSE(StructureMigrateParser().match(query))

namespace Moonlight::QueryParser::Helpers::Test {

TEST(TestMigrateMatch, matchSuccess)
{
    ASSERT_MATCH(
        "Structure"
        ".migrate(StructureName)"
        ".to(NewSchemaName);"
    );

    ASSERT_MATCH(
        "Structure"
        ".migrate(StructureName)"
        ".to(NewSchemaName)"
        ".migrate_dictionary("
        "    old_field1 => new_field1"
        "    );"
    );

    ASSERT_MATCH(
        "Structure"
        ".migrate(StructureName)"
        ".to(NewSchemaName)"
        ".migrate_dictionary("
        "    old_field1 => new_field1,"
        "    old_field2 => new_field2"
        "    );"
    );

    ASSERT_MATCH(
        "Structure"
        ".migrate(StructureName)"
        ".to(NewSchemaName)"
        ".migrate_dictionary("
        "    old_field1 => new_field1,"
        "    old_field2 => new_field2,"
        "    old_field3 => new_field3"
        "    );"
    );
}

TEST(TestMigrateMatch, matchFail)
{
    ASSERT_NO_MATCH(
        "Structure"
        ".migrate(StructureName);"
    );

    ASSERT_NO_MATCH(
        "Structure"
        ".migrate(StructureName)"
        ".to(NewSchemaName)"
        ".migrate_dictionary("
        "    );"
    );

    ASSERT_NO_MATCH(
        "Structure"
        ".migrate(StructureName)"
        ".to(NewSchemaName)"
        ".migrate_dictionary("
        "    old_field1  new_field1,"
        "    old_field2 => new_field2"
        "    );"
    );

    ASSERT_NO_MATCH(
        "Structure"
        ".migrate(StructureName)"
        ".migrate_dictionary{"
        "    old_field1 => new_field1,"
        "    old_field2 => new_field2,"
        "    old_field3 => new_field3"
        "    };"
    );
}

} // namespace Moonlight::QueryParser::Helpers::Test
