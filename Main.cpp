#include "EventLoop.h"
#include "Server.h"
#include <getopt.h>
#include <string>

int main(int argc, char *argv[])
{
    int threadNum = 4;
    int port = 80;
    std::string logPath = "./WebServer.log";

    // parse args
    int opt;
    const char *str = "t:p:";
    while ((opt = getopt(argc, argv, str))!= -1)
    {
        switch (opt)
        {
            case 't':
            {
                threadNum = atoi(optarg);
                break;
            }
       //     case 'l':
       //     {
       //         logPath = optarg;
       //         if (logPath.size() < 2 || optarg[0] != '/')
       //         {
       //             printf("logPath should start with \"/\"\n");
       //             abort();
       //         }
       //         break;
       //     }
            case 'p':
            {
                port = atoi(optarg);
                break;
            }
            default: break;
        }
    }
    //Logger::setLogFileName(logPath);
    #ifndef _PTHREADS
        cout<< "_PTHREADS is not defined !";
    #endif
    EventLoop mainLoop;
    Server myHTTPServer(&mainLoop, threadNum, port);
    myHTTPServer.start();
    mainLoop.loop();
    return 0;
}
