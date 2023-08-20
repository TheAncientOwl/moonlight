#include <gtest/gtest.h>

#include "Utils.hpp"

namespace Moonlight::Utils::Tests {

using namespace std::literals;

TEST(UtilsTest, extractValueSuccess01)
{
    auto query = "  structure: StructureName; some other string"sv;
    auto value = extractValue(query, "structure");

    auto expected_value = "StructureName"sv;
    auto expected_query = " some other string"sv;

    EXPECT_EQ(query, expected_query);
    EXPECT_EQ(value, expected_value);
}

TEST(UtilsTest, extractValueSuccess02)
{
    auto query = "  structure:       StructureName; some other string"sv;
    auto value = extractValue(query, "structure");

    auto expected_value = "StructureName"sv;
    auto expected_query = " some other string"sv;

    EXPECT_EQ(query, expected_query);
    EXPECT_EQ(value, expected_value);
}

TEST(UtilsTest, extractValueSuccess03)
{
    auto query = "  structure: StructureName;"sv;
    auto value = extractValue(query, "structure");

    auto expected_value = "StructureName"sv;
    auto expected_query = ""sv;

    EXPECT_EQ(query, expected_query);
    EXPECT_EQ(value, expected_value);
}

TEST(UtilsTest, extractValueThrow01)
{
    EXPECT_THROW({
        auto query = "  ssstructure: StructureName; some other string"sv;
        extractValue(query, "structure");
        }, std::runtime_error);
}

TEST(UtilsTest, extractValueThrow02)
{
    EXPECT_THROW({
        auto query = "  structure:"sv;
        extractValue(query, "structure");
        }, std::runtime_error);
}

TEST(UtilsTest, extractValueThrow03)
{
    EXPECT_THROW({
        auto query = "  structure SomeStructure"sv;
        extractValue(query, "structure");
        }, std::runtime_error);
}

TEST(UtilsTest, extractValueThrow04)
{
    EXPECT_THROW({
        auto query = "  structure: StructureName some other string"sv;
        extractValue(query, "structure");
        }, std::runtime_error);
}

TEST(UtilsTest, extractValueThrow05)
{
    EXPECT_THROW({
        auto query = "  structure: ; some other string"sv;
        extractValue(query, "structure");
        }, std::runtime_error);
}

} // namespace Moonlight::Utils::Tests
