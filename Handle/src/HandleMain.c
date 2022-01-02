//
// Created by hainguyen on 29/12/2021.
//

#include "handleMain.h"

void createRoom(int sockFd, UserData *userData)
{
//    char buff_send[MAX_LEN_BUFF];
//    char buff_recv[MAX_LEN_BUFF];
    char *buff_send = (char *) calloc(1, MAX_LEN_BUFF);
    int byte_send = 0;
//    int recvBuff = 0;
    sprintf(buff_send,"create_room#%d",userData->playerID);
    byte_send = send(sockFd,buff_send,MAX_LEN_BUFF,0);
    printf("data_send: %s\n",buff_send);
    if(byte_send < 0)
        perror("\nError: ");
    free(buff_send);
    return;
//    recvBuff = recv(sockFd,data_recv,MAX_LEN_BUFF,0);
//    if (recvBuff <0)
//        perror("\nError: ");
//    data_recv[recvBuff] = '\0';
//    strcpy(data_recv,"success1#2");
//    char *token = strtok(data_recv,"#");
//    printf("%s\n",token);

//    if (strcmp(token,"success") == 0)
//    {
//        token = strtok(NULL,"#");
//        printf("token la: %s\n",token);
//        gtk_label_set_text(userData->ScreenApp->roomContainer.show_room_id,token);
//        return 1;
//    }
//    else
//    {
//        gtk_label_set_text(userData->ScreenApp->mainContainer.show_main_status,"Error while creating room");
//        gtk_widget_set_visible(userData->ScreenApp->mainContainer.show_main_status,TRUE);
//        return 0;
//    }
}

void joinRandomRoom(int sockFd, UserData *userData)
{
//    char buff_send[MAX_LEN_BUFF];
    char *buff_send = (char *) calloc(1, MAX_LEN_BUFF);
    int byte_send = 0;
//    char buff_recv[MAX_LEN_BUFF];
    sprintf(buff_send,"join_random_room#%d",(userData->playerID));
    printf("data_send: %s\n",buff_send);
//    int recvBuff = 0;
    byte_send = send(sockFd,buff_send,MAX_LEN_BUFF,0);
    free(buff_send);
    if(byte_send < 0) {
        perror("\nError: ");
    }
    return;
//    recvBuff = recv(sockFd,data_recv,MAX_LEN_BUFF,0);
//    if (recvBuff <0)
//        perror("\nError: ");
//    data_recv[recvBuff] = '\0';
//    strcpy(data_recv,"success#2#1#player 1");
//    char *token = strtok(data_recv,"#");
//    printf("%s\n",token);\
    if(strcmp(token,"success") == 0)
//    {
//        token= strtok(NULL,"#");
//        printf("token la: %s\n",token);
//        gtk_label_set_text(userData->ScreenApp->roomContainer.show_room_id,token);
//        token = strtok(NULL,"#");
//        printf("so nguoi choi la: %s\n",token);
//        int players = atoi(token);
//        token = strtok(NULL,"#");
//        printf("nguoi choi 1 la: %s\n",token);
//        gtk_label_set_text(userData->ScreenApp->roomContainer.player1_name,token);
//        if(players == 1)
//        {
//            gtk_label_set_text(userData->ScreenApp->roomContainer.player2_name,userData->playerName);
//        }
//        else if(players == 2)
//        {
//            token = strtok(NULL,"#");
//            printf("nguoi choi 2 la: %s\n",token);
//            gtk_label_set_text(userData->ScreenApp->roomContainer.player2_name,token);
//            gtk_label_set_text(userData->ScreenApp->roomContainer.player3_name,userData->playerName);
//        }
//        return 1;
//    }
//    else
//    {
//        gtk_label_set_text(userData->ScreenApp->mainContainer.show_main_status,"No empty room");
//        gtk_widget_set_visible(userData->ScreenApp->mainContainer.show_main_status,TRUE);
//        return 0;
//    }
}

void joinRoomByID(int sockFd,UserData *userData)
{
//    char buff_send[MAX_LEN_BUFF];
    char *buff_send = (char *) calloc(1, MAX_LEN_BUFF);
    int  byte_send= 0;
//    char roomID[MAX_LEN_BUFF];
    char *roomID = (char *) calloc(1, MAX_LEN_BUFF);
    strcpy(roomID,gtk_label_get_text(userData->ScreenApp->mainContainer.input_room_id));
    sprintf(buff_send,"join_room#%d#",roomID+'0');
    printf("data_send: %s\n",buff_send);
    byte_send = send(sockFd,byte_send,MAX_LEN_BUFF,0);
    free(buff_send);
    free(roomID);
    if(byte_send < 0) {
        perror("\nError: ");
    }
    return;
//    char data_recv[MAX_LEN_BUFF];
//    int recvBuff = 0;
//    recvBuff = recv(sockFd,data_recv,MAX_LEN_BUFF,0);
//    if (recvBuff <0)
//        perror("\nError: ");
//    data_recv[recvBuff] = '\0';
//    strcpy(data_recv,"success1#2#1#player 1");
//    char *token = strtok(data_recv,"#");
//    printf("%s\n",token);\
//    if(strcmp(token,"success") == 0)
//    {
//        token= strtok(NULL,"#");
//        printf("token la: %s\n",token);
//        gtk_label_set_text(userData->ScreenApp->roomContainer.show_room_id,token);
//        token = strtok(NULL,"#");
//        printf("so nguoi choi la: %s\n",token);
//        int players = atoi(token);
//        token = strtok(NULL,"#");
//        printf("nguoi choi 1 la: %s\n",token);
//        gtk_label_set_text(userData->ScreenApp->roomContainer.player1_name,token);
//        if(players == 1)
//        {
//            gtk_label_set_text(userData->ScreenApp->roomContainer.player2_name,userData->playerName);
//        }
//        else if(players == 2)
//        {
//            token = strtok(NULL,"#");
//            printf("nguoi choi 2 la: %s\n",token);
//            gtk_label_set_text(userData->ScreenApp->roomContainer.player2_name,token);
//            gtk_label_set_text(userData->ScreenApp->roomContainer.player3_name,userData->playerName);
//        }
//        return 1;
//    }
//    else
//    {
//        gtk_label_set_text(userData->ScreenApp->mainContainer.show_main_status,"No empty room");
//        gtk_widget_set_visible(userData->ScreenApp->mainContainer.show_main_status,TRUE);
//        return 0;
//    }
}



