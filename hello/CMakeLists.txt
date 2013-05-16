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
set_target_properties(${LIBRARY} PROPERTIES VERSION ${VERSION}
                                            SOVERSION ${VERSION_ABI})

install(FILES ${BRION_PUBLIC_HEADERS} DESTINATION include/hello
  COMPONENT dev)
install(TARGETS ${LIBRARY}
        ARCHIVE DESTINATION lib COMPONENT dev
        RUNTIME DESTINATION bin COMPONENT lib
        LIBRARY DESTINATION lib COMPONENT lib)
