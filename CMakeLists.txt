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
target_include_directories(${PROJECT_NAME} PUBLIC C:/Users/visitor.ATALENT.001/vcpkg/installed/x64-windows/include)
#sfml


set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/$<0:>)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX _V${CMAKE_PROJECT_VERSION}_${Configuration}.exe)
