#include <gtest/gtest.h>

#include "QueryParser.hpp"
#include "helpers/ParsedQueriesInit.hpp"
#include "helpers/ParsedQueriesCompare.hpp"

namespace Moonlight::QueryParser::Implementation::Tests {

using namespace ParsedQuery;
using namespace std::literals;

TEST(RenameParserTest, parseSuccess01)
{
    const auto query =
        "rename {"
        "   type: structure;"
        "   old_name: StructureNameOld;"
        "   new_name: StructureNameNew;"
        "};";

    const auto out = parseQuery(query).get<Rename>();

    const Rename expected = Init::RenameInit{}
        .type(Primitives::EStructureRenameType::Structure)
        .old_name("StructureNameOld")
        .new_name("StructureNameNew");

    EXPECT_RENAME_EQ(out, expected);
}

TEST(RenameParserTest, parseSuccess02)
{
    const auto query =
        "rename {"
        "   type: database;"
        "   old_name: StructureNameOld;"
        "   new_name: StructureNameNew;"
        "};";

    const auto out = parseQuery(query).get<Rename>();

    const Rename expected = Init::RenameInit{}
        .type(Primitives::EStructureRenameType::Database)
        .old_name("StructureNameOld")
        .new_name("StructureNameNew");

    EXPECT_RENAME_EQ(out, expected);
}

TEST(RenameParserTest, parseSuccess03)
{
    const auto query =
        "rename {"
        "   type: field;"
        "   old_name: StructureName.old_field;"
        "   new_name: StructureName.new_field;"
        "};";

    const auto out = parseQuery(query).get<Rename>();

    const Rename expected = Init::RenameInit{}
        .type(Primitives::EStructureRenameType::Field)
        .old_name("StructureName.old_field")
        .new_name("StructureName.new_field");

    EXPECT_RENAME_EQ(out, expected);
}

TEST(RenameParserTest, parseSuccess04)
{
    const auto query =
        "rename {"
        "   type        :       structure;"
        "   old_name        :            StructureNameOld       ;   "
        "   new_name        :       StructureNameNew        ;   "
        "};";

    const auto out = parseQuery(query).get<Rename>();

    const Rename expected = Init::RenameInit{}
        .type(Primitives::EStructureRenameType::Structure)
        .old_name("StructureNameOld")
        .new_name("StructureNameNew");

    EXPECT_RENAME_EQ(out, expected);
}

TEST(RenameParserTest, parseSuccess05)
{
    const auto query =
        "rename {"
        "   type            :               Database        ;"
        "   old_name            :       StructureNameOld      ;"
        "   new_name        :        StructureNameNew       ;       "
        "};";

    const auto out = parseQuery(query).get<Rename>();

    const Rename expected = Init::RenameInit{}
        .type(Primitives::EStructureRenameType::Database)
        .old_name("StructureNameOld")
        .new_name("StructureNameNew");

    EXPECT_RENAME_EQ(out, expected);
}

TEST(RenameParserTest, parseSuccess06)
{
    const auto query =
        "rename {"
        "   type                :                    field;"
        "   old_name        :    StructureName.old_field;"
        "   new_name            :   StructureName.new_field         ;                "
        "};";

    const auto out = parseQuery(query).get<Rename>();

    const Rename expected = Init::RenameInit{}
        .type(Primitives::EStructureRenameType::Field)
        .old_name("StructureName.old_field")
        .new_name("StructureName.new_field");

    EXPECT_RENAME_EQ(out, expected);
}

TEST(RenameParserTest, parseThrow01)
{
    const auto query =
        "rename {"
        "   type: sdasd;"
        "   old_name: StructureNameOld;"
        "   new_name: StructureNameNew;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(RenameParserTest, parseThrow02)
{
    const auto query =
        "rename {"
        "   old_name: StructureNameOld;"
        "   new_name: StructureNameNew;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(RenameParserTest, parseThrow03)
{
    const auto query =
        "rename {"
        "   type: structure;"
        "   new_name: StructureNameNew;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(RenameParserTest, parseThrow04)
{
    const auto query =
        "rename {"
        "   type: structure;"
        "   old_name: StructureNameOld;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(RenameParserTest, parseThrow05)
{
    const auto query =
        "rename {"
        "   type: structure;"
        "   old_name: StructureName.Old;"
        "   new_name: StructureNameNew;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(RenameParserTest, parseThrow06)
{
    const auto query =
        "rename {"
        "   type: structure;"
        "   old_name: StructureNameOld;"
        "   new_name: StructureName.New;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(RenameParserTest, parseThrow07)
{
    const auto query =
        "rename {"
        "   type: database;"
        "   old_name: StructureName.Old;"
        "   new_name: StructureNameNew;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(RenameParserTest, parseThrow08)
{
    const auto query =
        "rename {"
        "   type: database;"
        "   old_name: StructureName.Old;"
        "   new_name: StructureName.New;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(RenameParserTest, parseThrow09)
{
    const auto query =
        "rename {"
        "   type: field;"
        "   old_name: StructureName.;"
        "   new_name: StructureName.New;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(RenameParserTest, parseThrow10)
{
    const auto query =
        "rename {"
        "   type: field;"
        "   old_name: StructureName.Old;"
        "   new_name: StructureName.;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(RenameParserTest, parseThrow11)
{
    const auto query =
        "rename {"
        "   type: field;"
        "   old_name: StructureNameOld;"
        "   new_name: StructureName.New;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(RenameParserTest, parseThrow12)
{
    const auto query =
        "rename {"
        "   type: field;"
        "   old_name: StructureName.Old;"
        "   new_name: StructureNameNew;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(RenameParserTest, parseThrow13)
{
    const auto query =
        "rename {"
        "   type: field;"
        "   old_name: StructureName.;"
        "   new_name: StructureName.New;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(RenameParserTest, parseThrow14)
{
    const auto query =
        "rename {"
        "   type: field;"
        "   old_name: StructureName.Old;"
        "   new_name: StructureName.;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(RenameParserTest, parseThrow15)
{
    const auto query =
        "rename {"
        "   type: field;"
        "   old_name: StructureName. Old;"
        "   new_name: StructureName.New;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(RenameParserTest, parseThrow16)
{
    const auto query =
        "rename {"
        "   type: field;"
        "   old_name: StructureName  .Old;"
        "   new_name: StructureName.New;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(RenameParserTest, parseThrow17)
{
    const auto query =
        "rename {"
        "   type: field;"
        "   old_name: StructureName  .  Old;"
        "   new_name: StructureName.New;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

} // namespace Moonlight::QueryParser::Implementation::Tests
