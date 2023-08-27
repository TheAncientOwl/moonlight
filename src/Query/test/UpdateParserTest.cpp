#include <gtest/gtest.h>

#include "QueryParser.hpp"
#include "helpers/QueryDataInit.hpp"
#include "helpers/QueryDataEquals.hpp"

namespace Moonlight::QueryParser::Implementation::Tests {

using namespace QueryData;
using namespace std::literals;

TEST(UpdateParserTest, parseSuccess01)
{
    const auto query =
        "update{"
        "    structure: StructureName;"
        "    set: ["
        "        field1 => field1 * 1.5 + 2,"
        "        field2 => 3"
        "    ] ;"
        "    where: rid = 11 or (rid >= 2 and 5 <= rid or some_field < 5000) or rid = 9 or rid = 120;"
        "};";

    const auto out = parseQuery(query).get<Update>();

    const Update expected = Init::UpdateInit{}
        .name("StructureName")
        .set(Init::SetClauseInit{}.data(
            "["
            "        field1 = > field1 * 1.5 + 2,"
            "        field2 = > 3"
            "    ]"))
        .where(Init::WhereClauseInit{}.content("rid = 11 or (rid >= 2 and 5 <= rid or some_field < 5000) or rid = 9 or rid = 120"));
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

} // namespace Moonlight::QueryParser::Implementation::Tests
