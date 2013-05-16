/**
 * @file    world.h
 * @brief
 * @author  vonhalle
 * @date    2011-07-29
 * @remarks Copyright (c) BBP/EPFL 2005-2011; All rights reserved. Do not distribute without further notice.
 */

#ifndef BBP_HELLO_WORLD_H
#define BBP_HELLO_WORLD_H

/**
 * @brief    Here you put a short description of the namespace
 *
 * Extended documentation for this namespace
 *
 * @author  	Barthelemy von Haller
 * @date    	29.07.2011
 */
namespace hello
{
    /**
     * @brief   Here you put a short description of the class
     *
     * Extended documentation for this class.
     *
     * @author 	Barthelemy von Haller
     * @date 	29.07.2011
     */
    class World
    {
        public:
            /**
             * @brief   Greets the caller
             * @author 	Fabien Delalondre
             * @brief	Simple hello world
             */
            void greet();

            /**
             * @brief   Returns the value passed to it
             *
             * Longer description that is useless here.
             *
             * @author 	Barthelemy von Haller
             * @param n (In) input number.
             * @return Returns the input number given.
             */
            int returns_n( int n );
    };

} /// namespace hello

#endif // BBP_HELLO_WORLD_H
