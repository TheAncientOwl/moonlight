#include <gtest/gtest.h>

#include "QueryParser.hpp"

#define ASSERT_MATCH(query) ASSERT_TRUE(DatabaseParser().match(query))
#define ASSERT_NO_MATCH(query) ASSERT_FALSE(DatabaseParser().match(query))

namespace Moonlight::QueryParser::Helpers::Test {

TEST(TestDatabaseMatch, matchSuccess)
{
    ASSERT_MATCH("Database.create(SomeDatabase);");

    ASSERT_MATCH("Database.drop(SomeDatabase);");

    ASSERT_MATCH(
        R"(Database.backup(SomeDatabase))"
        R"(.to_disk("somepath");)"
    );

    ASSERT_MATCH(
        R"(Database.backup(SomeDatabase))"
        R"(.to_disk("somepath"))"
        R"(.with_differential(true);)"
    );

    ASSERT_MATCH(
        R"(Database.backup(SomeDatabase))"
        R"(.to_disk("somepath"))"
        R"(.with_differential(false);)"
    );

}

TEST(TestDatabaseMatch, matchFail)
{
    ASSERT_NO_MATCH("dawda Structure.drop(SomeStructure).cascade(true);");
}

} // namespace Moonlight::QueryParser::Helpers::Test
