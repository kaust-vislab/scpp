
# Copyright (c) 2013, EPFL/Blue Brain Project
#                     Daniel Nachbaur <daniel.nachbaur@epfl.ch>

update_file(${CMAKE_CURRENT_SOURCE_DIR}/version.in.h ${OUTPUT_INCLUDE_DIR}/hello/version.h)

install(FILES ${OUTPUT_INCLUDE_DIR}/hello/version.h DESTINATION include/hello COMPONENT dev)
install(FILES ${DEFINES_FILE} DESTINATION include/hello COMPONENT dev)
install(FILES ${OPTIONS_CMAKE} DESTINATION ${CMAKE_MODULE_INSTALL_PATH} COMPONENT dev)
