

#include "SendCOmmand.h"

using namespace std;

void SendCom(char Command[64], int talkto) {
    // creating socket
    int sendSocket = socket(AF_INET, SOCK_STREAM, 0);
    //allows you to use the socket even though the socket might not have been closed yet
    int opt = 1;
    setsockopt(sendSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

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
    serverAddress.sin_addr.s_addr = inet_addr("172.23.240.9"); //binding socket to address for wsl

    // sending connection request if it fails we retry
    while (connect(sendSocket, (struct sockaddr*)&serverAddress,
        sizeof(serverAddress)) == -1) {
        cout << "failed connection" << endl;
        sleep(1);
    }

    // sending data
    const char* message = Command;
    send(sendSocket, message, strlen(message), 0);

    // closing socket
    close(sendSocket);
}