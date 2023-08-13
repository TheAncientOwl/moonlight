#include <gtest/gtest.h>

#include "QueryParser.hpp"

#define ASSERT_MATCH(query) ASSERT_TRUE(DropParser{}.match(query))
#define ASSERT_NO_MATCH(query) ASSERT_FALSE(DropParser{}.match(query))

namespace Moonlight::QueryParser::Helpers::Tests {

TEST(RegexDropMatchTest, match)
{
    ASSERT_MATCH(
        "drop {"
        "    structure: StructureName;"
        "    cascade: true;"
        "}"
    );

    ASSERT_MATCH(
        "drop {"
        "    structure: StructureName;"
        "    cascade: false;"
        "}"
    );
}

TEST(RegexDropMatchTest, noMatch)
{
    ASSERT_NO_MATCH(
        "drop {"
        "    structure: Structure-Name;"
        "    cascade: true;"
        "}"
    );

    ASSERT_NO_MATCH(
        "drop {"
        "    structure: StructureName;"
        "    cascade: maybe;"
        "}"
    );

    ASSERT_NO_MATCH(
        "drop {"
        "    structure: StructureName"
        "    cascade: maybe;"
        "}"
    );
}


} // namespace Moonlight::QueryParser::Helpers::Tests
