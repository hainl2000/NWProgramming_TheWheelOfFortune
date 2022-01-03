//
// Created by hainguyen on 02/01/2022.
//

#include "handleRoom.h"

void outRoom(int sockFd, UserData *userData)
{
    char *buff_send = (char *) calloc(1, MAX_LEN_BUFF);
    int byte_send = 0;
    sprintf(buff_send,"out_room#%d",userData->playerID);
    printf("data_send: %s\n",buff_send);
    send(sockFd,buff_send,MAX_LEN_BUFF,0);
    if(byte_send < 0)
        perror("\nError: ");
    free(buff_send);
    return;
}