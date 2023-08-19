#include <gtest/gtest.h>

#include "QueryParser.hpp"
#include "QueryDataInit.hpp"
#include "QueryDataEquals.hpp"

namespace Moonlight::QueryParser::Implementation::Tests {

using namespace QueryData;
using namespace std::literals;

TEST(DatabaseParserTest, parseSuccessCreate1)
{
    const auto query = "database {"
        "operation: create;"
        "name: DatabaseName;"
        "}";

    const auto out = parseQuery(query).get<Database>();

    const Database expected = Init::DatabaseInit{}
        .type(Primitives::EDatabaseOperationType::Create)
        .name("DatabaseName");

    EXPECT_DATABASE_EQ(out, expected);
}

TEST(DatabaseParserTest, parseSuccessCreate2)
{
    const auto query = "database {"
        "       operation       :                    create     ;"
        "               name        :          DatabaseName     ;"
        "}";

    const auto out = parseQuery(query).get<Database>();

    const Database expected = Init::DatabaseInit{}
        .type(Primitives::EDatabaseOperationType::Create)
        .name("DatabaseName");

    EXPECT_DATABASE_EQ(out, expected);
}

TEST(DatabaseParserTest, parseSuccessDrop1)
{
    const auto query = "database {"
        "operation: drop;"
        "name: DatabaseName;"
        "}";

    const auto out = parseQuery(query).get<Database>();

    const Database expected = Init::DatabaseInit{}
        .type(Primitives::EDatabaseOperationType::Drop)
        .name("DatabaseName");

    EXPECT_DATABASE_EQ(out, expected);
}

TEST(DatabaseParserTest, parseSuccessDrop2)
{
    const auto query = "database {"
        "           operation       :                     drop                ;"
        "           name    :          DatabaseName     ;"
        "}";

    const auto out = parseQuery(query).get<Database>();

    const Database expected = Init::DatabaseInit{}
        .type(Primitives::EDatabaseOperationType::Drop)
        .name("DatabaseName");

    EXPECT_DATABASE_EQ(out, expected);
}

TEST(DatabaseParserTest, parseSuccessBackup11)
{
    const auto query = "database {"
        "operation: backup;"
        "name: DatabaseName;"
        R"(to_disk: "/home/user/lunardb-backup";)"
        "with_differential: true;"
        "}";

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

TEST(DatabaseParserTest, parseSuccessBackup12)
{
    const auto query = "database {"
        "               operation   :                 backup  ;"
        "       name        :          DatabaseName     ;   "
        R"(     to_disk     :        "/home/user/lunardb-backup"        ;)"
        "       with_differential       :     true    ;   "
        "}";

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

TEST(DatabaseParserTest, parseSuccessBackup21)
{
    const auto query = "database {"
        "operation: backup;"
        "name: DatabaseName;"
        R"(to_disk: "/home/user/lunardb-backup";)"
        "with_differential: false;"
        "}";

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

TEST(DatabaseParserTest, parseSuccessBackup22)
{
    const auto query = "database {"
        "       operation   :   backup  ;"
        "       name        :      DatabaseName ;"
        R"(                         to_disk     : "/home/user/lunardb-backup";)"
        "       with_differential       :     false   ;"
        "}";

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

TEST(DatabaseParserTest, parseThrowUnknownOperation)
{
    const auto query = "database {"
        "operation: something;"
        "name: DatabaseName;"
        "}";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(DatabaseParserTest, parseThrowInvalidName)
{
    const auto query = "database {"
        "operation: create;"
        "name: Database-Name;"
        "}";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(DatabaseParserTest, parseThrowBackup1)
{
    const auto query = "database {"
        "operation: backup;"
        "name: DatabaseName;"
        R"(to_disk: "/home/user/lunardb-backup";)"
        "}";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(DatabaseParserTest, parseThrowBackup2)
{
    const auto query = "database {"
        "operation: backup;"
        "name: DatabaseName;"
        "with_differential: true;"
        "}";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(DatabaseParserTest, parseThrowBackup3)
{
    const auto query = "database {"
        "operation: backup;"
        "name: DatabaseName;"
        R"(to_disk: ;)"
        "with_differential: true;"
        "}";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

} //namespace Moonlight::QueryParser::Implementation::Tests
