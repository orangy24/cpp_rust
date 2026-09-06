cmake_minimum_required(VERSION 3.20)
project(cpp-rust-kata LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(KATA_SANITIZE "Enable ASan + UBSan (GCC/Clang)" ON)

include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.8.1
  GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(Catch2)

function(add_topic name)
  add_executable(${name} topics/${name}/test.cpp topics/${name}/kata.cpp)
  target_include_directories(${name} PRIVATE "${CMAKE_SOURCE_DIR}/topics/${name}")
  target_link_libraries(${name} PRIVATE Catch2::Catch2WithMain)
  if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(${name} PRIVATE -Wall -Wextra -Wpedantic)
    if(KATA_SANITIZE)
      target_compile_options(${name} PRIVATE -fsanitize=address,undefined)
      target_link_options(${name} PRIVATE -fsanitize=address,undefined)
    endif()
  endif()
endfunction()

function(add_topic_files name)
  add_executable(${name} ${ARGN})
  target_include_directories(${name} PRIVATE "${CMAKE_SOURCE_DIR}/topics")
  target_link_libraries(${name} PRIVATE Catch2::Catch2WithMain)
  if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(${name} PRIVATE -Wall -Wextra -Wpedantic)
    if(KATA_SANITIZE)
      target_compile_options(${name} PRIVATE -fsanitize=address,undefined)
      target_link_options(${name} PRIVATE -fsanitize=address,undefined)
    endif()
  endif()
endfunction()

add_topic(signatures)
add_topic(raii-loans)
add_topic(views)
add_topic(qos)
add_topic(templates)
add_topic(static-poly)
add_topic(policies)
add_topic(type-erasure)
add_topic(pubsub)
add_topic(nodes)
add_topic(abi)
add_topic(memory)

add_topic_files(policies-serialize
  topics/policies/serialize_test.cpp topics/policies/serialize.cpp)
target_include_directories(policies-serialize PRIVATE
  "${CMAKE_SOURCE_DIR}/topics/policies")

add_topic_files(concurrency-queue
  topics/concurrency/queue_test.cpp topics/concurrency/queue.cpp)
target_include_directories(concurrency-queue PRIVATE
  "${CMAKE_SOURCE_DIR}/topics/concurrency")

add_topic_files(concurrency-executor
  topics/concurrency/executor_test.cpp topics/concurrency/executor.cpp)
target_include_directories(concurrency-executor PRIVATE
  "${CMAKE_SOURCE_DIR}/topics/concurrency")

add_executable(practice practice/tests.cpp)
target_link_libraries(practice PRIVATE Catch2::Catch2WithMain)
add_executable(practice-sandbox practice/sandbox.cpp)
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
  foreach(t IN ITEMS practice practice-sandbox)
    target_compile_options(${t} PRIVATE -Wall -Wextra -Wpedantic)
    if(KATA_SANITIZE)
      target_compile_options(${t} PRIVATE -fsanitize=address,undefined)
      target_link_options(${t} PRIVATE -fsanitize=address,undefined)
    endif()
  endforeach()
endif()
