//
// Created by hainguyen on 02/01/2022.
//

#include "structScreen.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>

void sendResultAfterTurning(int sockFd, char *announcement)
{
    char *buff_send = (char *) calloc(1, MAX_LEN_BUFF);
    int byte_send = 0;
    strcpy(buff_send,announcement);
//    sprintf(buff_send,"result_after_turn#%d",userData->playerID);
    byte_send = send(sockFd,buff_send,MAX_LEN_BUFF,0);
    printf("data_send: %s\n",buff_send);
    if(byte_send < 0)
        perror("\nError: ");
    free(buff_send);
    return;
}