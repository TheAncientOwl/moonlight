add_library(MoonlightQuery SHARED
    QueryParser.cpp
    QueryObject.cpp
    
    Parsers/SchemaFieldParsers.cpp

    Parsers/DropParser.cpp
    Parsers/CreateParser.cpp
    Parsers/RenameParser.cpp
    Parsers/DatabaseParser.cpp
    Parsers/IndexParser.cpp
    Parsers/MigrateParser.cpp
    Parsers/SchemaParser.cpp
    Parsers/DeleteParser.cpp
    Parsers/UpdateParser.cpp
    Parsers/SelectParser.cpp
    Parsers/ViewParser.cpp
)

target_link_libraries(MoonlightQuery PRIVATE
    MoonlightPrimitives
    MoonlightUtils
)
