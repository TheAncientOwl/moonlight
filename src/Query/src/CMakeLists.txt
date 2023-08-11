add_library(MoonlightQuery SHARED
    QueryParser.cpp
    QueryObject.cpp
    
    Parsers/RegexBuilder.cpp
    
    Parsers/StructureDropParser.cpp
    Parsers/StructureCreateParser.cpp
    Parsers/StructureRenameParser.cpp
    Parsers/DatabaseParser.cpp
    Parsers/IndexParser.cpp
    Parsers/StructureMigrateParser.cpp
    Parsers/SchemaParser.cpp
    Parsers/StructureDeleteParser.cpp
    Parsers/StructureUpdateParser.cpp
    Parsers/StructureSelectParser.cpp
    Parsers/ViewParser.cpp
)

target_link_libraries(MoonlightQuery PRIVATE
    MoonlightPrimitives
)
