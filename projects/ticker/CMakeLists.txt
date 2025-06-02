cmake_minimum_required(VERSION 3.16)
project(ticker)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(QPC_ROOT "${CMAKE_SOURCE_DIR}/qpc" CACHE PATH "Path to QP/C framework")

find_package(Threads REQUIRED)

file(GLOB QPC_SOURCES
  ${QPC_ROOT}/src/qf/*.c
  ${QPC_ROOT}/src/qs/*.c
  ${QPC_ROOT}/ports/posix/qf_port.c
)

set(APP_SOURCES
  src/main.c
  src/ping.c
  include/bsp.c
)

add_executable(${PROJECT_NAME} ${APP_SOURCES} ${QPC_SOURCES})

target_include_directories(
  ${PROJECT_NAME} PRIVATE
  ${QPC_ROOT}/include
  ${QPC_ROOT}/ports/posix
  ${CMAKE_CURRNET_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} Threads::Threads)

target_compile_options(${PROJECT_NAME} PRIVATE
  -Wall
  -Wextra
  -O2
)
