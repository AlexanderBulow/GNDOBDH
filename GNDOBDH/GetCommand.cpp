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
    else {
        cout << "code no work" << endl;
    }
    //wsl1 address = 127.0.0.1 wsl2 address = 172.23.240.9
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1"); //binding socket to address for wsl
    cout << "1" << endl;
    // binding socket.
    bind(receivingSocket, (struct sockaddr*)&serverAddress,
        sizeof(serverAddress));

    // listening to the assigned socket
    listen(receivingSocket, 5);
    cout << "2" << endl;
    // accepting connection request
    int sendSocket = accept(receivingSocket, nullptr, nullptr);
    cout << "3" << endl;
    // recieving data
    recv(sendSocket, buffer, sizeof(buffer), 0);

    // closing the socket.
    close(receivingSocket);
    cout << "4" << endl;
    return buffer;
}

