#include <gtest/gtest.h>

#include "Utils.hpp"

namespace Moonlight::Utils::Tests {

using namespace std::literals;

TEST(MoonlightUtilsTest, ltrim)
{
    ASSERT_EQ("some string"sv, ltrim("   some string"sv));
    ASSERT_EQ("some string"sv, ltrim("\t\t\tsome string"sv));
    ASSERT_EQ("some string"sv, ltrim("\v\v\vsome string"sv));
    ASSERT_EQ("some string"sv, ltrim("\f\f\fsome string"sv));
    ASSERT_EQ("some string"sv, ltrim("\v\v\vsome string"sv));
    ASSERT_EQ("some string"sv, ltrim("\n\n\nsome string"sv));
    ASSERT_EQ("some string"sv, ltrim("  \t  \v  \f  \t    \v     \t \rsome string"sv));
}

TEST(MoonlightUtilsTest, rtrim)
{
    ASSERT_EQ("some string"sv, rtrim("some string   "sv));
    ASSERT_EQ("some string"sv, rtrim("some string\t\t\t"sv));
    ASSERT_EQ("some string"sv, rtrim("some string\v\v\v"sv));
    ASSERT_EQ("some string"sv, rtrim("some string\f\f\f"sv));
    ASSERT_EQ("some string"sv, rtrim("some string\v\v\v"sv));
    ASSERT_EQ("some string"sv, rtrim("some string\n\n\n"sv));
    ASSERT_EQ("some string"sv, rtrim("some string  \t  \v  \f  \t    \v     \t \r"sv));
}

TEST(MoonlightUtilsTest, trim)
{
    ASSERT_EQ("some string"sv, trim("   some string   "sv));
    ASSERT_EQ("some string"sv, trim("\t\t\tsome string\t\t\t"sv));
    ASSERT_EQ("some string"sv, trim("\v\v\vsome string\v\v\v"sv));
    ASSERT_EQ("some string"sv, trim("\f\f\fsome string\f\f\f"sv));
    ASSERT_EQ("some string"sv, trim("\v\v\vsome string\v\v\v"sv));
    ASSERT_EQ("some string"sv, trim("\n\n\nsome string\n\n\n"sv));
    ASSERT_EQ("some string"sv, trim("  \t  \v  \f  \t    \v     \t \rsome string  \t  \v  \f  \t    \v     \t \r"sv));
}

} // namespace Moonlight::Utils::Tests
