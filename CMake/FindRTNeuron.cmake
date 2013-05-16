# Copyright (c) 2011 EPFL/BBP. All rights reserved.
# Author: Stefan Eilemann

if(NOT RTNEURON_ROOT)
  set (RTNEURON_ROOT $ENV{RTNEURON_ROOT})
endif()

if(NOT RTNEURON_ROOT) # heuristic search in standard places
  find_path(RTNEURON_ROOT "share/RTNeuron/Corba/RTNeuronInterface.idl"
    NO_DEFAULT_PATH PATHS
    ${CMAKE_SOURCE_DIR}/../RTNeuron/Bluehub${CMAKE_BUILD_TYPE}/install
    ${CMAKE_SOURCE_DIR}/../../RTNeuron/Bluehub${CMAKE_BUILD_TYPE}/install
    /usr
    /usr/local
    /opt
    /opt/local
    )
endif()

set(RTNEURON_INCLUDE_DIRS "${RTNEURON_ROOT}/include"
    "${RTNEURON_ROOT}/include/RTNeuron/Corba"
    "${RTNEURON_ROOT}/include/RTNeuron/"
    "${RTNEURON_ROOT}/include/RTNeuron/render/alphablend")

set(RTNEURON_IDL_DIR "${RTNEURON_ROOT}/share")

# Blue Hub libraries
find_library(RTNEURON_BLUEHUB_LIB NAMES rtneuron_osgviewer rtneuron_osgviewer_dbg
  NO_DEFAULT_PATH PATHS ${RTNEURON_ROOT}/lib)
find_library(RTNEURON_WIDGETS_LIB rtneuron_widgets ${RTNEURON_ROOT}/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(RTNeuron DEFAULT_MSG RTNEURON_ROOT
                                  RTNEURON_BLUEHUB_LIB
                                  RTNEURON_WIDGETS_LIB)

set(RTNEURON_LIBRARIES ${RTNEURON_BLUEHUB_LIB})
if(RTNEURON_FOUND)
  message(STATUS "Found RTNeuron in ${RTNEURON_INCLUDE_DIRS}:"
    "${RTNEURON_LIBRARIES}")
  set(RTNEURON_IDL_FILES
    "${RTNEURON_IDL_DIR}/RTNeuron/Corba/RTNeuronInterface.idl")
  set(RTNEURON_BLUEHUB_DEB_DEPENDENCIES "rtneuron-bluehub")
endif()
