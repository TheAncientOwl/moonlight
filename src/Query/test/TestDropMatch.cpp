#include <gtest/gtest.h>

#include "QueryParser.hpp"

#define ASSERT_MATCH(query) ASSERT_TRUE(StructureDropParser().match(query))
#define ASSERT_NO_MATCH(query) ASSERT_FALSE(StructureDropParser().match(query))

namespace Moonlight::QueryParser::Helpers::Test {

TEST(TestDropMatch, matchSuccess)
{
    ASSERT_MATCH("Structure.drop(SomeStructure).cascade(true);");
    ASSERT_MATCH("Structure.drop(SomeStructure).cascade(false);");
    ASSERT_MATCH("Structure     .      drop      (   SomeStructure  )  . cascade ( true )  ;");
    ASSERT_MATCH("Structure     .      drop      (   SomeStructure  )  . cascade ( false )  ;");
}

TEST(TestDropMatch, matchFail)
{
    ASSERT_MATCH("dawda Structure.drop(SomeStructure).cascade(true);");
    ASSERT_MATCH("Structuresda.drop(SomeStructure).cascade(false);");
    ASSERT_MATCH("Structure     .      dropsd      (   SomeStructure dda  )  . cascade (  )  ;");
    ASSERT_MATCH("Structure     .      drop      (   SomeStructure  )  . cascade (  )  ;");
}

} // namespace Moonlight::QueryParser::Helpers::Test
