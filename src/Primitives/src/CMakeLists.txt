add_library(MoonlightPrimitives SHARED
    Primitives.cpp
)

target_link_libraries(MoonlightPrimitives PRIVATE
    MoonlightUtils
)
