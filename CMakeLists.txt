cmake_minimum_required(VERSION 3.16)
project(events)

set(CMAKE_CXX_STANDARD 17)

add_executable( events 
${PROJECT_SOURCE_DIR}/src/main.cpp
${PROJECT_SOURCE_DIR}/src/BookStore/Customers.cpp
${PROJECT_SOURCE_DIR}/src/BookStore/Stock.cpp

)

target_include_directories(events PUBLIC ${PROJECT_SOURCE_DIR}/src )