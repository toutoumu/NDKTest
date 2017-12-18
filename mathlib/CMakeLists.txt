cmake_minimum_required(VERSION 3.4.1)
add_library(add SHARED
            src/main/cpp/add.cpp)
set(distribution_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../distribution1)
set_target_properties(add PROPERTIES
                      LIBRARY_OUTPUT_DIRECTORY
                      ${distribution_DIR}/libs/${ANDROID_ABI})
target_include_directories(add
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/main/cpp)

# 复制头文件
add_custom_command(TARGET add POST_BUILD
                   COMMAND "${CMAKE_COMMAND}" -E
                   copy "${CMAKE_CURRENT_SOURCE_DIR}/src/main/cpp/add.h"
                   "${distribution_DIR}/add/include/add.h"
#                   **** the following 2 lines are for potential future debug purpose ****
#                   COMMAND "${CMAKE_COMMAND}" -E
#                   remove_directory "${CMAKE_CURRENT_BINARY_DIR}"
                   COMMENT "Copying add to output directory")
