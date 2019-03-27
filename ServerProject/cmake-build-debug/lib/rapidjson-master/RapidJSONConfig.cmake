################################################################################
# RapidJSON source dir
set( RapidJSON_SOURCE_DIR "/home/esteban/Documentos/TEC/1S 2019/Algoritomos y estructuras de datos II/4. Proyectos/Proyecto #1/Scrabble/lib/rapidjson-master")

################################################################################
# RapidJSON build dir
set( RapidJSON_DIR "/home/esteban/Documentos/TEC/1S 2019/Algoritomos y estructuras de datos II/4. Proyectos/Proyecto #1/Scrabble/cmake-build-debug/lib/rapidjson-master")

################################################################################
# Compute paths
get_filename_component(RapidJSON_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)

set( RapidJSON_INCLUDE_DIR  "${RapidJSON_SOURCE_DIR}/include" )
set( RapidJSON_INCLUDE_DIRS  "${RapidJSON_SOURCE_DIR}/include" )
message(STATUS "RapidJSON found. Headers: ${RapidJSON_INCLUDE_DIRS}")
