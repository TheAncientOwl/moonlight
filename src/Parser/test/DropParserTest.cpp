#include <gtest/gtest.h>

#include "common/api/Parser.hpp"
#include "common/QueryParsers.hpp"
#include "helpers/ObjectsInit.hpp"
#include "helpers/ObjectsCompare.hpp"

namespace Moonlight::Parser::Implementation::Tests {

using namespace Objects;
using namespace Objects::Init;
using namespace std::literals;

TEST(DropParserTest, parseSuccess01)
{
    const auto query =
        "drop"
        "{"
        "   structure: StructureName;"
        "   cascade: true;"
        "};";

    const auto out = parseQuery(query).get<Drop>();

    const Drop expected = DropInit{}
        .name("StructureName")
        .cascade(true);

    EXPECT_DROP_EQ(out, expected);
}

TEST(DropParserTest, parseSuccess02)
{
    const auto query =
        "drop"
        "{"
        "   structure: StructureName;"
        "   cascade: false;"
        "};";

    const auto out = parseQuery(query).get<Drop>();

    const Drop expected = DropInit{}
        .name("StructureName")
        .cascade(false);

    EXPECT_DROP_EQ(out, expected);
}

TEST(DropParserTest, parseSuccess03)
{
    const auto query =
        "drop"
        "{"
        "   structure       :   StructureName       ;        "
        "   cascade: true;"
        "};";

    const auto out = parseQuery(query).get<Drop>();

    const Drop expected = DropInit{}
        .name("StructureName")
        .cascade(true);

    EXPECT_DROP_EQ(out, expected);
}

TEST(DropParserTest, parseSuccess04)
{
    const auto query =
        "Drop"
        "                       {"
        "   Structure  : StructureName;"
        "       Cascade      : true   ;"
        "             };       ";

    const auto out = parseQuery(query).get<Drop>();

    const Drop expected = DropInit{}
        .name("StructureName")
        .cascade(true);

    EXPECT_DROP_EQ(out, expected);
}

TEST(DropParserTest, parseThrow01)
{
    const auto query = "drop{};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(DropParserTest, parseThrow02)
{
    const auto query =
        "drop"
        "{"
        "   structure StructureName;"
        "   cascade: true;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(DropParserTest, parseThrow03)
{
    const auto query =
        "drop"
        "{"
        "   cascade: true;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(DropParserTest, parseThrow04)
{
    const auto query =
        "drop"
        "{"
        "   structure: StructureName;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(DropParserTest, parseThrow05)
{
    const auto query =
        "drop"
        "{"
        "   structure: StructureName;"
        "   cascade: maybe;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

TEST(DropParserTest, parseThrow06)
{
    const auto query =
        "drop"
        "{"
        "   structure:"
        "   cascade: true;"
        "};";

    EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
}

} // namespace Moonlight::Parser::Implementation::Tests
