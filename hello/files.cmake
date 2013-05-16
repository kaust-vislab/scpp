
# Copyright (c) 2013, EPFL/Blue Brain Project
#                     Daniel Nachbaur <daniel.nachbaur@epfl.ch>

set(HELLO_PUBLIC_HEADERS
  ${OUTPUT_INCLUDE_DIR}/hello/version.h
  ${DEFINES_FILE}
  world.h
  )

set(HELLO_DETAIL
  )

set(HELLO_SOURCES
  version.cpp
  world.cpp
  )

set(HELLO_ALL ${HELLO_PUBLIC_HEADERS} ${HELLO_DETAIL} ${HELLO_SOURCES})
