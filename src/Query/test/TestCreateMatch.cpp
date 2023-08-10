#include <gtest/gtest.h>

#include "QueryParser.hpp"

#define ASSERT_MATCH(query) ASSERT_TRUE(StructureCreateParser().match(query))
#define ASSERT_NO_MATCH(query) ASSERT_FALSE(StructureCreateParser().match(query))

namespace Moonlight::QueryParser::Helpers::Test {

TEST(TestCreateMatch, matchSuccess)
{
    ASSERT_MATCH(
        "Structure"
        ".create(table)"
        ".based_on(SchemaName)"
        ".named(StructureName)"
        ".volatile(true);"
    );

    ASSERT_MATCH(
        "Structure"
        ".create(table)"
        ".based_on(SchemaName)"
        ".named(StructureName)"
        ".volatile(false);"
    );

    ASSERT_MATCH(
        "Structure"
        ".create(document)"
        ".based_on(SchemaName)"
        ".named(StructureName)"
        ".volatile(true);"
    );

    ASSERT_MATCH(
        "Structure"
        ".create(document)"
        ".based_on(SchemaName)"
        ".named(StructureName)"
        ".volatile(false);"
    );
}

TEST(TestCreateMatch, matchFail)
{
    ASSERT_NO_MATCH(
        "Structuress"
        ".create(table)"
        ".based_on(SchemaName)"
        ".named(StructureName)"
        ".volatile(true);"
    );

    ASSERT_NO_MATCH(
        "Structure"
        ".create(tabledas)"
        ".based_on(SchemaName)"
        ".named(StructureName)"
        ".volatile(false);"
    );

    ASSERT_NO_MATCH(
        "Structure"
        ".create(document)"
        ".based_on(SchemaName)"
        ".named(StructureName)"
        ".volatile();"
    );

    ASSERT_NO_MATCH(
        "Structure"
        ".create(document)"
        ".based_on(SchemaName)"
        ".named()"
        ".volatile(false);"
    );
}

} // namespace Moonlight::QueryParser::Helpers::Test
