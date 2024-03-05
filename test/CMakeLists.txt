set(TEST_NAME ${PROJECT_NAME}-Test)

find_package(GTest REQUIRED)

set(SOURCE_FILES test.cpp exampleTest.cpp)

add_executable(${TEST_NAME} ${SOURCE_FILES})
target_link_libraries(${TEST_NAME} GTest::gtest_main)
set_target_properties(${TEST_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${BIN_DIR}")

include(GoogleTest)
gtest_discover_tests(${TEST_NAME})
