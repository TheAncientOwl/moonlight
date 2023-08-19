#include <gtest/gtest.h>

#include "QueryParser.hpp"
#include "QueryDataInit.hpp"
#include "QueryDataEquals.hpp"

namespace Moonlight::QueryParser::Implementation::Tests {

using namespace QueryData;
using namespace std::literals;

TEST(DropParserTest, parseSuccess)
{
    {
        const auto query =
            "drop"
            "{"
            "   structure: StructureName;"
            "   cascade: true;"
            "}";

        const auto out = parseQuery(query).get<Drop>();

        const Drop expected = Init::DropInit{}
            .name("StructureName")
            .cascade(true);

        EXPECT_DROP_EQ(out, expected);
    }

    {
        const auto query =
            "drop"
            "{"
            "   structure: StructureName;"
            "   cascade: false;"
            "}";

        const auto out = parseQuery(query).get<Drop>();

        const Drop expected = Init::DropInit{}
            .name("StructureName")
            .cascade(false);

        EXPECT_DROP_EQ(out, expected);
    }

    {
        const auto query =
            "drop"
            "{"
            "   structure       :   StructureName       ;        "
            "   cascade: true;"
            "}";

        const auto out = parseQuery(query).get<Drop>();

        const Drop expected = Init::DropInit{}
            .name("StructureName")
            .cascade(true);

        EXPECT_DROP_EQ(out, expected);
    }

    {
        const auto query =
            "Drop"
            "                       {"
            "   Structure  : StructureName;"
            "       Cascade      : true   ;"
            "             }       ";

        const auto out = parseQuery(query).get<Drop>();

        const Drop expected = Init::DropInit{}
            .name("StructureName")
            .cascade(true);

        EXPECT_DROP_EQ(out, expected);
    }
}

TEST(DropParserTest, parseThrow)
{
    {
        const auto query = "drop{}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }

    {
        const auto query =
            "drop"
            "{"
            "   structure StructureName;"
            "   cascade: true;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }

    {
        const auto query =
            "drop"
            "{"
            "   cascade: true;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }

    {
        const auto query =
            "drop"
            "{"
            "   structure: StructureName;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }

    {
        const auto query =
            "drop"
            "{"
            "   structure: StructureName;"
            "   cascade: maybe;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }

    {
        const auto query =
            "drop"
            "{"
            "   structure:"
            "   cascade: true;"
            "}";
        EXPECT_THROW({ parseQuery(query); }, std::runtime_error);
    }
}

} // namespace Moonlight::QueryParser::Implementation::Tests
