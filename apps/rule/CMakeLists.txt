# Copyright (c) BBP/EPFL 2011-2014
#                        Stefan.Eilemann@epfl.ch
# All rights reserved. Do not distribute without further notice.

set(RULE_HEADERS)
set(RULE_SOURCES main.cpp)
set(RULE_LINK_LIBRARIES Hello ${Boost_PROGRAM_OPTIONS_LIBRARY})

common_application(rule)
