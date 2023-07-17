#include <gtest/gtest.h>

#include "Types.hpp"

namespace Moonlight::Common::Types::Test {

TEST(CommonTypesTest, StructureTypes)
{
    using EStructureTypes = StructureTypes::EValue;

    using namespace StructureTypes;

    ASSERT_EQ(EStructureTypes::Document, toEnum(toString(EStructureTypes::Document)));
    ASSERT_EQ(EStructureTypes::Table, toEnum(toString(EStructureTypes::Table)));
    ASSERT_EQ(EStructureTypes::None, toEnum(toString(EStructureTypes::None)));
}

} // namespace Moonlight::Common::Utils::Test
