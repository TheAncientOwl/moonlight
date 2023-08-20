#include <gtest/gtest.h>

#include "Utils.hpp"

namespace Moonlight::Utils::Tests {

using namespace std::literals;

TEST(UtilsTest, extractIdentifierSuccess01)
{
    auto query = "name: SomeIdentifier_09;"sv;
    ASSERT_EQ("SomeIdentifier_09"sv, extractIdentifier(query, "name"));
}

TEST(UtilsTest, extractIdentifierSuccess02)
{
    auto query = "name: _SomeIdentifier_09;"sv;
    ASSERT_EQ("_SomeIdentifier_09"sv, extractIdentifier(query, "name"));
}

TEST(UtilsTest, extractIdentifierSuccess03)
{
    auto query = "name: _Some_Identi0fier_09;"sv;
    ASSERT_EQ("_Some_Identi0fier_09"sv, extractIdentifier(query, "name"));
}

TEST(UtilsTest, extractIdentifierSuccess04)
{
    auto query = "name: _Some_Identi0fier_09;"sv;
    ASSERT_EQ("_Some_Identi0fier_09"sv, extractIdentifier(query, "name"));
}

TEST(UtilsTest, extractIdentifierThrow01)
{
    auto query = "name: SomeIdentifier_09"sv;
    EXPECT_THROW({ extractIdentifier(query, "name"); }, std::runtime_error);
}

TEST(UtilsTest, extractIdentifierThrow02)
{
    auto query = "name SomeIdentifier_09;"sv;
    EXPECT_THROW({ extractIdentifier(query, "name"); }, std::runtime_error);
}

TEST(UtilsTest, extractIdentifierThrow03)
{
    auto query = ": SomeIdentifier_09;"sv;
    EXPECT_THROW({ extractIdentifier(query, "name"); }, std::runtime_error);
}

TEST(UtilsTest, extractIdentifierThrow04)
{
    auto query = "name:;"sv;
    EXPECT_THROW({ extractIdentifier(query, "name"); }, std::runtime_error);
}

TEST(UtilsTest, extractIdentifierThrow05)
{
    auto query = "name:"sv;
    EXPECT_THROW({ extractIdentifier(query, "name"); }, std::runtime_error);
}

} // namespace Moonlight::Utils::Tests
