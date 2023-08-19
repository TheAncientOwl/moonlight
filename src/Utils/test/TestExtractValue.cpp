#include <gtest/gtest.h>

#include "Utils.hpp"

namespace Moonlight::Utils::Tests {

using namespace std::literals;

TEST(MoonlightUtilsTest, extractValueNoThrow)
{
    {
        auto query = "  structure: StructureName; some other string"sv;
        auto value = extractValue(query, "structure");

        auto expected_value = "StructureName"sv;
        auto expected_query = " some other string"sv;

        EXPECT_EQ(query, expected_query);
        EXPECT_EQ(value, expected_value);
    }

    {
        auto query = "  structure:       StructureName; some other string"sv;
        auto value = extractValue(query, "structure");

        auto expected_value = "StructureName"sv;
        auto expected_query = " some other string"sv;

        EXPECT_EQ(query, expected_query);
        EXPECT_EQ(value, expected_value);
    }

    {
        auto query = "  structure: StructureName;"sv;
        auto value = extractValue(query, "structure");

        auto expected_value = "StructureName"sv;
        auto expected_query = ""sv;

        EXPECT_EQ(query, expected_query);
        EXPECT_EQ(value, expected_value);
    }
}

TEST(MoonlightUtilsTest, extractValueThrow)
{
    EXPECT_THROW({
        try
        {
            auto query = "  ssstructure: StructureName; some other string"sv;
            extractValue(query, "structure");
        }
        catch (const std::runtime_error& e)
        {
            ASSERT_TRUE(startsWithIgnoreCase(e.what(), "Invalid query, missing"));
            throw e;
        }
        }, std::runtime_error);

    EXPECT_THROW({
        try
        {
            auto query = "  structure:"sv;
            extractValue(query, "structure");
        }
        catch (const std::runtime_error& e)
        {
            ASSERT_TRUE(startsWithIgnoreCase(e.what(), "Missing value for keyword"));
            throw e;
        }
        }, std::runtime_error);

    EXPECT_THROW({
        try
        {
            auto query = "  structure SomeStructure"sv;
            extractValue(query, "structure");
        }
        catch (const std::runtime_error& e)
        {
            ASSERT_TRUE(startsWithIgnoreCase(e.what(), "Missing ':' symbol"));
            throw e;
        }
        }, std::runtime_error);

    EXPECT_THROW({
        try
        {
            auto query = "  structure: StructureName some other string"sv;
            extractValue(query, "structure");
        }
        catch (const std::runtime_error& e)
        {
            ASSERT_TRUE(startsWithIgnoreCase(e.what(), "Missing ';'"));
            throw e;
        }
        }, std::runtime_error);

    EXPECT_THROW({
        try
        {
            auto query = "  structure: ; some other string"sv;
            extractValue(query, "structure");
        }
        catch (const std::runtime_error& e)
        {
            ASSERT_TRUE(startsWithIgnoreCase(e.what(), "Value cannot be empty"));
            throw e;
        }
        }, std::runtime_error);
}

} // namespace Moonlight::Utils::Tests
