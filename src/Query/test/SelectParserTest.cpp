#include <gtest/gtest.h>

#include "common/QueryParser.hpp"
#include "helpers/ParsedQueriesInit.hpp"
#include "helpers/ParsedQueriesCompare.hpp"

namespace Moonlight::QueryParser::Implementation::Tests {

using namespace ParsedQuery;
using namespace std::literals;

TEST(SelectParserTest, parseSuccess01)
{
    const auto query =
        "select{"
        "    from: ["
        "        structure1 as s1,"
        "        structure2 as s2,"
        "        structure3 as s3"
        "    ];"
        " "
        "    fields: ["
        "        s1.field as alias_field1,"
        "        s2.field as alias_field2,"
        "        s3.field as alias_field3"
        "    ];"
        " "
        "    join: ["
        "        s1 => s2 on reference_field12,"
        "        s2 => s3 on reference_field23,"
        "        s3 => s1 on reference_field31"
        "    ];"
        " "
        "    where: rid = 11 or (rid >= 2 and 5 <= rid or some_field < 5000) or rid = 9 or rid = 120;"
        " "
        "    order_by: ["
        "        s1.some_field asc,"
        "        s2.some_field desc"
        "    ];"
        "};";

    const auto out = parseQuery(query).get<Select>();

    const Select expected = Init::SelectInit{}
        .from({
            Init::AliasInit{}.original("structure1").alias("s1"),
            Init::AliasInit{}.original("structure2").alias("s2"),
            Init::AliasInit{}.original("structure3").alias("s3")
            })
        .fields({
            Init::AliasInit{}.original("s1.field").alias("alias_field1"),
            Init::AliasInit{}.original("s2.field").alias("alias_field2"),
            Init::AliasInit{}.original("s3.field").alias("alias_field3")
            })
        .join({
            Init::JoinInit{}.child("s1").father("s2").reference_field("reference_field12"),
            Init::JoinInit{}.child("s2").father("s3").reference_field("reference_field23"),
            Init::JoinInit{}.child("s3").father("s1").reference_field("reference_field31")
            })
        .where(Init::WhereClauseInit{}.content("rid = 11 or (rid >= 2 and 5 <= rid or some_field < 5000) or rid = 9 or rid = 120"))
        .order_by({
            Init::OrderByInit{}.field("s1.some_field").type(Primitives::ESelectSortType::Asc),
            Init::OrderByInit{}.field("s2.some_field").type(Primitives::ESelectSortType::Desc)
            });

    EXPECT_SELECT_EQ(out, expected);
}

TEST(SelectParserTest, parseThrow01)
{

}

} // namespace Moonlight::QueryParser::Implementation::Tests
