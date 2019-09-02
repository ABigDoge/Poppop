cmake_minimum_required(VERSION 2.6)
PROJECT(hello)
add_subdirectory(DTO)
add_subdirectory(Service)

aux_source_directory(. DIR_SRCS)
add_executable(hello ${DIR_SRCS})
link_directories(/usr/lib/x86_64-linux-gnu)

include_directories("${PROJECT_SOURCE_DIR}/DTO")
include_directories("${PROJECT_SOURCE_DIR}/Service")
add_library(connector STATIC IMPORTED)
#add_library(pthread STATIC IMPORTED)
set_property(TARGET connector PROPERTY IMPORTED_LOCATION /usr/local/lib/libsqlpp-mysql.a)
#option(ENABLE_PIC "Generate position independent code (necessary for shared libraries)" TRUE)
#set(CMAKE_POSITION_INDEPENDENT_CODE ${ENABLE_PIC})

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -no-pie")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -no-pie")
#add_compile_options("-fPIC")
#set(CMAKE_C_FLAGS "-fPIC")
#set(CMAKE_CXX_FLAGS "-fPIC")
#target_link_libraries(hello Service Controller connector pthread libmysqlclient.so )

#add_definitions("-lpthread")
#set_property(TARGET pthread PROPERTY IMPORTED_LOCATION /usr/lib/x86_64-linux-gnu/libpthread.a)
target_link_libraries(hello connector Service libmysqlclient.so)
target_link_libraries(hello -pthread)


