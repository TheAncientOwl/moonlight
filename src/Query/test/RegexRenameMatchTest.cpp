#include <gtest/gtest.h>

#include "QueryParser.hpp"

#define ASSERT_MATCH(query) ASSERT_TRUE(RenameParser{}.match(query))
#define ASSERT_NO_MATCH(query) ASSERT_FALSE(RenameParser{}.match(query))

namespace Moonlight::QueryParser::Implementation::Tests {

TEST(RegexRenameMatchTest, match)
{
    ASSERT_MATCH(
        "rename structure {"
        "   old_name: StructureNameOld;"
        "   new_name: StructureNameNew;"
        "}"
    );

    ASSERT_MATCH(
        "rename field {"
        "   old_name: StructureName.old_field;"
        "   new_name: StructureName.new_field;"
        "}"
    );
}

TEST(RegexRenameMatchTest, noMatch)
{
    ASSERT_NO_MATCH(
        "rename structure {"
        "   old_name: StructureNameOld.smth;"
        "   new_name: StructureNameNew;"
        "}"
    );

    ASSERT_NO_MATCH(
        "rename field {"
        "   old_name: StructureName.old_field;"
        "   new_name: StructureNamenew_field;"
        "}"
    );

    ASSERT_NO_MATCH(
        "rename idk {"
        "   old_name: StructureName.old_field;"
        "   new_name: StructureName.new_field;"
        "}"
    );
}

} // namespace Moonlight::QueryParser::Implementation::Tests
