# Copyright (c) BBP/EPFL 2011-2014
#                        Stefan.Eilemann@epfl.ch
# All rights reserved. Do not distribute without further notice.

#MADHU This is temporary. Should be moved to CMake/common repo
find_package(ALSA)
include_directories(${ALSA_INCLUDE_DIRS})

add_definitions(-DBOOST_PROGRAM_OPTIONS_DYN_LINK) # Fix for windows and shared boost.


set(RULE_HEADERS)
set(RULE_SOURCES main.cpp)
set(RULE_LINK_LIBRARIES Hello 
  ${Boost_PROGRAM_OPTIONS_LIBRARY} 
  ${Boost_THREAD_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_REGEX_LIBRARY}
  ${ALSA_LIBRARIES} 
  ${SuperCollider_LIBRARIES}
)

common_application(rule)


#MADHU: TODO
# 1. Change supercollider builds to output third-party static libs to be output to lib/ during installation
# 2. Move the ALSA package finding somewhere else (CMake/common)
