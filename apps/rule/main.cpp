/* Copyright (c) 2014, BBP/EPFL
 *                     Stefan.Eilemann@epfl.ch
 *
 * This file is part of Hello (https://github.com/BlueBrain/Hello)
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name of Eyescale Software GmbH nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <hello/world.h>
#include <hello/version.h>
#include <boost/program_options.hpp>
#include <iostream>

#include "SC_LanguageClient.h"
#include "SC_StringBuffer.h"

namespace po = boost::program_options;


// =====================================================================
// SC_CPPClient - cpp sclang client.
// =====================================================================
static FILE* gPostDest = stdout;
class SC_CPPClient : public SC_LanguageClient
{
 public:
    SC_CPPClient(const char* name):SC_LanguageClient(name){}

    virtual void postText(const char* str, size_t len);
    virtual void postFlush(const char* str, size_t len);
    virtual void postError(const char* str, size_t len);
    virtual void flush();
    void run();
};

void SC_CPPClient::postText(const char* str, size_t len)
{
    fwrite(str, sizeof(char), len, gPostDest);
}

void SC_CPPClient::postFlush(const char* str, size_t len)
{
    fwrite(str, sizeof(char), len, gPostDest);
    fflush(gPostDest);
}

void SC_CPPClient::postError(const char* str, size_t len)
{
    fprintf(gPostDest, "ERROR: ");
    fwrite(str, sizeof(char), len, gPostDest);
}

void SC_CPPClient::flush()
{
    fflush(gPostDest);
}

void SC_CPPClient::run(){
    // initialize runtime
    initRuntime();

    // startup library
    compileLibrary();

    // we first connect to the synth server
    setCmdLine("s = Server(\"aServer\", NetAddr(\"109.171.139.2\", 57110));");
    runLibrary(s_interpretCmdLine);

    //MADHU: The synth is setup and defined on the server
    //setCmdLine("SynthDef(\"sine\", { Out.ar(0, SinOsc.ar(440, 0, 0.2)) }).send(s);");
    //runLibrary(s_interpretCmdLine);


    setCmdLine("s.sendMsg(\"s_new\", \"sine\", n = s.nextNodeID, 0, 1);");
    runLibrary(s_interpretCmdLine);

    /* setCmdLine("s.sendMsg(\"s_new\", \"sine\", n = s.nextNodeID, 0, 1);");
    runLibrary(s_interpretCmdLine);
    setCmdLine("s.sendMsg(\"s_new\", \"sine\", n = s.nextNodeID, 0, 1);");
    runLibrary(s_interpretCmdLine);
    setCmdLine("s.sendMsg(\"s_new\", \"sine\", n = s.nextNodeID, 0, 1);");
    runLibrary(s_interpretCmdLine);
    setCmdLine("s.sendMsg(\"s_new\", \"sine\", n = s.nextNodeID, 0, 1);");
    runLibrary(s_interpretCmdLine);*/

    flush();


    // shutdown library
    shutdownLibrary();
    flush ();
    shutdownRuntime ();
}


int main( int argc, char *argv[] )
{
    // Arguments parsing
    po::variables_map vm;
    po::options_description desc( "Supported options" );
    desc.add_options()
        ( "help,h", "show help message." )
        ( "version,v", "Show program name/version banner and exit." )
        ( "rev", "Print the git revision number" );
    po::store( parse_command_line( argc, argv, desc ), vm );
    po::notify( vm );

    if( vm.count( "help" ))
    {
        std::cout << desc << std::endl;
        return EXIT_SUCCESS;
    }

    if( vm.count( "version" ))
    {
        std::cout << "HelloRunner version " << hello::Version::getString()
                  << std::endl
                  << "Copyright (c) BBP/EPFL 2014." << std::endl;
        return EXIT_SUCCESS;
    }

    if( vm.count( "rev" ))
    {
        std::cout << "git revision: " << std::hex
                  << hello::Version::getRevision() << std::endl;
        return EXIT_SUCCESS;
    }

    // Actual "work"
    // Create a simple cpp client app
    SC_CPPClient app("sclang");
    app.run();


    hello::World hello;
    hello.greet();

    return EXIT_SUCCESS;
}
