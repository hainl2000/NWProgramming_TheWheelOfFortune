//
// Created by hainguyen on 29/12/2021.
//

#include "handleMain.h"

void createRoom(int sockFd, UserData *userData)
{
    char *buff_send = (char *) calloc(1, MAX_LEN_BUFF);
    int byte_send = 0;
    sprintf(buff_send,"create_room#%d",userData->playerID);
    byte_send = send(sockFd,buff_send,MAX_LEN_BUFF,0);
    printf("data_send: %s\n",buff_send);
    if(byte_send < 0)
        perror("\nError: ");
    free(buff_send);
    return;
}

void joinRandomRoom(int sockFd, UserData *userData)
{
    char *buff_send = (char *) calloc(1, MAX_LEN_BUFF);
    int byte_send = 0;
    sprintf(buff_send,"join_random_room#%d",(userData->playerID));
    printf("data_send: %s\n",buff_send);
    byte_send = send(sockFd,buff_send,MAX_LEN_BUFF,0);
    free(buff_send);
    if(byte_send < 0) {
        perror("\nError: ");
    }
    return;
}

void joinRoomByID(int sockFd,UserData *userData)
{
    char *buff_send = (char *) calloc(1, MAX_LEN_BUFF);
    int  byte_send= 0;
    char *roomID = (char *) calloc(1, MAX_LEN_BUFF);
    strcpy(roomID,gtk_entry_get_text(userData->ScreenApp->mainContainer.input_room_id));
    printf("roomID: %s\n",roomID);
    sprintf(buff_send,"join_room#%s#%d",roomID,userData->playerID);
    printf("data_send: %s\n",buff_send);
    byte_send = send(sockFd,buff_send,MAX_LEN_BUFF,0);
    free(buff_send);
    free(roomID);
    if(byte_send < 0) {
        perror("\nError: ");
    }
    return;
}





