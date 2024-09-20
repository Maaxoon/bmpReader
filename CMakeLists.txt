cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME drawBmp)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} 
	drawBmp.cpp
	BMPReader.h
	BMPReader.cpp
	BMPReaderLib.h
)