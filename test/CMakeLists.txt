cmake_minimum_required(VERSION 3.18)

project(test_file_to_string)

find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main
# add_executable(tests test.cpp)
# target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

file(GLOB
	file_to_string "../*.cpp"
	app_exceptin "../lib/app_exception/*.cpp")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(app_config_lib STATIC 
	${file_to_string}
	${app_exception})

# These tests need their own main
add_executable(tests test-main.cpp
	${file_to_string}
	${app_exception})

target_link_libraries(tests PRIVATE Catch2::Catch2)
