include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../Primitives)

add_library(MoonlightQuery SHARED
    QueryParser.cpp
    QueryObject.cpp
    
    SchemaFieldParsers.cpp
    ParsedQueryHelpers.cpp

    DropParser.cpp
    CreateParser.cpp
    RenameParser.cpp
    DatabaseParser.cpp
    IndexParser.cpp
    MigrateParser.cpp
    SchemaParser.cpp
    DeleteParser.cpp
    UpdateParser.cpp
    SelectParser.cpp
    ViewParser.cpp
    InsertParser.cpp
)

target_link_libraries(MoonlightQuery PRIVATE
    MoonlightPrimitives
    MoonlightUtils
)
