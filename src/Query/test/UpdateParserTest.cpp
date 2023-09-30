#include <gtest/gtest.h>

#include "common/QueryParser.hpp"
#include "helpers/ParsedQueriesInit.hpp"
#include "helpers/ParsedQueriesCompare.hpp"

namespace Moonlight::Parser::Implementation::Tests {

using namespace Objects;
using namespace Objects::Init;
using namespace std::literals;

TEST(UpdateParserTest, parseSuccess01)
{
    const auto query =
        "update{"
        "    structure: StructureName;"
        "    set: ["
        "        field1 => field1 * 1.5 + 2,"
        "        field2 => 3,"
        R"(        field3 => " some ,string")"
        "    ] ;"
        "    where: rid = 11 or (rid >= 2 and 5 <= rid or some_field < 5000) or rid = 9 or rid = 120;"
        "};";

    const auto out = parseQuery(query).get<Update>();

    const Update expected = UpdateInit{}
        .name("StructureName")
        .set({
            SetClauseItemInit{}.field("field1").expression("field1 * 1.5 + 2"),
            SetClauseItemInit{}.field("field2").expression("3"),
            SetClauseItemInit{}.field("field3").expression(R"(" some ,string")")
            })
        .where(WhereClauseInit{}.content("rid = 11 or (rid >= 2 and 5 <= rid or some_field < 5000) or rid = 9 or rid = 120"));

    EXPECT_UPDATE_EQ(out, expected);
}

TEST(UpdateParserTest, parseThrow01)
{
    const auto query =
        "update{"
        "    structure: StructureName;"
        "    set: ;"
        "    where: rid = 11 or (rid >= 2 and 5 <= rid or some_field < 5000) or rid = 9 or rid = 120;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(UpdateParserTest, parseThrow02)
{
    const auto query =
        "update{"
        "    structure: StructureName;"
        "    set: ["
        "         => field1 * 1.5 + 2,"
        "        field2 => 3,"
        R"(        field3 => " some ,string")"
        "    ] ;"
        "    where: rid = 11 or (rid >= 2 and 5 <= rid or some_field < 5000) or rid = 9 or rid = 120;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(UpdateParserTest, parseThrow03)
{
    const auto query =
        "update{"
        "    structure: StructureName;"
        "    set: ["
        "        field1 field1 * 1.5 + 2,"
        "        field2 => 3,"
        R"(        field3 => " some ,string")"
        "    ] ;"
        "    where: rid = 11 or (rid >= 2 and 5 <= rid or some_field < 5000) or rid = 9 or rid = 120;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(UpdateParserTest, parseThrow04)
{
    const auto query =
        "update{"
        "    structure: StructureName;"
        "    set: ["
        "        field1 => ,"
        "        field2 => 3,"
        R"(        field3 => " some ,string")"
        "    ] ;"
        "    where: rid = 11 or (rid >= 2 and 5 <= rid or some_field < 5000) or rid = 9 or rid = 120;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(UpdateParserTest, parseThrow05)
{
    const auto query =
        "update{"
        "    structure: StructureName;"
        "    set: ["
        "        field1 =>,"
        "        field2 => 3,"
        R"(        field3 => " some ,string")"
        "    ] ;"
        "    where: rid = 11 or (rid >= 2 and 5 <= rid or some_field < 5000) or rid = 9 or rid = 120;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

} // namespace Moonlight::Parser::Implementation::Tests
