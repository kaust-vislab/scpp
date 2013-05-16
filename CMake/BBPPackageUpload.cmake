
# Copyright (c) 2012, EPFL/Blue Brain Project
#                     Daniel Nachbaur <daniel.nachbaur@epfl.ch>

# HOW-TO:
# This file contains the 'package-upload' rule for any BBP software, currently
# limited to deb (Ubuntu) and rpm (RedHat) packages. This file must be included
# after the CPack configuration inside the CPackConfig.cmake to work correctly.
# Note that the release procedure is handled separately as this needs to be
# executed only on one machine contrary to the packaging. The file containing
# the release procedure rules is BBPRelease.cmake.
#
# Below variables must be set beforehand in order to get the task working.

if(APPLE OR MSVC)
  return()
endif()

if(CMAKE_VERSION VERSION_LESS 2.8.3)
  # WAR bug
  get_filename_component(CMAKE_CURRENT_LIST_DIR ${CMAKE_CURRENT_LIST_FILE} PATH)
  list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/2.8.3)
endif()

# ID/name of the used distribution, e.g. "Ubuntu"
include(${CMAKE_CURRENT_LIST_DIR}/oss/LSBInfo.cmake)
if(NOT LSB_DISTRIBUTOR_ID)
  message(FATAL_ERROR "Need LSB_DISTRIBUTOR_ID")
endif()

# will be set if CPack was configured before
if(NOT CPACK_PACKAGE_FILE_NAME)
  message(FATAL_ERROR "Need CPACK_PACKAGE_FILE_NAME")
endif()

set(PACKAGE_SERVER "bbprelman@bbpteam.epfl.ch")
set(UPLOAD_COMMAND)

if(LSB_DISTRIBUTOR_ID MATCHES "Ubuntu")
  if(NOT LSB_CODENAME)
    message(FATAL_ERROR "Need LSB_CODENAME")
  endif()
  set(UPLOAD_COMMAND scp ${CPACK_PACKAGE_FILE_NAME}.deb
                       ${PACKAGE_SERVER}:~/debian/apt/ &&
                     ssh ${PACKAGE_SERVER}
                       /web/artifacts/bin/updaterepo-ubuntu ${LSB_CODENAME}
                       remove ${CPACK_DEBIAN_PACKAGE_NAME} &&
                     ssh ${PACKAGE_SERVER}
                       /web/artifacts/bin/updaterepo-ubuntu ${LSB_CODENAME}
                       add debian/apt/${CPACK_PACKAGE_FILE_NAME}.deb)
elseif(LSB_DISTRIBUTOR_ID MATCHES "RedHatEnterpriseServer")
  if(NOT LSB_RELEASE)
    message(FATAL_ERROR "Need LSB_RELEASE")
  endif()
  set(UPLOAD_COMMAND scp ${CPACK_PACKAGE_FILE_NAME}.rpm
                       ${PACKAGE_SERVER}:~/redhat/el${LSB_RELEASE}/x86_64/bbp/rpms/ &&
                     ssh ${PACKAGE_SERVER} /web/artifacts/bin/updaterepo-redhat
                       update el${LSB_RELEASE} x86_64 bbp)
else()
  message(STATUS "Unknown OS for package-upload")
endif()

add_custom_target(package-build
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target package)

add_custom_target(package-upload
  COMMAND ${UPLOAD_COMMAND}
  COMMENT "Uploading package ${CPACK_PACKAGE_FILE_NAME} to bbpteam"
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  DEPENDS package-build
  VERBATIM)
