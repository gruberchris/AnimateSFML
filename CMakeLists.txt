cmake_minimum_required(VERSION 3.26)
project(AnimateSFML)

set(CMAKE_CXX_STANDARD 20)

include_directories(src resources)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")
file(GLOB_RECURSE RESOURCES "resources/*")
add_executable(${PROJECT_NAME} ${SOURCES} ${RESOURCES})

find_package(SFML 2.6 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)