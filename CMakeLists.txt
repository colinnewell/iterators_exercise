cmake_minimum_required(VERSION 3.1)
project(iterators_exercise)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS Off)

add_executable(test_basic_iterator
    test/catch_main.cpp
    test/test_basic_iterator.cpp
)

add_executable(test_input_iterator
    test/catch_main.cpp
    test/test_basic_iterator.cpp
    test/test_input_iterator.cpp
)

add_executable(test_forward_iterator
    test/catch_main.cpp
    test/test_basic_iterator.cpp
    test/test_input_iterator.cpp
    test/test_forward_iterator.cpp
)

add_executable(test_bidir_iterator
    test/catch_main.cpp
    test/test_basic_iterator.cpp
    test/test_input_iterator.cpp
    test/test_forward_iterator.cpp
    test/test_bidir_iterator.cpp
)