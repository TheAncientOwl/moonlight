#include <gtest/gtest.h>

#include "Utils.hpp"

#define ASSERT_TRIM(func, s1, s2) { auto str = s2; func(str); ASSERT_EQ(s1, str); }

namespace Moonlight::Utils::Tests {

using namespace std::literals;

TEST(MoonlightUtilsTest, ltrim)
{
    ASSERT_TRIM(ltrim, ""sv, "\r\r\r\t\t\t       "sv);
    ASSERT_TRIM(ltrim, ""sv, ""sv);
    ASSERT_TRIM(ltrim, "somestr"sv, "somestr"sv);
    ASSERT_TRIM(ltrim, "some string"sv, "   some string"sv);
    ASSERT_TRIM(ltrim, "some string"sv, "\t\t\tsome string"sv);
    ASSERT_TRIM(ltrim, "some string"sv, "\v\v\vsome string"sv);
    ASSERT_TRIM(ltrim, "some string"sv, "\f\f\fsome string"sv);
    ASSERT_TRIM(ltrim, "some string"sv, "\v\v\vsome string"sv);
    ASSERT_TRIM(ltrim, "some string"sv, "\n\n\nsome string"sv);
    ASSERT_TRIM(ltrim, "some string"sv, "  \t  \v  \f  \t    \v     \t \rsome string"sv);
}

TEST(MoonlightUtilsTest, rtrim)
{
    ASSERT_TRIM(rtrim, ""sv, "\r\r\r\t\t\t       "sv);
    ASSERT_TRIM(rtrim, ""sv, ""sv);
    ASSERT_TRIM(rtrim, "somestr"sv, "somestr"sv);
    ASSERT_TRIM(rtrim, "some string"sv, "some string   "sv);
    ASSERT_TRIM(rtrim, "some string"sv, "some string\t\t\t"sv);
    ASSERT_TRIM(rtrim, "some string"sv, "some string\v\v\v"sv);
    ASSERT_TRIM(rtrim, "some string"sv, "some string\f\f\f"sv);
    ASSERT_TRIM(rtrim, "some string"sv, "some string\v\v\v"sv);
    ASSERT_TRIM(rtrim, "some string"sv, "some string\n\n\n"sv);
    ASSERT_TRIM(rtrim, "some string"sv, "some string  \t  \v  \f  \t    \v     \t \r"sv);
}

TEST(MoonlightUtilsTest, trim)
{
    ASSERT_TRIM(trim, ""sv, "\r\r\r\t\t\t       "sv);
    ASSERT_TRIM(trim, ""sv, ""sv);
    ASSERT_TRIM(trim, "somestr"sv, "somestr"sv);
    ASSERT_TRIM(trim, "some string"sv, "   some string   "sv);
    ASSERT_TRIM(trim, "some string"sv, "\t\t\tsome string\t\t\t"sv);
    ASSERT_TRIM(trim, "some string"sv, "\v\v\vsome string\v\v\v"sv);
    ASSERT_TRIM(trim, "some string"sv, "\f\f\fsome string\f\f\f"sv);
    ASSERT_TRIM(trim, "some string"sv, "\v\v\vsome string\v\v\v"sv);
    ASSERT_TRIM(trim, "some string"sv, "\n\n\nsome string\n\n\n"sv);
    ASSERT_TRIM(trim, "some string"sv, "  \t  \v  \f  \t    \v     \t \rsome string  \t  \v  \f  \t    \v     \t \r"sv);
}

} // namespace Moonlight::Utils::Tests
