/**
 * @file    world.cpp
 * @brief
 * @author  vonhalle
 * @date    2011-07-29
 * @remarks Copyright (c) BBP/EPFL 2005-2011; All rights reserved. Do not distribute without further notice.
 */

#include <hello/world.h>

#include <iostream>

namespace hello {

    void World::greet()
    {
        std::cout << "Hello world!!" << std::endl;
    }

    int World::returns_n( int n )
    {

        /// \todo This is how you can markup a todo in your code that will show up in the documentation of your project.
        /// \bug This is how you annotate a bug in your code.
        return n;
    }

} // namespace hello
