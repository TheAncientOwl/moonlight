#include <gtest/gtest.h>

#include "Utils.hpp"

namespace Moonlight::Utils::Tests {

TEST(UtilsTest, equalsIgnoreCaseTrue01)
{
    ASSERT_TRUE(equalsIgnoreCase("", ""));
}

TEST(UtilsTest, equalsIgnoreCaseTrue02)
{
    ASSERT_TRUE(equalsIgnoreCase("qWertYUIop", "QWErtyUIOp"));
}

TEST(UtilsTest, equalsIgnoreCaseTrue03)
{
    ASSERT_TRUE(equalsIgnoreCase("some string \r :)", "some string \r :)"));
}

TEST(UtilsTest, equalsIgnoreCaseFalse01)
{
    ASSERT_FALSE(equalsIgnoreCase("qwerty", "QWERT"));
}

TEST(UtilsTest, equalsIgnoreCaseFalse02)
{
    ASSERT_FALSE(equalsIgnoreCase("somestr1", "somestr2"));
}

TEST(UtilsTest, startsWithIgnoreCaseTrue01)
{
    ASSERT_TRUE(startsWithIgnoreCase("", ""));
}

TEST(UtilsTest, startsWithIgnoreCaseTrue02)
{
    ASSERT_TRUE(startsWithIgnoreCase("qWertYUIopASDFGHJKL", "QWErtyUIOp"));
}

TEST(UtilsTest, startsWithIgnoreCaseTrue03)
{
    ASSERT_TRUE(startsWithIgnoreCase("some string \r :) WITH SOME MORE STRINGS", "some string \r :)"));
}

TEST(UtilsTest, startsWithIgnoreCaseFalse01)
{
    ASSERT_FALSE(startsWithIgnoreCase("qwerty", "qQWERT"));
}

TEST(UtilsTest, startsWithIgnoreCaseFalse02)
{
    ASSERT_FALSE(startsWithIgnoreCase("somestr1", "ssomestr2"));
}

} // namespace Moonlight::Utils::Tests
