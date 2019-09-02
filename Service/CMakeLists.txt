AUX_SOURCE_DIRECTORY(. DIR_Service_SRCS)
include_directories("${PROJECT_SOURCE_DIR}/DTO")
ADD_LIBRARY(Service ${DIR_Service_SRCS})