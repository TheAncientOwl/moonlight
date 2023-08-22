#include <gtest/gtest.h>

#include "Utils.hpp"

namespace Moonlight::Utils::Tests {

using namespace std::literals;

TEST(UtilsTest, extractBooleanSuccess01)
{
    auto query = "yes: true;"sv;
    ASSERT_EQ(true, extractBoolean(query, "yes"));
}

TEST(UtilsTest, extractBooleanSuccess02)
{
    auto query = "yes: false;"sv;
    ASSERT_EQ(false, extractBoolean(query, "yes"));
}

TEST(UtilsTest, extractBooleanThrow01)
{
    auto query = "yes: maybe;"sv;
    EXPECT_THROW({ extractBoolean(query, "yes"); }, std::runtime_error);
}

TEST(UtilsTest, extractBooleanThrow02)
{
    auto query = "yes: ;"sv;
    EXPECT_THROW({ extractBoolean(query, "yes"); }, std::runtime_error);
}

TEST(UtilsTest, extractBooleanThrow03)
{
    auto query = "yes: true"sv;
    EXPECT_THROW({ extractBoolean(query, "yes"); }, std::runtime_error);
}

TEST(UtilsTest, extractBooleanThrow04)
{
    auto query = "yes: ;"sv;
    EXPECT_THROW({ extractBoolean(query, "yes"); }, std::runtime_error);
}

TEST(UtilsTest, extractBooleanThrow05)
{
    auto query = ": true;"sv;
    EXPECT_THROW({ extractBoolean(query, "yes"); }, std::runtime_error);
}

TEST(UtilsTest, extractBooleanThrow06)
{
    auto query = "yes true;"sv;
    EXPECT_THROW({ extractBoolean(query, "yes"); }, std::runtime_error);
}

} // namespace Moonlight::Utils::Tests
