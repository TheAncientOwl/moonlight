#include <gtest/gtest.h>

#include "Utils.hpp"

namespace Moonlight::Utils::Tests {

TEST(MoonlightUtilsTest, equalsIgnoreCase)
{
    ASSERT_TRUE(equalsIgnoreCase("", ""));
    ASSERT_TRUE(equalsIgnoreCase("qWertYUIop", "QWErtyUIOp"));
    ASSERT_TRUE(equalsIgnoreCase("some string \r :)", "some string \r :)"));

    ASSERT_FALSE(equalsIgnoreCase("qwerty", "QWERT"));
    ASSERT_FALSE(equalsIgnoreCase("somestr1", "somestr2"));
}

TEST(MoonlightUtilsTest, startsWithIgnoreCase)
{
    ASSERT_TRUE(startsWithIgnoreCase("", ""));
    ASSERT_TRUE(startsWithIgnoreCase("qWertYUIopASDFGHJKL", "QWErtyUIOp"));
    ASSERT_TRUE(startsWithIgnoreCase("some string \r :) WITH SOME MORE STRINGS", "some string \r :)"));

    ASSERT_FALSE(startsWithIgnoreCase("qwerty", "qQWERT"));
    ASSERT_FALSE(startsWithIgnoreCase("somestr1", "ssomestr2"));

}

} // namespace Moonlight::Utils::Tests
