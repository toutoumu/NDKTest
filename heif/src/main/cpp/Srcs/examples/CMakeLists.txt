# Copyright (c) 2015, Nokia Technologies Ltd.
# All rights reserved.
#
# Licensed under the Nokia High-Efficiency Image File Format (HEIF) License (the "License").
#
# You may not use the High-Efficiency Image File Format except in compliance with the License.
# The License accompanies the software and can be found in the file "LICENSE.TXT".
#
# You may also obtain the License at:
# https://nokiatech.github.io/heif/license.txt

include_directories(${PROJECT_SOURCE_DIR}/src/main/cpp/Srcs/common)
include_directories(${PROJECT_SOURCE_DIR}/src/main/cpp/Srcs/reader)
include_directories(${PROJECT_SOURCE_DIR}/src/main/cpp/Srcs/jsonlib)
include_directories(${PROJECT_SOURCE_DIR}/src/main/cpp/Srcs/parser)
include_directories(${PROJECT_SOURCE_DIR}/src/main/cpp/Srcs/writer)

set(EXAMPLE_SRCS
    example.cpp
    native-math.cpp)

# add_executable(${EXAMPLE_EXE} ${EXAMPLE_SRCS})


add_library(heif SHARED ${EXAMPLE_SRCS})

set(distribution_DIR ${PROJECT_SOURCE_DIR})

message(STATUS "我靠       : ${distribution_DIR}")


set_target_properties(heif PROPERTIES
                      LIBRARY_OUTPUT_DIRECTORY
                      ${distribution_DIR}/libs/${ANDROID_ABI})

target_link_libraries(heif reader writer)
