/**
 * @file    version.cpp
 * @brief   Version Information
 * @author  Stefan Eilemann
 * @remarks Copyright (c) BBP/EPFL 2011; All rights reserved. Do not distribute without further notice.
 */

#include <hello/version.h>
#include <sstream>

namespace hello
{

int Version::getMajor()
{
    return HELLO_VERSION_MAJOR;
}

int Version::getMinor()
{
    return HELLO_VERSION_MINOR;
}

int Version::getPatch()
{
    return HELLO_VERSION_PATCH;
}

std::string Version::getString()
{
    std::ostringstream version;
    version << HELLO_VERSION_MAJOR << '.' << HELLO_VERSION_MINOR << '.'
            << HELLO_VERSION_PATCH;
    return version.str();
}

int Version::getRevision()
{
    return HELLO_VERSION_REVISION;
}

/** @return the current Hello version plus the SVN revision (MM.mm.pp.rev). */
std::string Version::getRevString()
{
    std::ostringstream version;
    version << getString() << '.' << std::hex << HELLO_VERSION_REVISION
            << std::dec;
    return version.str();
}

}
