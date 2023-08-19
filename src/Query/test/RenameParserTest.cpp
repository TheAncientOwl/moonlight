#include <gtest/gtest.h>

#include "QueryParser.hpp"
#include "QueryDataInit.hpp"
#include "QueryDataEquals.hpp"

namespace Moonlight::QueryParser::Implementation::Tests {

using namespace QueryData;
using namespace std::literals;

TEST(RenameParserTest, parseSuccess)
{
    {
        const auto query =
            "rename {"
            "   type: structure;"
            "   old_name: StructureNameOld;"
            "   new_name: StructureNameNew;"
            "}";

        const auto out = parseQuery(query).get<Rename>();

        const Rename expected = Init::RenameInit{}
            .type(Primitives::EStructureRenameType::Structure)
            .old_name("StructureNameOld")
            .new_name("StructureNameNew");

        EXPECT_RENAME_EQ(out, expected);
    }
    {
        const auto query =
            "rename {"
            "   type: database;"
            "   old_name: StructureNameOld;"
            "   new_name: StructureNameNew;"
            "}";

        const auto out = parseQuery(query).get<Rename>();

        const Rename expected = Init::RenameInit{}
            .type(Primitives::EStructureRenameType::Database)
            .old_name("StructureNameOld")
            .new_name("StructureNameNew");

        EXPECT_RENAME_EQ(out, expected);
    }
    {
        const auto query =
            "rename {"
            "   type: field;"
            "   old_name: StructureName.old_field;"
            "   new_name: StructureName.new_field;"
            "}";

        const auto out = parseQuery(query).get<Rename>();

        const Rename expected = Init::RenameInit{}
            .type(Primitives::EStructureRenameType::Field)
            .old_name("StructureName.old_field")
            .new_name("StructureName.new_field");

        EXPECT_RENAME_EQ(out, expected);
    }
    {
        const auto query =
            "rename {"
            "   type        :       structure;"
            "   old_name        :            StructureNameOld       ;   "
            "   new_name        :       StructureNameNew        ;   "
            "}";

        const auto out = parseQuery(query).get<Rename>();

        const Rename expected = Init::RenameInit{}
            .type(Primitives::EStructureRenameType::Structure)
            .old_name("StructureNameOld")
            .new_name("StructureNameNew");

        EXPECT_RENAME_EQ(out, expected);
    }
    {
        const auto query =
            "rename {"
            "   type            :               Database        ;"
            "   old_name            :       StructureNameOld      ;"
            "   new_name        :        StructureNameNew       ;       "
            "}";

        const auto out = parseQuery(query).get<Rename>();

        const Rename expected = Init::RenameInit{}
            .type(Primitives::EStructureRenameType::Database)
            .old_name("StructureNameOld")
            .new_name("StructureNameNew");

        EXPECT_RENAME_EQ(out, expected);
    }
    {
        const auto query =
            "rename {"
            "   type                :                    field;"
            "   old_name        :    StructureName.old_field;"
            "   new_name            :   StructureName.new_field         ;                "
            "}";

        const auto out = parseQuery(query).get<Rename>();

        const Rename expected = Init::RenameInit{}
            .type(Primitives::EStructureRenameType::Field)
            .old_name("StructureName.old_field")
            .new_name("StructureName.new_field");

        EXPECT_RENAME_EQ(out, expected);
    }
}

TEST(RenameParserTest, parseThrow)
{
    {
        const auto query =
            "rename {"
            "   type: sdasd;"
            "   old_name: StructureNameOld;"
            "   new_name: StructureNameNew;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
    {
        const auto query =
            "rename {"
            "   old_name: StructureNameOld;"
            "   new_name: StructureNameNew;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
    {
        const auto query =
            "rename {"
            "   type: structure;"
            "   new_name: StructureNameNew;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
    {
        const auto query =
            "rename {"
            "   type: structure;"
            "   old_name: StructureNameOld;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
    {
        const auto query =
            "rename {"
            "   type: structure;"
            "   old_name: StructureName.Old;"
            "   new_name: StructureNameNew;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
    {
        const auto query =
            "rename {"
            "   type: structure;"
            "   old_name: StructureNameOld;"
            "   new_name: StructureName.New;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
    {
        const auto query =
            "rename {"
            "   type: database;"
            "   old_name: StructureName.Old;"
            "   new_name: StructureNameNew;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
    {
        const auto query =
            "rename {"
            "   type: database;"
            "   old_name: StructureName.Old;"
            "   new_name: StructureName.New;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
    {
        const auto query =
            "rename {"
            "   type: field;"
            "   old_name: StructureName.;"
            "   new_name: StructureName.New;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
    {
        const auto query =
            "rename {"
            "   type: field;"
            "   old_name: StructureName.Old;"
            "   new_name: StructureName.;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
    {
        const auto query =
            "rename {"
            "   type: field;"
            "   old_name: StructureNameOld;"
            "   new_name: StructureName.New;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
    {
        const auto query =
            "rename {"
            "   type: field;"
            "   old_name: StructureName.Old;"
            "   new_name: StructureNameNew;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
    {
        const auto query =
            "rename {"
            "   type: field;"
            "   old_name: StructureName.;"
            "   new_name: StructureName.New;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
    {
        const auto query =
            "rename {"
            "   type: field;"
            "   old_name: StructureName.Old;"
            "   new_name: StructureName.;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
    {
        const auto query =
            "rename {"
            "   type: field;"
            "   old_name: StructureName. Old;"
            "   new_name: StructureName.New;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
    {
        const auto query =
            "rename {"
            "   type: field;"
            "   old_name: StructureName  .Old;"
            "   new_name: StructureName.New;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
    {
        const auto query =
            "rename {"
            "   type: field;"
            "   old_name: StructureName  .  Old;"
            "   new_name: StructureName.New;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
}

} // namespace Moonlight::QueryParser::Implementation::Tests
