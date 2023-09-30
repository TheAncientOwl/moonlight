#include <gtest/gtest.h>

#include "common/api/Parser.hpp"
#include "common/QueryParsers.hpp"
#include "helpers/ObjectsInit.hpp"
#include "helpers/ObjectsCompare.hpp"

namespace Moonlight::Parser::Implementation::Tests {

using namespace Objects;
using namespace Objects::Init;
using namespace std::literals;

TEST(DeleteParserTest, parseSuccess01)
{
    const auto query =
        "delete {"
        "   from: StructureName;"
        "   where: rid = 11 or (rid >= 2 and 5 <= rid or some_field < 5000) or rid = 9 or rid = 120;"
        "};";

    const auto out = parseQuery(query).get<Delete>();

    const Delete expected = DeleteInit{}
        .from("StructureName")
        .where(WhereClauseInit{}.content("rid = 11 or (rid >= 2 and 5 <= rid or some_field < 5000) or rid = 9 or rid = 120"));

    EXPECT_DELETE_EQ(out, expected);
}

TEST(DeleteParserTest, parseSuccess02)
{
    const auto query =
        "delete {"
        "   from: StructureName;"
        R"( where: rid = 11 or (rid >= 2 and 5 <= rid or some_field < 5000) or rid = 9 or rid = 120 and some_field like "*some-other-str;  ";)"
        "};";

    const auto out = parseQuery(query).get<Delete>();

    const Delete expected = DeleteInit{}
        .from("StructureName")
        .where(WhereClauseInit{}.content(R"(rid = 11 or (rid >= 2 and 5 <= rid or some_field < 5000) or rid = 9 or rid = 120 and some_field like "*some-other-str;  ")"));

    EXPECT_DELETE_EQ(out, expected);
}

TEST(DeleteParserTest, parseThrow01)
{
    const auto query =
        "delete {"
        "   from: ;"
        "   where: rid = 11 or (rid >= 2 and 5 <= rid or some_field < 5000) or rid = 9 or rid = 120;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(DeleteParserTest, parseThrow02)
{
    const auto query =
        "delete {"
        "   from: StructureName;"
        "   where: ;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(DeleteParserTest, parseThrow03)
{
    const auto query =
        "delete {"
        "   where: rid = 11 or (rid >= 2 and 5 <= rid or some_field < 5000) or rid = 9 or rid = 120;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(DeleteParserTest, parseThrow04)
{
    const auto query =
        "delete {"
        "   from: SomeStructure;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

} // namespace Moonlight::Parser::Implementation::Tests
