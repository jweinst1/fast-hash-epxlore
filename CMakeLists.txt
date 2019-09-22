# Project fast hash main cmake file

cmake_minimum_required(VERSION 3.3)

project(fast_hash_explore)

# Disable some windows specific warnings for using more modern c functions
if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

# Options
option(WITH_testing "Allows tests to be run" ON)
option(WITH_verbose "Emits verbose output" OFF)

if(WITH_testing MATCHES ON)
   enable_testing()
endif(WITH_testing MATCHES ON)

if(WITH_verbose MATCHES ON)
   add_definitions(-DUSE_VERBOSE_MSGS)
endif(WITH_verbose MATCHES ON)

find_file(HAVE_STDINT_HEADER stdint.h)
if(HAVE_STDINT_HEADER)
   message("-- stdint.h header found")
   add_definitions(-DHAVE_STDINT_HEAD)
else(HAVE_STDINT_HEADER)
   message("-- stdint.h header not found")
endif(HAVE_STDINT_HEADER)

set(FAST_HASH_EXPLORE_SOURCES
   timer.c
)

add_library(fasthashlib STATIC "${FAST_HASH_EXPLORE_SOURCES}")

add_library(fasthashlibs SHARED "${FAST_HASH_EXPLORE_SOURCES}")
