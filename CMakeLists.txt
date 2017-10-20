cmake_minimum_required(VERSION 3.5.2)
project(Gielda)

message(${PROJECT_NAME})

include_directories(src)

set(	SRC_FILES
	"src/*.cpp"
)

file(GLOB SOURCES
	${SRC_FILES}
)

add_executable(${PROJECT_NAME} ${SOURCES})
set(EXECUTABLE_OUTPUT_PATH ../)
