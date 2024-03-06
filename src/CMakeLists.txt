find_package(Boost REQUIRED)

if(Boost_FOUND)
    add_executable(${PROJECT_NAME} main.cpp Client.cpp MainNode.cpp)
    target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()