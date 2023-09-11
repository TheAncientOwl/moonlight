function(create_test_executable TARGET_NAME SOURCE_FILES)
    add_executable(${TARGET_NAME} ${SOURCE_FILES} ParsedQueriesInit.cpp)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

    target_link_libraries(${TARGET_NAME} PRIVATE
        gtest
        gtest_main
        MoonlightQuery
    )

    include(GoogleTest)
    gtest_discover_tests(${TARGET_NAME})
endfunction()

create_test_executable(CreateParserTest CreateParserTest.cpp)
create_test_executable(DatabaseParserTest DatabaseParserTest.cpp)
create_test_executable(DeleteParserTest DeleteParserTest.cpp)
create_test_executable(DropParserTest DropParserTest.cpp)

create_test_executable(FieldParserBooleanTest FieldParserBooleanTest.cpp)
create_test_executable(FieldParserDateTimeTest FieldParserDateTimeTest.cpp)
create_test_executable(FieldParserDecimalTest FieldParserDecimalTest.cpp)
create_test_executable(FieldParserIntegerTest FieldParserIntegerTest.cpp)
create_test_executable(FieldParserReferenceTest FieldParserReferenceTest.cpp)
create_test_executable(FieldParserStringTest FieldParserStringTest.cpp)

create_test_executable(IndexParserTest IndexParserTest.cpp)
create_test_executable(MigrateParserTest MigrateParserTest.cpp)

create_test_executable(QueryObjectTest QueryObjectTest.cpp)

create_test_executable(RenameParserTest RenameParserTest.cpp)
create_test_executable(SchemaParserTest SchemaParserTest.cpp)
create_test_executable(UpdateParserTest UpdateParserTest.cpp)
create_test_executable(SelectParserTest SelectParserTest.cpp)
create_test_executable(InsertParserTest InsertParserTest.cpp)
