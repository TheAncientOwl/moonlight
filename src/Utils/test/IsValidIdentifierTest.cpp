#include <gtest/gtest.h>

#include "Utils.hpp"

namespace Moonlight::Utils::Tests {

TEST(UtilsTest, isValidIdentifierTrue01)
{
    ASSERT_TRUE(isValidIdentifier("SomeIdentifier_09"));
}

TEST(UtilsTest, isValidIdentifierTrue02)
{
    ASSERT_TRUE(isValidIdentifier("_SomeIdentifier_09"));
}

TEST(UtilsTest, isValidIdentifierTrue03)
{
    ASSERT_TRUE(isValidIdentifier("_Some_Identi0fier_09"));
}

TEST(UtilsTest, isValidIdentifierTrue04)
{
    ASSERT_TRUE(isValidIdentifier("_Some_Identi0fier_09"));
}

TEST(UtilsTest, isValidIdentifierFalse01)
{
    ASSERT_FALSE(isValidIdentifier("  _Some_Identi0fier_09"));
}

TEST(UtilsTest, isValidIdentifierFalse02)
{
    ASSERT_FALSE(isValidIdentifier("_Some_Ide-nti0fier_09"));
}

TEST(UtilsTest, isValidIdentifierFalse03)
{
    ASSERT_FALSE(isValidIdentifier("_Some_Ide  nti0fier_09"));
}

TEST(UtilsTest, isValidIdentifierFalse04)
{
    ASSERT_FALSE(isValidIdentifier("_Some_Identi0fier_09@"));
}

TEST(UtilsTest, isValidIdentifierFalse05)
{
    ASSERT_FALSE(isValidIdentifier("_Some_Identi0fie$r_09"));
}

} // namespace Moonlight::Utils::Tests
