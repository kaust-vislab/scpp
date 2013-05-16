# @author  Stefan Eilemann
# @remarks Copyright (c) BBP/EPFL 2011; All rights reserved. Do not distribute without further notice.

set(HEADERS
)

set(SOURCES
  main.cpp
)

# Executable name. This is a make target, so you can do a "make hellorunner"
set(APPLICATION hellorunner)

add_executable(${APPLICATION} ${HEADERS} ${SOURCES})
target_link_libraries(${APPLICATION} Hello ${Boost_PROGRAM_OPTIONS_LIBRARY})
install(TARGETS ${APPLICATION} DESTINATION bin COMPONENT apps)
