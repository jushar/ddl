cmake_minimum_required(VERSION 3.17)
project(ddl LANGUAGES CXX)

add_library(ddl STATIC
    "src/drivers/ST/ST_I2C.cpp"
    "src/drivers/LPS22DF.cpp" # TODO: One CMake target per driver?
)
target_include_directories(ddl PUBLIC "include")

add_subdirectory(src/fakes)

add_subdirectory(examples)

add_subdirectory(third_party/Catch2)
add_subdirectory(tests)
