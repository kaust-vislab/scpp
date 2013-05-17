# @author  Stefan Eilemann
# @remarks Copyright (c) BBP/EPFL 2011; All rights reserved. Do not distribute without further notice.

include(configure.cmake)
include(files.cmake)

source_group(\\ FILES CMakeLists.txt)
source_group(hello FILES ${HELLO_ALL})

set(LIBRARY Hello)
set(HELLO_LINKLIBS ${Boost_LIBRARIES})

add_library(${LIBRARY} SHARED ${HELLO_ALL})
target_link_libraries(${LIBRARY} ${HELLO_LINKLIBS})
set_target_properties(${LIBRARY}
  PROPERTIES VERSION ${VERSION} SOVERSION ${VERSION_ABI}
  PUBLIC_HEADER "${HELLO_PUBLIC_HEADERS}")

install(TARGETS ${LIBRARY}
        PUBLIC_HEADER DESTINATION include/hello COMPONENT dev
        ARCHIVE DESTINATION lib COMPONENT dev
        RUNTIME DESTINATION bin COMPONENT lib
        LIBRARY DESTINATION lib COMPONENT lib)
