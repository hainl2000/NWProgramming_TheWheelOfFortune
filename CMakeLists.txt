cmake_minimum_required(VERSION 3.21)
project(LTM_Project C)

set(CMAKE_C_STANDARD 99)

add_executable(LTM_Project main.c View/library/structScreen.h View/library/InitScreen.h View/src/InitScreen.c View/library/LoginController.h Handle/library/constant.h Handle/library/handleMain.h Handle/library/InitClient.h Handle/src/InitClient.c View/src/LoginController.c Handle/src/HandleMain.c View/library/mainController.h View/src/mainController.c View/library/gameController.h View/src/gameController.c View/library/roomController.h View/src/roomController.c Handle/library/handleLogin.h Handle/src/handleLogin.c Handle/library/handleThread.h Handle/library/clientError.h Handle/src/handleRecvData.c Handle/library/handleRecvData.h)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(SOURCE_FILES main.c)
file(GLOB SOURCES "View/src/*.c" "Handle/src/*.c")


add_executable(SOURCE_FILES ${SOURCES})
add_executable(LTM_Project${SOURCE_FILES} ${SOURCES})
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(View/library Handle/library)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})
target_link_libraries(LTM_Project ${GTK3_LIBRARIES})
target_link_libraries(LTM_Project Threads::Threads)