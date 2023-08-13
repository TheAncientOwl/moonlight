#include <gtest/gtest.h>

#include "QueryParser.hpp"

#define ASSERT_MATCH(query) ASSERT_TRUE(CreateParser{}.match(query))
#define ASSERT_NO_MATCH(query) ASSERT_FALSE(CreateParser{}.match(query))

namespace Moonlight::QueryParser::Implementation::Tests {

TEST(RegexCreateMatchTest, match)
{
    ASSERT_MATCH(
        "create structure {"
        "   name: StructureName;"
        "   type: table;"
        "   based_on: SchemaName;"
        "   volatile: true;"
        "}"
    );

    ASSERT_MATCH(
        "create structure {"
        "   name: StructureName;"
        "   type: document;"
        "   based_on: SchemaName;"
        "   volatile: true;"
        "}"
    );
    ASSERT_MATCH(
        "create structure {"
        "   name: StructureName;"
        "   type: table;"
        "   based_on: SchemaName;"
        "   volatile: false;"
        "}"
    );
    ASSERT_MATCH(
        "create structure {"
        "   name: StructureName;"
        "   type: document;"
        "   based_on: SchemaName;"
        "   volatile: false;"
        "}"
    );
}

TEST(RegexCreateMatchTest, noMatch)
{
    ASSERT_NO_MATCH(
        "create structure {"
        "   name: Structure-Name;"
        "   type: table;"
        "   based_on: SchemaName;"
        "   volatile: true;"
        "}"
    );

    ASSERT_NO_MATCH(
        "create structure {"
        "   name: StructureName;"
        "   type: document;"
        "   based_on: Schema-Name;"
        "   volatile: true;"
        "}"
    );
    ASSERT_NO_MATCH(
        "create structure {"
        "   name: StructureName;"
        "   type: table;"
        "   based_on: SchemaName;"
        "   volatile: maybe;"
        "}"
    );
    ASSERT_NO_MATCH(
        "create structure {"
        "   name: StructureName;"
        "   type: someType;"
        "   based_on: SchemaName;"
        "   volatile: false;"
        "}"
    );
}

} //namespace Moonlight::QueryParser::Implementation::Tests
