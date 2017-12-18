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

add_subdirectory(${PROJECT_SOURCE_DIR}/src/main/cpp/Srcs/common)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/main/cpp/Srcs/jsonlib)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/main/cpp/Srcs/parser)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/main/cpp/Srcs/reader)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/main/cpp/Srcs/writer)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/main/cpp/Srcs/writerapp)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/main/cpp/Srcs/examples)# Do not build reader API usage examples by default
