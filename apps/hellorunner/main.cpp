/**
 * @file    main.cpp
 * @brief
 * @author  vonhalle
 * @date    2011-07-29
 * @remarks Copyright (c) BBP/EPFL 2005-2011; All rights reserved. Do not distribute without further notice.
 */

#include <hello/world.h>
#include <hello/version.h>
#include <boost/program_options.hpp>
#include <iostream>

namespace po = boost::program_options;

int main( int argc, char *argv[] )
{
    // Arguments parsing
    po::variables_map vm;
    po::options_description desc("Allowed options");
    desc.add_options()
            ("help,h", "Produce help message.")
            ("version,v", "Show program name/version banner and exit.")
            ("rev", "Print the SVN revision number")
            ;
    po::store(parse_command_line(argc,argv,desc),vm);
    po::notify(vm);
    // help
    if (vm.count("help")) {
        std::cout << desc << std::endl;
        return EXIT_SUCCESS;
    }
    // version
    if (vm.count("version")) {
        std::cout << "HelloRunner version " << hello::Version::getString()
                  << std::endl
                  << "Copyright (c) BBP/EPFL 2005-2011; All rights reserved. Do "
                  << "not distribute without further notice." << std::endl;
        return EXIT_SUCCESS;
    }
    // rev
    if (vm.count("rev")) {
        std::cout << "SVN revision : " << hello::Version::getRevision() << std::endl;
        return EXIT_SUCCESS;
    }

    // Actual "work"
    hello::World hello;
    hello.greet();

    return EXIT_SUCCESS;
}
