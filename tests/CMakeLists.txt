# Copyright (c) BBP/EPFL 2011-2014, Stefan.Eilemann@epfl.ch
# Change this number when adding tests to force a CMake run: 1

include(InstallFiles)

include_directories(${CMAKE_SOURCE_DIR}) # some tests need private headers
set(TEST_LIBRARIES ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} Hello)
include(CommonCTest)

install_files(share/Lunchbox/tests FILES ${TEST_FILES} COMPONENT examples)
