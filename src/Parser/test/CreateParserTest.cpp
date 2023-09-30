#include <gtest/gtest.h>

#include "common/api/Parser.hpp"
#include "common/QueryParsers.hpp"
#include "helpers/ObjectsInit.hpp"
#include "helpers/ObjectsCompare.hpp"

namespace Moonlight::Parser::Implementation::Tests {

using namespace Objects;
using namespace Objects::Init;
using namespace std::literals;

TEST(CreateParserTest, parseSuccess01)
{
    const auto query =
        "create structure {"
        "   name: StructureName;"
        "   type: table;"
        "   based_on: SchemaName;"
        "   volatile: true;"
        "};";

    const auto out = parseQuery(query).get<Create>();

    const Create expected = CreateInit{}
        .name("StructureName")
        .type(Primitives::EStructureType::Table)
        .schema("SchemaName")
        .is_volatile(true);

    EXPECT_CREATE_EQ(out, expected);
}

TEST(CreateParserTest, parseSuccess02)
{
    const auto query =
        "create structure {"
        "   name: StructureName;"
        "   type: document;"
        "   based_on: SchemaName;"
        "   volatile: true;"
        "};";

    const auto out = parseQuery(query).get<Create>();

    const Create expected = CreateInit{}
        .name("StructureName")
        .type(Primitives::EStructureType::Document)
        .schema("SchemaName")
        .is_volatile(true);

    EXPECT_CREATE_EQ(out, expected);
}

TEST(CreateParserTest, parseSuccess03)
{
    const auto query =
        "create structure {"
        "   name: StructureName;"
        "   type: document;"
        "   based_on: SchemaName;"
        "   volatile: true;"
        "};";

    const auto out = parseQuery(query).get<Create>();

    const Create expected = CreateInit{}
        .name("StructureName")
        .type(Primitives::EStructureType::Document)
        .schema("SchemaName")
        .is_volatile(true);

    EXPECT_CREATE_EQ(out, expected);
}

TEST(CreateParserTest, parseSuccess04)
{
    const auto query =
        "create structure {"
        "   name: StructureName;"
        "   type: document;"
        "   based_on: SchemaName;"
        "   volatile: false;"
        "};";

    const auto out = parseQuery(query).get<Create>();

    const Create expected = CreateInit{}
        .name("StructureName")
        .type(Primitives::EStructureType::Document)
        .schema("SchemaName")
        .is_volatile(false);

    EXPECT_CREATE_EQ(out, expected);
}

TEST(CreateParserTest, parseSuccess05)
{
    const auto query =
        "create structure    {"
        "   name   :    StructureName   ;  "
        "   type  : table   ;  "
        "   based_on  : SchemaName  ;  "
        "   volatile  :   true  ;  "
        "  } ;  ";

    const auto out = parseQuery(query).get<Create>();

    const Create expected = CreateInit{}
        .name("StructureName")
        .type(Primitives::EStructureType::Table)
        .schema("SchemaName")
        .is_volatile(true);

    EXPECT_CREATE_EQ(out, expected);
}

TEST(CreateParserTest, parseThrow01)
{
    const auto query =
        "create structure {"
        "   name: StructureName;"
        "   type: table;"
        "   based_on: SchemaName;"
        "   volatile: maybe;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(CreateParserTest, parseThrow02)
{
    const auto query =
        "create {"
        "   name: StructureName;"
        "   type: table;"
        "   based_on: SchemaName;"
        "   volatile: true;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(CreateParserTest, parseThrow03)
{
    const auto query =
        "create structure {"
        "   type: table;"
        "   based_on: SchemaName;"
        "   volatile: true;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(CreateParserTest, parseThrow04)
{
    const auto query =
        "create structure {"
        "   name: StructureName;"
        "   based_on: SchemaName;"
        "   volatile: true;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(CreateParserTest, parseThrow05)
{
    const auto query =
        "create structure {"
        "   name: StructureName;"
        "   type: table;"
        "   volatile: true;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(CreateParserTest, parseThrow06)
{
    const auto query =
        "create structure {"
        "   name: StructureName;"
        "   type: table;"
        "   based_on: SchemaName;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

} // namespace Moonlight::Parser::Implementation::Tests
