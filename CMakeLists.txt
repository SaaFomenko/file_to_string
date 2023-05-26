cmake_minimum_required(VERSION 3.5)

project(file_to_string 
	VERSION 1.0.0
	DESCRIPTION "C++ library with functions for return one string of file."
	LANGUAGES CXX)

file(GLOB
	public_headers "*.h"
	sources "*.cpp")

add_library(${PROJECT_NAME}_lib ${sources} ${public_headers})
