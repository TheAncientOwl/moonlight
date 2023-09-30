#include <gtest/gtest.h>

#include "common/QueryParser.hpp"
#include "helpers/ParsedQueriesInit.hpp"
#include "helpers/ParsedQueriesCompare.hpp"

namespace Moonlight::Parser::Implementation::Tests {

using namespace Objects;
using namespace Objects::Init;
using namespace std::literals;

TEST(DeleteParserTest, parseSuccess01)
{
    const auto query =
        "insert into {"
        "    structure: StructureName;"
        "    fields: [field1, field2, field3];"
        "values : [value1, value2, value3] ;"
        "};";

    const auto out = parseQuery(query).get<Insert>();

    const Insert expected = InsertInit{}
        .structure("StructureName")
        .fields({
            "field1",
            "field2",
            "field3"
            })
        .values({
            "value1",
            "value2",
            "value3" });

    EXPECT_INSERT_EQ(out, expected);
}

TEST(DeleteParserTest, parseSuccess02)
{
    const auto query =
        "insert into {"
        "    structure: StructureName;"
        R"(    fields: [field1, field2, field3, new_field is String[15] @default("empty")];)"
        R"(    values : [value1, value2, value3, "value,4"];)"
        "};";

    const auto out = parseQuery(query).get<Insert>();

    const Insert expected = InsertInit{}
        .structure("StructureName")
        .fields({
            "field1",
            "field2",
            "field3",
            R"(new_field is String[15] @default("empty"))"
            })
        .values({
            "value1",
            "value2",
            "value3",
            R"(value,4)"
            });

    EXPECT_INSERT_EQ(out, expected);
}

TEST(DeleteParserTest, parseSuccess03)
{
    const auto query =
        "insert into {"
        "    structure: StructureName;"
        R"(    values : [value1, value2, value3, "value,4"];)"
        "};";

    const auto out = parseQuery(query).get<Insert>();

    const Insert expected = InsertInit{}
        .structure("StructureName")
        .fields({})
        .values({
            "value1",
            "value2",
            "value3",
            R"(value,4)"
            });

    EXPECT_INSERT_EQ(out, expected);
}

TEST(DeleteParserTest, parseThrow01)
{
    const auto query =
        "insert into {"
        "    structure: StructureName;"
        "    fields: [];"
        "    values : [value1, value2, value3];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(DeleteParserTest, parseThrow02)
{
    const auto query =
        "insert into {"
        "    structure: StructureName;"
        "    fields: [field1, field2];"
        "    values : [value1, value2, value3];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(DeleteParserTest, parseThrow03)
{
    const auto query =
        "insert into {"
        "    structure: StructureName;"
        "    fields: [field1, field2, value3];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(DeleteParserTest, parseThrow04)
{
    const auto query =
        "insert into {"
        "    structure: StructureName;"
        "    fields: [field1, field2, value3];"
        "    values: [];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(DeleteParserTest, parseThrow05)
{
    const auto query =
        "insert into {"
        "    fields: [field1, field2, value3];"
        "    values: [value1, value2, value3];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

} // namespace Moonlight::Parser::Implementation::Tests
