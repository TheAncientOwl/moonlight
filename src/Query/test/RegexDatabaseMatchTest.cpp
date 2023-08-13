#include <gtest/gtest.h>

#include "QueryParser.hpp"

#define ASSERT_MATCH(query) ASSERT_TRUE(DatabaseParser{}.match(query))
#define ASSERT_NO_MATCH(query) ASSERT_FALSE(DatabaseParser{}.match(query))

namespace Moonlight::QueryParser::Implementation::Tests {

TEST(RegexDatabaseMatchTest, match)
{
    ASSERT_MATCH(
        "database create {"
        "   name: DatabaseName;"
        "}"
    );

    ASSERT_MATCH(
        "database drop {"
        "   name: DatabaseName;"
        "}"
    );

    ASSERT_MATCH(
        "database backup {"
        "   name: DatabaseName;"
        R"(to_disk: "/home/user/lunardb-backup";)"
        "with_differential: true;"
        "}"
    );

    ASSERT_MATCH(
        "database backup {"
        "   name: DatabaseName;"
        R"(to_disk: "/home/user/lunardb-backup";)"
        "with_differential: false;"
        "}"
    );
}

TEST(RegexDatabaseMatchTest, noMatch)
{
    ASSERT_NO_MATCH(
        "database create {"
        "   name: Database-Name;"
        "}"
    );

    ASSERT_NO_MATCH(
        "database dropp {"
        "   name: DatabaseName;"
        "}"
    );

    ASSERT_NO_MATCH(
        "database backup {"
        "   name: DatabaseName;"
        R"(to_disk: "/home/user/lunardb-backup";)"
        "with_differential: maybe;"
        "}"
    );

    ASSERT_NO_MATCH(
        "database backup {"
        "   name: DatabaseName;"
        R"(to_disk: "/home/user/lunardb-backup";)"
        "}"
    );
}

} // namespace Moonlight::QueryParser::Implementation::Tests
