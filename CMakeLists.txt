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

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules/")
find_package(SFML REQUIRED audio network graphics window system)

target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
