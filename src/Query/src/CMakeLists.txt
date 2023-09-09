add_library(MoonlightQuery SHARED
    QueryParser.cpp
    QueryObject.cpp
    
    helpers/SchemaFieldParsers.cpp
    helpers/ParsedQueryHelpers.cpp

    helpers/DropParser.cpp
    helpers/CreateParser.cpp
    helpers/RenameParser.cpp
    helpers/DatabaseParser.cpp
    helpers/IndexParser.cpp
    helpers/MigrateParser.cpp
    helpers/SchemaParser.cpp
    helpers/DeleteParser.cpp
    helpers/UpdateParser.cpp
    helpers/SelectParser.cpp
    helpers/ViewParser.cpp
    helpers/InsertParser.cpp
)

target_link_libraries(MoonlightQuery PRIVATE
    MoonlightPrimitives
    MoonlightUtils
)
