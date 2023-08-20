#include <gtest/gtest.h>

#include "Utils.hpp"

namespace Moonlight::Utils::Tests {

using namespace std::literals;

TEST(UtilsTest, cleanupQuerySuccess01)
{
    auto query = "someQuery { content };"sv;
    cleanupQuery(query, "someQuery");
    ASSERT_EQ("content"sv, query);
}

TEST(UtilsTest, cleanupQuerySuccess02)
{
    auto query = "someQuery         {        content         }      ;"sv;
    cleanupQuery(query, "someQuery");
    ASSERT_EQ("content"sv, query);
}

TEST(UtilsTest, cleanupQueryThrow01)
{
    auto query = "someQuery { content }"sv;
    EXPECT_THROW({ cleanupQuery(query, "someQuery"); }, std::runtime_error);
}

TEST(UtilsTest, cleanupQueryThrow02)
{
    auto query = "someQuery { content ;"sv;
    EXPECT_THROW({ cleanupQuery(query, "someQuery"); }, std::runtime_error);
}

TEST(UtilsTest, cleanupQueryThrow03)
{
    auto query = "someQuery  content };"sv;
    EXPECT_THROW({ cleanupQuery(query, "someQuery"); }, std::runtime_error);
}

TEST(UtilsTest, cleanupQueryThrow04)
{
    auto query = "{ content };"sv;
    EXPECT_THROW({ cleanupQuery(query, "someQuery"); }, std::runtime_error);
}

TEST(UtilsTest, cleanupQueryThrow05)
{
    auto query = "someQuery {  };"sv;
    EXPECT_THROW({ cleanupQuery(query, "someQuery"); }, std::runtime_error);
}

TEST(UtilsTest, cleanupQueryThrow06)
{
    auto query = "someQuery {};"sv;
    EXPECT_THROW({ cleanupQuery(query, "someQuery"); }, std::runtime_error);
}

} // namespace Moonlight::Utils::Tests
