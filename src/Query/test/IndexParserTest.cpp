#include <gtest/gtest.h>

#include "QueryParser.hpp"
#include "helpers/QueryDataInit.hpp"
#include "helpers/QueryDataEquals.hpp"

namespace Moonlight::QueryParser::Implementation::Tests {

using namespace QueryData;
using namespace std::literals;

TEST(IndexParserTest, parseSuccess01)
{
    const auto query =
        "index {"
        "   on: SomeStructure;"
        "   name: Field1Field2Index;"
        "   fields: [field1, field2];"
        "   unique: true;"
        "};";

    const auto out = parseQuery(query).get<Index>();

    const Index expected = Init::IndexInit{}
        .on_structure("SomeStructure")
        .name("Field1Field2Index")
        .on_fields({ "field1", "field2" })
        .unique(true);

    EXPECT_INDEX_EQ(out, expected);
}

TEST(IndexParserTest, parseSuccess02)
{
    const auto query =
        "index {"
        "   on: SomeStructure;"
        "   name: Field1Field2Index;"
        "   fields: [field1, field2];"
        "   unique: false;"
        "};";

    const auto out = parseQuery(query).get<Index>();

    const Index expected = Init::IndexInit{}
        .on_structure("SomeStructure")
        .name("Field1Field2Index")
        .on_fields({ "field1", "field2" })
        .unique(false);

    EXPECT_INDEX_EQ(out, expected);
}

TEST(IndexParserTest, parseSuccess03)
{
    const auto query =
        "index {"
        "       on  :        SomeStructure      ;   "
        "   name    :        Field1Field2Index ;   "
        "       fields      :    [  field1      ,           field2      ,            field3     ,       field4      ]   ;   "
        "       unique      :     true    ;   "
        "};";

    const auto out = parseQuery(query).get<Index>();

    const Index expected = Init::IndexInit{}
        .on_structure("SomeStructure")
        .name("Field1Field2Index")
        .on_fields({ "field1", "field2", "field3", "field4" })
        .unique(true);

    EXPECT_INDEX_EQ(out, expected);
}

TEST(IndexParserTest, parseSuccess04)
{
    const auto query =
        "index {"
        "       on  :        SomeStructure      ;   "
        "   name    :        Field1Field2Index ;   "
        "       fields      :    [  field1      ,           field2      ,            field3     ,       field4      ]   ;   "
        "       unique      :     false    ;   "
        "};";

    const auto out = parseQuery(query).get<Index>();

    const Index expected = Init::IndexInit{}
        .on_structure("SomeStructure")
        .name("Field1Field2Index")
        .on_fields({ "field1", "field2", "field3", "field4" })
        .unique(false);

    EXPECT_INDEX_EQ(out, expected);
}

TEST(IndexParserTest, parseThrow01)
{
    const auto query =
        "index {"
        "   on: SomeStructure;"
        "   name: Field1Field2Index;"
        "   fields: [];"
        "   unique: true;"
        "};";
    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(IndexParserTest, parseThrow02)
{
    const auto query =
        "index {"
        "   on: SomeStructure;"
        "   name: Field1Field2Index;"
        "   fields: [field1, field2, field3 field4];"
        "   unique: true;"
        "};";
    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(IndexParserTest, parseThrow03)
{
    const auto query =
        "index {"
        "   on: SomeStructure;"
        "   name: Field1Field2Index;"
        "   fields: [field1, field2, fie&ld3, field4];"
        "   unique: true;"
        "};";
    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(IndexParserTest, parseThrow04)
{
    const auto query =
        "index {"
        "   on: SomeStructure;"
        "   name: Field1Field2Index;"
        R"(   fields: [field1, field2, "fie ld3", field4];)"
        "   unique: true;"
        "};";
    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

} // namespace Moonlight::QueryParser::Implementation::Tests
