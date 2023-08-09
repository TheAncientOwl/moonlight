add_library(MoonlightCommonQueryObject SHARED
    QueryObject.cpp
)

target_link_libraries(MoonlightCommonQueryObject PRIVATE
    MoonlightCommonPrimitives
)
