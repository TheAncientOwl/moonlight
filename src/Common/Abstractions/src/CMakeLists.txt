add_library(MoonlightCommonTypes SHARED
    Types.cpp
)

target_link_libraries(MoonlightCommonTypes 
    PRIVATE MoonlightCommonUtils
)
