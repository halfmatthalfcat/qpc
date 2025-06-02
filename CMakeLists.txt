cmake_minimum_required(VERSION 3.16)
project(qpc)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB SUBDIRS RELATIVE ${CMAKE_SOURCE_DIR} projects/*)

foreach(SUBDIR ${SUBDIRS})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR})
        if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR}/CMakeLists.txt)
            add_subdirectory(${SUBDIR})
        endif()
    endif()
endforeach()