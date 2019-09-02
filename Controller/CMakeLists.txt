AUX_SOURCE_DIRECTORY(. DIR_Controller_SRCS)
include_directories("${PROJECT_SOURCE_DIR}/DTO")
ADD_LIBRARY(Controller ${DIR_Controller_SRCS})
include_directories("${PROJECT_SOURCE_DIR}/Service")