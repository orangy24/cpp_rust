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

function(add_week week)
  add_executable(${week} weeks/${week}/test.cpp weeks/${week}/kata.cpp)
  target_include_directories(${week} PRIVATE "${CMAKE_SOURCE_DIR}/weeks/${week}")
  target_link_libraries(${week} PRIVATE Catch2::Catch2WithMain)
  if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(${week} PRIVATE -Wall -Wextra -Wpedantic)
    if(KATA_SANITIZE)
      target_compile_options(${week} PRIVATE -fsanitize=address,undefined)
      target_link_options(${week} PRIVATE -fsanitize=address,undefined)
    endif()
  endif()
endfunction()

add_week(week01)
add_week(week02)
add_week(week03)
add_week(week04)
add_week(week05)
add_week(week06)
add_week(week07)
add_week(week08)
add_week(week09)
add_week(week10)
add_week(week11)
add_week(week12)
add_week(week13)
add_week(week14)
