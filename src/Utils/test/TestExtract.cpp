#include <gtest/gtest.h>

#include "Utils.hpp"

namespace Moonlight::Utils::Tests {

using namespace std::literals;

TEST(UtilsTest, isValidIdentifier)
{
    ASSERT_TRUE(isValidIdentifier("SomeIdentifier_09"));
    ASSERT_TRUE(isValidIdentifier("_SomeIdentifier_09"));
    ASSERT_TRUE(isValidIdentifier("_Some_Identi0fier_09"));
    ASSERT_TRUE(isValidIdentifier("_Some_Identi0fier_09"));

    ASSERT_FALSE(isValidIdentifier("  _Some_Identi0fier_09"));
    ASSERT_FALSE(isValidIdentifier("_Some_Ide-nti0fier_09"));
    ASSERT_FALSE(isValidIdentifier("_Some_Ide  nti0fier_09"));
    ASSERT_FALSE(isValidIdentifier("_Some_Identi0fier_09@"));
    ASSERT_FALSE(isValidIdentifier("_Some_Identi0fie$r_09"));
}

TEST(UtilsTest, extractIdentifierSuccess)
{
    {
        auto query = "name: SomeIdentifier_09;"sv;
        ASSERT_EQ("SomeIdentifier_09"sv, extractIdentifier(query, "name"));
    }
    {
        auto query = "name: _SomeIdentifier_09;"sv;
        ASSERT_EQ("_SomeIdentifier_09"sv, extractIdentifier(query, "name"));
    }
    {
        auto query = "name: _Some_Identi0fier_09;"sv;
        ASSERT_EQ("_Some_Identi0fier_09"sv, extractIdentifier(query, "name"));
    }
    {
        auto query = "name: _Some_Identi0fier_09;"sv;
        ASSERT_EQ("_Some_Identi0fier_09"sv, extractIdentifier(query, "name"));
    }
}

TEST(UtilsTest, extractIdentifierThrow)
{
    {
        auto query = "name: SomeIdentifier_09"sv;
        EXPECT_THROW({ extractIdentifier(query, "name"); }, std::runtime_error);
    }
    {
        auto query = "name SomeIdentifier_09;"sv;
        EXPECT_THROW({ extractIdentifier(query, "name"); }, std::runtime_error);
    }
    {
        auto query = ": SomeIdentifier_09;"sv;
        EXPECT_THROW({ extractIdentifier(query, "name"); }, std::runtime_error);
    }
    {
        auto query = "name:;"sv;
        EXPECT_THROW({ extractIdentifier(query, "name"); }, std::runtime_error);
    }
    {
        auto query = "name:"sv;
        EXPECT_THROW({ extractIdentifier(query, "name"); }, std::runtime_error);
    }
}

TEST(UtilsTest, extractBooleanSuccess)
{
    {
        auto query = "yes: true;"sv;
        ASSERT_EQ(true, extractBoolean(query, "yes"));
    }
    {
        auto query = "yes: false;"sv;
        ASSERT_EQ(false, extractBoolean(query, "yes"));
    }
}

TEST(UtilsTest, extractBooleanThrow)
{
    {
        auto query = "yes: maybe;"sv;
        EXPECT_THROW({ extractBoolean(query, "yes"); }, std::runtime_error);
    }
    {
        auto query = "yes: ;"sv;
        EXPECT_THROW({ extractBoolean(query, "yes"); }, std::runtime_error);
    }
    {
        auto query = "yes: true"sv;
        EXPECT_THROW({ extractBoolean(query, "yes"); }, std::runtime_error);
    }
    {
        auto query = "yes: ;"sv;
        EXPECT_THROW({ extractBoolean(query, "yes"); }, std::runtime_error);
    }
    {
        auto query = ": true;"sv;
        EXPECT_THROW({ extractBoolean(query, "yes"); }, std::runtime_error);
    }
    {
        auto query = "yes true;"sv;
        EXPECT_THROW({ extractBoolean(query, "yes"); }, std::runtime_error);
    }
}

TEST(UtilsTest, cleanupQuerySuccess)
{
    {
        auto query = "someQuery { content };"sv;
        cleanupQuery(query, "someQuery");
        ASSERT_EQ("content"sv, query);
    }
    {
        auto query = "someQuery         {        content         }      ;"sv;
        cleanupQuery(query, "someQuery");
        ASSERT_EQ("content"sv, query);
    }
}

TEST(UtilsTest, cleanupQueryThrow)
{
    {
        auto query = "someQuery { content }"sv;
        EXPECT_THROW({ cleanupQuery(query, "someQuery"); }, std::runtime_error);
    }
    {
        auto query = "someQuery { content ;"sv;
        EXPECT_THROW({ cleanupQuery(query, "someQuery"); }, std::runtime_error);
    }
    {
        auto query = "someQuery  content };"sv;
        EXPECT_THROW({ cleanupQuery(query, "someQuery"); }, std::runtime_error);
    }
    {
        auto query = "{ content };"sv;
        EXPECT_THROW({ cleanupQuery(query, "someQuery"); }, std::runtime_error);
    }
    {
        auto query = "someQuery {  };"sv;
        EXPECT_THROW({ cleanupQuery(query, "someQuery"); }, std::runtime_error);
    }
}

} // namespace Moonlight::Utils::Tests
