
#ifndef BIUPROJECT2_CLIENTHANDLER_H
#define BIUPROJECT2_CLIENTHANDLER_H

#include <string>

class ClientHandler {
public:

    /**
     * Writes server's output to output stream after getting input from the server through input stream.
     * @param input
     * @param output
     */
    virtual void handleClient(int socketfd) = 0;
};


#endif //BIUPROJECT2_CLIENTHANDLER_H
