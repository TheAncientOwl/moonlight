#include <gtest/gtest.h>

#include "QueryParser.hpp"
#include "helpers/QueryDataInit.hpp"
#include "helpers/QueryDataEquals.hpp"

namespace Moonlight::QueryParser::Implementation::Tests {

using namespace QueryData;
using namespace std::literals;

TEST(MigrateParserTest, parseSuccess01)
{
    const auto query =
        "migrate {"
        "   structure: StructureName;"
        "   to: NewSchemaName;"
        "   mappings: ["
        "       old_field1 => new_field1,"
        "       old_field2 => new_field2"
        "   ];"
        "};";

    const auto out = parseQuery(query).get<Migrate>();

    const Migrate expected = Init::MigrateInit{}
        .structure_name("StructureName")
        .new_schema("NewSchemaName")
        .mappings({
            {"old_field1", "new_field1"},
            {"old_field2", "new_field2"}
            });

    EXPECT_MIGRATE_EQ(out, expected);
}

TEST(MigrateParserTest, parseSuccess02)
{
    const auto query =
        "migrate {"
        "   structure: StructureName;"
        "   to: NewSchemaName;"
        "   mappings: ["
        "       old_field1 => new_field1"
        "   ];"
        "};";

    const auto out = parseQuery(query).get<Migrate>();

    const Migrate expected = Init::MigrateInit{}
        .structure_name("StructureName")
        .new_schema("NewSchemaName")
        .mappings({
            {"old_field1", "new_field1"}
            });

    EXPECT_MIGRATE_EQ(out, expected);
}

TEST(MigrateParserTest, parseSuccess03)
{
    const auto query =
        "migrate    {  "
        "   structure       :        StructureName      ;   "
        "       to  :     NewSchemaName       ;       "
        "   mappings    :    [      "
        "               old_field1      =>       new_field1      ,"
        "           old_field2   =>          new_field2     "
        "   ] ; "
        "   }  ;";

    const auto out = parseQuery(query).get<Migrate>();

    const Migrate expected = Init::MigrateInit{}
        .structure_name("StructureName")
        .new_schema("NewSchemaName")
        .mappings({
            {"old_field1", "new_field1"},
            {"old_field2", "new_field2"}
            });

    EXPECT_MIGRATE_EQ(out, expected);
}

TEST(MigrateParserTest, parseThrow01)
{
    const auto query =
        "migrate {"
        "   structure: StructureName;"
        "   to: NewSchemaName;"
        "   mappings: ["
        "   ];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(MigrateParserTest, parseThrow02)
{
    const auto query =
        "migrate {"
        "   structure: StructureName;"
        "   to: NewSchemaName;"
        "   mappings: ["
        "       old_field1 => new_field1"
        "       old_field2 => new_field2"
        "   ];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(MigrateParserTest, parseThrow03)
{
    const auto query =
        "migrate {"
        "   structure: StructureName;"
        "   to: NewSchemaName;"
        "   mappings: ["
        "       old_field1 => new_field1,"
        "       old_field2 => new_field2"
        "   ;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(MigrateParserTest, parseThrow04)
{
    const auto query =
        "migrate {"
        "   structure: StructureName;"
        "   to: NewSchemaName;"
        "   mappings: ["
        "       old_field1 => new_field1,"
        "       old_field2 => new_field2"
        "   "
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(MigrateParserTest, parseThrow05)
{
    const auto query =
        "migrate {"
        "   to: NewSchemaName;"
        "   mappings: ["
        "       old_field1 => new_field1,"
        "       old_field2 => new_field2"
        "   ];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(MigrateParserTest, parseThrow06)
{
    const auto query =
        "migrate {"
        "   structure: StructureName;"
        "   mappings: ["
        "       old_field1 => new_field1,"
        "       old_field2 => new_field2"
        "   ];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(MigrateParserTest, parseThrow07)
{
    const auto query =
        "migrate {"
        "   structure: StructureName;"
        "   to: NewSchemaName;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(MigrateParserTest, parseThrow08)
{
    const auto query =
        "migrate {"
        "   structure: StructureName;"
        "   to: NewSchemaName;"
        "   mappings: ["
        "       old_field1 = > new_field1,"
        "       old_field2 => new_field2"
        "   ];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(MigrateParserTest, parseThrow09)
{
    const auto query =
        "migrate {"
        "   structure: StructureName;"
        "   to: NewSchemaName;"
        "   mappings: ["
        "       old_field1 > new_field1,"
        "       old_field2 => new_field2"
        "   ];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(MigrateParserTest, parseThrow10)
{
    const auto query =
        "migrate {"
        "   structure: StructureName;"
        "   to: NewSchemaName;"
        "   mappings: ["
        "       old_field1 = new_field1,"
        "       old_field2 => new_field2"
        "   ];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(MigrateParserTest, parseThrow11)
{
    const auto query =
        "migrate {"
        "   structure: StructureName;"
        "   to: NewSchemaName;"
        "   mappings: ["
        "       old_field1 new_field1,"
        "       old_field2 => new_field2"
        "   ];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(MigrateParserTest, parseThrow12)
{
    const auto query =
        "migrate {"
        "   structure: StructureName;"
        "   to: NewSchemaName;"
        "   mappings: ["
        "       old_field1 => new _field1,"
        "       old_field2 => new_field2"
        "   ];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(MigrateParserTest, parseThrow13)
{
    const auto query =
        "migrate {"
        "   structure: StructureName;"
        "   to: NewSchemaName;"
        "   mappings: ["
        "       old_ field1 => new_field1,"
        "       old_field2 => new_field2"
        "   ];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(MigrateParserTest, parseThrow14)
{
    const auto query =
        "migrate {"
        "   structure: StructureName;"
        "   to: NewSchemaName;"
        "   mappings: ["
        "        => new_field1,"
        "       old_field2 => new_field2"
        "   ];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(MigrateParserTest, parseThrow15)
{
    const auto query =
        "migrate {"
        "   structure: StructureName;"
        "   to: NewSchemaName;"
        "   mappings: ["
        "       old_field1 => ,"
        "       old_field2 => new_field2"
        "   ];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(MigrateParserTest, parseThrow16)
{
    const auto query =
        "migrate {"
        "   structure: StructureName;"
        "   to: NewSchemaName;"
        "   mappings: ["
        "       old_field1 => "
        "       old_field2 => new_field2"
        "   ];"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

} // namespace Moonlight::QueryParser::Implementation::Tests
