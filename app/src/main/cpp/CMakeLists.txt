cmake_minimum_required(VERSION 3.4.1)



include_directories( ${CMAKE_CURRENT_LIST_DIR}/ffmpeg/${CMAKE_ANDROID_ARCH_ABI}/include)

add_library(native-lib SHARED native-lib.cpp)

find_library(log-lib log)

target_link_libraries( # Specifies the target library.
                       native-lib

                       #增加ffmpeg库，注意顺序（具体看lib/pkgconfig的依赖关系）
#                       ${CMAKE_CURRENT_LIST_DIR}/../jniLibs/libavfilter.so
#                       ${CMAKE_CURRENT_LIST_DIR}/../jniLibs/libavformat.so
#                       ${CMAKE_CURRENT_LIST_DIR}/../jniLibs/libavcodec.so
#                       ${CMAKE_CURRENT_LIST_DIR}/../jniLibs/libswresample.so
#                       ${CMAKE_CURRENT_LIST_DIR}/../jniLibs/libswscale.so
#                       ${CMAKE_CURRENT_LIST_DIR}/../jniLibs/libavutil.so


                        ${CMAKE_CURRENT_LIST_DIR}/../jniLibs/libavfilter.a
                        ${CMAKE_CURRENT_LIST_DIR}/../jniLibs/libavformat.a
                        ${CMAKE_CURRENT_LIST_DIR}/../jniLibs/libavcodec.a
                        ${CMAKE_CURRENT_LIST_DIR}/../jniLibs/libswresample.a
                        ${CMAKE_CURRENT_LIST_DIR}/../jniLibs/libswscale.a
                        ${CMAKE_CURRENT_LIST_DIR}/../jniLibs/libavutil.a

        #增加ffmpeg所需要的依赖库
                       -lm -lz

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib}
                       )