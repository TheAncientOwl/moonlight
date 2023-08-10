#include <gtest/gtest.h>

#include "QueryParser.hpp"

#define ASSERT_MATCH(query) ASSERT_TRUE(StructureRenameParser().match(query))
#define ASSERT_NO_MATCH(query) ASSERT_FALSE(StructureRenameParser().match(query))

namespace Moonlight::QueryParser::Helpers::Test {

TEST(TestRenameMatch, matchSuccess)
{
    ASSERT_MATCH(
        "Structure"
        ".rename(structure)"
        ".old_name(StructureNameOld)"
        ".new_name(StructureNameNew);"
    );

    ASSERT_MATCH(
        "Structure"
        ".rename(field)"
        ".old_name(StructureName.old_field)"
        ".new_name(StructureName.new_field);"
    );
}

TEST(TestRenameMatch, matchFail)
{
    ASSERT_NO_MATCH(
        "Structure"
        ".rename(field)"
        ".old_name(StructureNameOld)"
        ".new_name(StructureNameNew);"
    );

    ASSERT_NO_MATCH(
        "Structure"
        ".rename(structure)"
        ".old_name(StructureName.old_field)"
        ".new_name(StructureName.new_field);"
    );
}

} // namespace Moonlight::QueryParser::Helpers::Test
