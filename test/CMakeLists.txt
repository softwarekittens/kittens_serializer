cmake_minimum_required(VERSION 3.2)
project(kittens_serializer_test)

set (CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES test.cpp test.h ../kittens/serializer.h ../kittens/impl/serializer_impl.h)

add_executable(kittens_serializer_test ${SOURCE_FILES})
target_include_directories(kittens_serializer_test PRIVATE "msgpack-c/include")