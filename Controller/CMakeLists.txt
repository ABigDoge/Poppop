#include_directories("${PROJECT_SOURCE_DIR}/DTO")
#include_directories("${PROJECT_SOURCE_DIR}/Service")

#AUX_SOURCE_DIRECTORY(. DIR_Controller_SRCS)
#ADD_LIBRARY(Controller ${DIR_Controller_SRCS})