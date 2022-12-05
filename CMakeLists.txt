cmake_minimum_required(VERSION 3.17)
project(GamakEngineProject VERSION 2.0)

#cool_folder
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_scripts/cmake_scripts.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/sources/sources.cmake)

get_sources(SOURCES_LIST ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(${PROJECT_NAME} ${SOURCES_LIST})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/sources)
#cool_folder

#sfml

set(SFML_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libraries/SFML-2.5.1_W-64)
set(SFML_DIR ${SFML_ROOT_DIR}/lib/cmake/SFML)

find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-network sfml-graphics sfml-audio)
#sfml


set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/$<0:>)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX _V${CMAKE_PROJECT_VERSION}_${Configuration}.exe)
