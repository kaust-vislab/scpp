/* Copyright (c) BBP/EPFL 2005-2014;
 *               Stefan.Eilemann@epfl.ch
 * All rights reserved. Do not distribute without further notice.
 */

#ifndef HELLO_WORLD_H
#define HELLO_WORLD_H

#include <hello/api.h>

/**
 * The namespace to rule the world.
 *
 * The hello namespace implements the world to provide a template project.
 */
namespace hello
{
/**
 * The world class.
 *
 * Does all the work in the world. Not thread safe.
 */
class World
{
public:
    /** Greet the caller. @version 1.0 */
    HELLO_API void greet();

    /** @return the input value. */
    HELLO_API static int getN(const int n);
};

} // namespace hello

#endif // HELLO_WORLD_H
