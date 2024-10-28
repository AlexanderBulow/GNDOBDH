#include "check_command.h"


int check_command(char TC_GRD[], char TM_socket[]) {
    if (strcmp(TM_socket, TC_GRD) == 0){
        return 1;
    }
    else {
        return 0;
    }
}