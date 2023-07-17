#include <gtest/gtest.h>

#include "Utils.hpp"

#define CONCAT(x, y) x ## y
#define CONCAT2(x, y) CONCAT(x, y)
#define ASSERT_TRIM(str, expected, trim) \
    { \
        std::string_view sv = str; \
        trim(sv); \
        ASSERT_EQ(sv, expected); \
    }\

namespace Moonlight::Common::Utils::Test {

using namespace Common;
using namespace std::literals;

TEST(CommonUtilsTest, Trim)
{
    ASSERT_TRIM("hello world!"sv, "hello world!"sv, Utils::trim);
    ASSERT_TRIM("    hello world!     "sv, "hello world!"sv, Utils::trim);

    ASSERT_TRIM("hello world!"sv, "hello world!"sv, Utils::trimLeft);
    ASSERT_TRIM("    hello world!"sv, "hello world!"sv, Utils::trimLeft);

    ASSERT_TRIM("hello world!"sv, "hello world!"sv, Utils::trimRight);
    ASSERT_TRIM("hello world!    "sv, "hello world!"sv, Utils::trimRight);

    ASSERT_TRIM(" "sv, ""sv, Utils::trim);

    std::string_view sv = "       "sv;
    Utils::trim(sv);
    ASSERT_EQ(sv.length(), 0);
}

TEST(CommonUtilsTest, StartsWithIgnoreCase)
{
    ASSERT_TRUE(Utils::startsWithIgnoreCase("Check dada waawd af", "cHeck"));
    ASSERT_TRUE(Utils::startsWithIgnoreCase("ChEcK dada waawd af", "cHeCk"));
    ASSERT_TRUE(Utils::startsWithIgnoreCase("CHeCk dada waawd af", "cHEck"));
}

TEST(CommonUtilsTest, SplitAt)
{
    {
        const auto in = "abc; def; ghi;"sv;

        std::vector<std::string_view> out =
        {
            "abc"sv,
            " def"sv,
            " ghi"sv,
        };

        ASSERT_EQ(splitAt(in, ';'), out);
    }
    {
        const auto in = "abc; def; ghi; dadad"sv;

        std::vector<std::string_view> out =
        {
            "abc"sv,
            " def"sv,
            " ghi"sv,
            " dadad"sv,
        };

        ASSERT_EQ(splitAt(in, ';'), out);
    }
    {
        const auto in = "abc; def   ; ghi;"sv;

        std::vector<std::string_view> out =
        {
            "abc"sv,
            " def   "sv,
            " ghi"sv,
        };

        ASSERT_EQ(splitAt(in, ';'), out);
    }
    {
        const auto in = "     abc    ;    de   f       ;   g hi        ;        "sv;

        std::vector<std::string_view> out =
        {
            "     abc    "sv,
            "    de   f       "sv,
            "   g hi        "sv,
            "        ",
        };

        ASSERT_EQ(splitAt(in, ';'), out);
    }
    {
        const auto in = "   a        ab    abc       abcd   "sv;

        std::vector<std::string_view> out =
        {
            "a"sv,
            "ab"sv,
            "abc"sv,
            "abcd",
        };

        ASSERT_EQ(splitAt(in, ' '), out);
    }
}

} // namespace Moonlight::Common::Utils::Test
