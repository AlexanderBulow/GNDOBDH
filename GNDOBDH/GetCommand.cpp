// ComTestinVS.cpp : Defines the entry point for the application.
//

#include "GetCommand.h"

using namespace std;

char buffer[64] = { 0 };

char* GetCommand(int talkto)
{
    memset(buffer, 0, sizeof(buffer));
    // creating socket
    int receivingSocket = socket(AF_INET, SOCK_STREAM, 0);
    //allows you to use the socket even though the socket might not have been closed yet
    int opt = 1;
    setsockopt(receivingSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET; //Internet domain sockets
    if (talkto == 1) {
        serverAddress.sin_port = htons(1200); //port we connect to
    }
    else if (talkto == 2) {
        serverAddress.sin_port = htons(2000); //port we connect to
    }
    else if (talkto == 3) {
        serverAddress.sin_port = htons(3000); //port we connect to
    }
    else if (talkto == 4) {
        serverAddress.sin_port = htons(4000); //port we connect to
    }
    else if (talkto == 5) {
        serverAddress.sin_port = htons(5000); //port we connect to
    }
    else if (talkto == 6) {
        serverAddress.sin_port = htons(6000); //port we connect to
    }
    else if (talkto == 7) {
        serverAddress.sin_port = htons(7000); //port we connect to
    }
    else if (talkto == 8) {
        serverAddress.sin_port = htons(8000); //port we connect to
    }
    else {
        cout << "Unable to connect to the specified port" << endl;
    }
    //wsl1 address = 127.0.0.1 wsl2 address = 172.23.240.9
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1"); //binding socket to address for wsl
    // binding socket.
    bind(receivingSocket, (struct sockaddr*)&serverAddress,
        sizeof(serverAddress));

    // listening to the assigned socket
    listen(receivingSocket, 5);
    // accepting connection request
    int sendSocket = accept(receivingSocket, nullptr, nullptr);
    // recieving data
    recv(sendSocket, buffer, sizeof(buffer), 0);

    // closing the socket.
    close(receivingSocket);
    return buffer;
}

