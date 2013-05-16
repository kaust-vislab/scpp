# used by BBPPackages.cmake, don't use directly

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake/oss)
find_package(Git)

if(NOT GIT_EXECUTABLE)
  return()
endif()
include(UpdateFile)

file(GLOB_RECURSE DEBS RELATIVE ${CMAKE_SOURCE_DIR}/ubuntu *.deb)
set(ENTRIES)

foreach(DEB ${DEBS})
  if(NOT DEB MATCHES "^apt.*")
    list(APPEND ENTRIES ${CMAKE_SOURCE_DIR}/ubuntu/${DEB})
  endif()
endforeach()

execute_process(COMMAND "${GIT_EXECUTABLE}" add ${ENTRIES}
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
