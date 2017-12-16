cmake_minimum_required(VERSION 3.4.1)

set(distribution_DIR ${CMAKE_SOURCE_DIR}/../distribution)

# set add lib
add_library(libheif SHARED IMPORTED)
set_target_properties(libheif PROPERTIES IMPORTED_LOCATION
                      ${distribution_DIR}/libs/${ANDROID_ABI}/libheif.so)
include_directories(libheif
                    ${distribution_DIR}/include)

add_library(native-math SHARED
            src/main/cpp/native-math.cpp)
set_target_properties(native-math PROPERTIES
                      LIBRARY_OUTPUT_DIRECTORY ${distribution_DIR}/libs/${ANDROID_ABI})
target_link_libraries(native-math
                      android
                      libheif
                      log)


# 加入头文件
target_include_directories(native-math PRIVATE
                           ${distribution_DIR}/add/include
                           ${distribution_DIR}/add/include)
