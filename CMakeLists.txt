cmake_minimum_required(VERSION 3.10)

project(vector VERSION 1.0 )

set(FLAGS -Wall -Wextra -Werror -pedantic -Wconversion -O3)

set(SRC 
    tests/main.ut.cpp
    tests/vector.ut.cpp    
)

add_executable(${PROJECT_NAME}-ut ${SRC} )

target_compile_options(${PROJECT_NAME}-ut PRIVATE ${FLAGS})

target_compile_features(${PROJECT_NAME}-ut PRIVATE cxx_std_17)