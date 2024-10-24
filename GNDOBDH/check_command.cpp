#include "check_command.h"


void check_command(char TC_GRD[], char TM_socket[]) {
    if (strcmp(TM_socket, TC_GRD) == 0){
        cout << "\033[32mTC COMMAND RECIEVED CORRECTLY\033[0m\n";
    }
    else {
        cout << "\033[31mTC COMMAND RECIEVED INCORRECTLY!\033[0m\n";
    }
}