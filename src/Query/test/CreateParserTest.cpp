#include <gtest/gtest.h>

#include "QueryParser.hpp"
#include "QueryDataInit.hpp"
#include "QueryDataEquals.hpp"

namespace Moonlight::QueryParser::Implementation::Tests {

using namespace QueryData;
using namespace std::literals;

TEST(CreateParserTest, parseSuccess)
{
    {
        const auto query =
            "create structure {"
            "   name: StructureName;"
            "   type: table;"
            "   based_on: SchemaName;"
            "   volatile: true;"
            "}";

        const auto out = parseQuery(query).get<Create>();

        const Create expected = Init::CreateInit{}
            .name("StructureName")
            .type(Primitives::EStructureType::Table)
            .schema("SchemaName")
            .is_volatile(true);

        EXPECT_CREATE_EQ(out, expected);
    }
    {
        const auto query =
            "create structure {"
            "   name: StructureName;"
            "   type: document;"
            "   based_on: SchemaName;"
            "   volatile: true;"
            "}";

        const auto out = parseQuery(query).get<Create>();

        const Create expected = Init::CreateInit{}
            .name("StructureName")
            .type(Primitives::EStructureType::Document)
            .schema("SchemaName")
            .is_volatile(true);

        EXPECT_CREATE_EQ(out, expected);
    }
    {
        const auto query =
            "create structure {"
            "   name: StructureName;"
            "   type: document;"
            "   based_on: SchemaName;"
            "   volatile: true;"
            "}";

        const auto out = parseQuery(query).get<Create>();

        const Create expected = Init::CreateInit{}
            .name("StructureName")
            .type(Primitives::EStructureType::Document)
            .schema("SchemaName")
            .is_volatile(true);

        EXPECT_CREATE_EQ(out, expected);
    }
    {
        const auto query =
            "create structure {"
            "   name: StructureName;"
            "   type: document;"
            "   based_on: SchemaName;"
            "   volatile: false;"
            "}";

        const auto out = parseQuery(query).get<Create>();

        const Create expected = Init::CreateInit{}
            .name("StructureName")
            .type(Primitives::EStructureType::Document)
            .schema("SchemaName")
            .is_volatile(false);

        EXPECT_CREATE_EQ(out, expected);
    }
    {
        const auto query =
            "create           structure    {"
            "   name   :    StructureName   ;  "
            "   type  : table   ;  "
            "   based_on  : SchemaName  ;  "
            "   volatile  :   true  ;  "
            "  }   ";

        const auto out = parseQuery(query).get<Create>();

        const Create expected = Init::CreateInit{}
            .name("StructureName")
            .type(Primitives::EStructureType::Table)
            .schema("SchemaName")
            .is_volatile(true);

        EXPECT_CREATE_EQ(out, expected);
    }
}

TEST(CreateParserTest, parseThrow)
{
    {
        const auto query =
            "create structure {"
            "   name: StructureName;"
            "   type: table;"
            "   based_on: SchemaName;"
            "   volatile: maybe;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
    {
        const auto query =
            "create {"
            "   name: StructureName;"
            "   type: table;"
            "   based_on: SchemaName;"
            "   volatile: true;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
    {
        const auto query =
            "create structure {"
            "   type: table;"
            "   based_on: SchemaName;"
            "   volatile: true;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
    {
        const auto query =
            "create structure {"
            "   name: StructureName;"
            "   based_on: SchemaName;"
            "   volatile: true;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
    {
        const auto query =
            "create structure {"
            "   name: StructureName;"
            "   type: table;"
            "   volatile: true;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
    {
        const auto query =
            "create structure {"
            "   name: StructureName;"
            "   type: table;"
            "   based_on: SchemaName;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
}

} // namespace Moonlight::QueryParser::Implementation::Tests
