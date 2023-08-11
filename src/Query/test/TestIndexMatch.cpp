#include <gtest/gtest.h>

#include "QueryParser.hpp"

#define ASSERT_MATCH(query) ASSERT_TRUE(IndexParser().match(query))
#define ASSERT_NO_MATCH(query) ASSERT_FALSE(IndexParser().match(query))

namespace Moonlight::QueryParser::Helpers::Test {

TEST(TestIndexMatch, matchSuccess)
{
    ASSERT_MATCH(
        "Index.create_on(SomeStructure)"
        ".named(Field1Field2Index)"
        ".on_fields(field1);"
    );
    ASSERT_MATCH(
        "Index.create_on(SomeStructure)"
        ".named(Field1Field2Index)"
        ".on_fields(field1, field2);"
    );
    ASSERT_MATCH(
        "Index.create_on(SomeStructure)"
        ".named(Field1Field2Index)"
        ".on_fields(field1, field2, field3);"
    );
    ASSERT_MATCH(
        "Index.create_on(SomeStructure)"
        ".named(Field1Field2Index)"
        ".on_fields(field1, field2)"
        ".unique(true);"
    );
    ASSERT_MATCH(
        "Index.create_on(SomeStructure)"
        ".named(Field1Field2Index)"
        ".on_fields(field1, field2)"
        ".unique(false);"
    );
}

TEST(TestIndexMatch, matchFail)
{
    ASSERT_NO_MATCH("dawda Structure.drop(SomeStructure).cascade(true);");
}

} // namespace Moonlight::QueryParser::Helpers::Test
