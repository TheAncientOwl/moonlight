#include <gtest/gtest.h>

#include "common/QueryParser.hpp"
#include "helpers/ParsedQueriesInit.hpp"
#include "helpers/ParsedQueriesCompare.hpp"

namespace Moonlight::QueryParser::Implementation::Tests {

using namespace ParsedQuery;
using namespace std::literals;

TEST(DatabaseParserTest, parseSuccess01)
{
    const auto query = "database {"
        "operation: create;"
        "name: DatabaseName;"
        "};";

    const auto out = parseQuery(query).get<Database>();

    const Database expected = Init::DatabaseInit{}
        .type(Primitives::EDatabaseOperationType::Create)
        .name("DatabaseName");

    EXPECT_DATABASE_EQ(out, expected);
}

TEST(DatabaseParserTest, parseSuccess02)
{
    const auto query = "database {"
        "       operation       :                    create     ;"
        "               name        :          DatabaseName     ;"
        "};";

    const auto out = parseQuery(query).get<Database>();

    const Database expected = Init::DatabaseInit{}
        .type(Primitives::EDatabaseOperationType::Create)
        .name("DatabaseName");

    EXPECT_DATABASE_EQ(out, expected);
}

TEST(DatabaseParserTest, parseSuccess03)
{
    const auto query = "database {"
        "operation: drop;"
        "name: DatabaseName;"
        "};";

    const auto out = parseQuery(query).get<Database>();

    const Database expected = Init::DatabaseInit{}
        .type(Primitives::EDatabaseOperationType::Drop)
        .name("DatabaseName");

    EXPECT_DATABASE_EQ(out, expected);
}

TEST(DatabaseParserTest, parseSuccess04)
{
    const auto query = "database {"
        "           operation       :                     drop                ;"
        "           name    :          DatabaseName     ;"
        "};";

    const auto out = parseQuery(query).get<Database>();

    const Database expected = Init::DatabaseInit{}
        .type(Primitives::EDatabaseOperationType::Drop)
        .name("DatabaseName");

    EXPECT_DATABASE_EQ(out, expected);
}

TEST(DatabaseParserTest, parseSuccess05)
{
    const auto query = "database {"
        "operation: backup;"
        "name: DatabaseName;"
        R"(to_disk: "/home/user/lunardb-backup";)"
        "with_differential: true;"
        "};";

    const auto out = parseQuery(query).get<Database>();

    const Database expected = Init::DatabaseInit{}
        .type(Primitives::EDatabaseOperationType::Backup)
        .name("DatabaseName")
        .backup_metadata(
            Init::DatabaseBackupMetadataInit{}
            .disk_path(R"("/home/user/lunardb-backup")")
            .with_differential(true)
        );

    EXPECT_DATABASE_EQ(out, expected);
}

TEST(DatabaseParserTest, parseSuccess06)
{
    const auto query = "database {"
        "               operation   :                 backup  ;"
        "       name        :          DatabaseName     ;   "
        R"(     to_disk     :        "/home/user/lunardb-backup"        ;)"
        "       with_differential       :     true    ;   "
        "};";

    const auto out = parseQuery(query).get<Database>();

    const Database expected = Init::DatabaseInit{}
        .type(Primitives::EDatabaseOperationType::Backup)
        .name("DatabaseName")
        .backup_metadata(
            Init::DatabaseBackupMetadataInit{}
            .disk_path(R"("/home/user/lunardb-backup")")
            .with_differential(true)
        );

    EXPECT_DATABASE_EQ(out, expected);
}

TEST(DatabaseParserTest, parseSuccess07)
{
    const auto query = "database {"
        "operation: backup;"
        "name: DatabaseName;"
        R"(to_disk: "/home/user/lunardb-backup";)"
        "with_differential: false;"
        "};";

    const auto out = parseQuery(query).get<Database>();

    const Database expected = Init::DatabaseInit{}
        .type(Primitives::EDatabaseOperationType::Backup)
        .name("DatabaseName")
        .backup_metadata(
            Init::DatabaseBackupMetadataInit{}
            .disk_path(R"("/home/user/lunardb-backup")")
            .with_differential(false)
        );

    EXPECT_DATABASE_EQ(out, expected);
}

TEST(DatabaseParserTest, parseSuccess08)
{
    const auto query = "database {"
        "       operation   :   backup  ;"
        "       name        :      DatabaseName ;"
        R"(                         to_disk     : "/home/user/lunardb-backup";)"
        "       with_differential       :     false   ;"
        "};";

    const auto out = parseQuery(query).get<Database>();

    const Database expected = Init::DatabaseInit{}
        .type(Primitives::EDatabaseOperationType::Backup)
        .name("DatabaseName")
        .backup_metadata(
            Init::DatabaseBackupMetadataInit{}
            .disk_path(R"("/home/user/lunardb-backup")")
            .with_differential(false)
        );

    EXPECT_DATABASE_EQ(out, expected);
}

TEST(DatabaseParserTest, parseThrow01)
{
    const auto query = "database {"
        "operation: something;"
        "name: DatabaseName;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(DatabaseParserTest, parseThrow02)
{
    const auto query = "database {"
        "operation: create;"
        "name: Database-Name;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(DatabaseParserTest, parseThrow03)
{
    const auto query = "database {"
        "operation: backup;"
        "name: DatabaseName;"
        R"(to_disk: "/home/user/lunardb-backup";)"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(DatabaseParserTest, parseThrow04)
{
    const auto query = "database {"
        "operation: backup;"
        "name: DatabaseName;"
        "with_differential: true;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(DatabaseParserTest, parseThrow05)
{
    const auto query = "database {"
        "operation: backup;"
        "name: DatabaseName;"
        R"(to_disk: ;)"
        "with_differential: true;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

} //namespace Moonlight::QueryParser::Implementation::Tests
