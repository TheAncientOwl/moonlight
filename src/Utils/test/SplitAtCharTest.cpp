#include <gtest/gtest.h>

#include "Utils.hpp"

namespace Moonlight::Utils::Tests {

using namespace std::literals;

TEST(UtilsTest, splitAtChar01)
{
    const auto str = "  field1  ,  field2  ";

    const auto out = splitAtComma(str, ESplitModifier::EscapeQuotes);

    std::vector<std::string_view> expected = {
        "field1",
        "field2"
    };

    EXPECT_EQ(out, expected);
}

TEST(UtilsTest, splitAtChar02)
{
    const auto str = R"(  field1  ,  field2, "some string,q", field3  )";

    const auto out = splitAtComma(str, ESplitModifier::EscapeQuotes);

    std::vector<std::string_view> expected = {
        "field1",
        "field2",
        R"(some string,q)",
        "field3"
    };

    EXPECT_EQ(out, expected);
}

TEST(UtilsTest, splitAtChar03)
{
    const auto str = R"(  field1  ,  field2, "some string,q", field3, "some other string \"with quotes", and commas"  )";

    const auto out = splitAtComma(str, ESplitModifier::EscapeQuotes);

    std::vector<std::string_view> expected = {
        "field1",
        "field2",
        R"(some string,q)",
        "field3",
        R"(some other string \"with quotes)",
        R"(and commas")"
    };

    EXPECT_EQ(out, expected);
}

TEST(UtilsTest, splitAtChar04)
{
    const auto str = R"(  field1  ,  field2, "some string,q", field3, "some other string \"with quotes\", and commas"  )";

    const auto out = splitAtComma(str, ESplitModifier::EscapeQuotes);

    std::vector<std::string_view> expected = {
        "field1",
        "field2",
        R"(some string,q)",
        "field3",
        R"(some other string \"with quotes\", and commas)",
    };

    EXPECT_EQ(out, expected);
}

TEST(UtilsTest, splitAtChar05)
{
    const auto str = R"(  field1, field2, "", field3  )";

    const auto out = splitAtComma(str, ESplitModifier::EscapeQuotes);

    std::vector<std::string_view> expected = {
        "field1",
        "field2",
        "field3"
    };

    EXPECT_EQ(out, expected);
}

TEST(UtilsTest, splitAtChar06)
{
    const auto str = R"(  field1, field2, "", ", field3  )";

    const auto out = splitAtComma(str, ESplitModifier::EscapeQuotes);

    std::vector<std::string_view> expected = {
        "field1",
        "field2",
        R"(", field3)"
    };

    EXPECT_EQ(out, expected);
}

TEST(UtilsTest, splitAtChar07)
{
    const auto str = R"(  field1, field2, "", ", field3  )";

    const auto out = splitAtComma(str);

    std::vector<std::string_view> expected = {
        "field1",
        "field2",
        R"("")",
        R"(")",
        R"(field3)"
    };

    EXPECT_EQ(out, expected);
}

} // namespace Moonlight::Utils::Tests
