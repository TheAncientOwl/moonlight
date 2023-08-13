#include <gtest/gtest.h>

#include "QueryParser.hpp"

#define ASSERT_MATCH(query) ASSERT_TRUE(IndexParser{}.match(query))
#define ASSERT_NO_MATCH(query) ASSERT_FALSE(IndexParser{}.match(query))

namespace Moonlight::QueryParser::Implementation::Tests {

TEST(RegexIndexMatchTest, match)
{
    ASSERT_MATCH(
        "index {"
        "    on: SomeStructure;"
        "    name: Field1Field2Index;"
        "    fields: [ field1, field2 ];"
        "    unique: true;"
        "}"
    );

    ASSERT_MATCH(
        "index {"
        "    on: SomeStructure;"
        "    name: Field1Field2Index;"
        "    fields: [ field1, field2 ];"
        "    unique: false;"
        "}"
    );

    ASSERT_MATCH(
        "index {"
        "    on: SomeStructure;"
        "    name: Field1Field2Index;"
        "    fields: [ field1 ];"
        "    unique: true;"
        "}"
    );

    ASSERT_MATCH(
        "index {"
        "    on: SomeStructure;"
        "    name: Field1Field2Index;"
        "    fields: [ field1, field2, field3 ];"
        "    unique: true;"
        "}"
    );
}

TEST(RegexIndexMatchTest, noMatch)
{
    ASSERT_NO_MATCH(
        "index {"
        "    on: SomeStructure;"
        "    name: Field1Field2Index;"
        "    fields: [  ];"
        "    unique: true;"
        "}"
    );

    ASSERT_NO_MATCH(
        "index {"
        "    on: SomeStructure;"
        "    name: Field1Field2Index;"
        "    fields: [ field1, field2 ];"
        "    unique: maybe;"
        "}"
    );

    ASSERT_NO_MATCH(
        "index {"
        "    on: Some-Structure;"
        "    name: Field1Field2Index;"
        "    fields: [ field1 ];"
        "    unique: true;"
        "}"
    );

    ASSERT_NO_MATCH(
        "index {"
        "    on: SomeStructure;"
        "    name: Field1Field2Index;"
        "    fields: [ field1, field2, field3 ];"
        "}"
    );
}

} // namespace Moonlight::QueryParser::Implementation::Tests
