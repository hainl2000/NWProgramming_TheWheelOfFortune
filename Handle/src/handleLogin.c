//
// Created by hainguyen on 01/01/2022.
//

#include "handleLogin.h"
int loginUser(int sockFd,UserData *userData)
{
    int byte_recv,byte_send;
    char buff_send[MAX_LEN_BUFF];
    char buff_recv[MAX_LEN_BUFF];

    //send
    sprintf(buff_send,"login#%s#%s",userData->ScreenApp->loginContainer.username_input,userData->ScreenApp->loginContainer.password_input);
    byte_send = send(sockFd,buff_send,MAX_LEN_BUFF,0);
    if (byte_send < 0){
        perror("Some thing wrong in loginUser: byte_send");
    }

    free(buff_send);
    byte_recv = recv(sockFd,buff_recv,MAX_LEN_BUFF,0);
    if (byte_recv < 0){
        perror("Some thing wrong in loginUser: byte_recv");
    }
    buff_recv[byte_recv] = '\0';
//    Login Success
    char *token = strtok(buff_recv,SEPERATOR);
    printf("%s\n",token);
    if (strcmp(buff_recv,LOGIN_SUCCESS)==0){
        token = strtok(NULL,"#");
        userData->playerID = atoi(token);
        free(buff_recv);
        free(token);
        return 1;
    }
    else
    {
        return 0;
    }

}

int registerUser(int sockFd,UserData *userData){
    int byte_recv,byte_send;
    char buff_send[MAX_LEN_BUFF];
    char buff_recv[MAX_LEN_BUFF];

    //send
    sprintf(buff_send,"register#%s#%s",userData->ScreenApp->loginContainer.username_input,userData->ScreenApp->loginContainer.password_input);

    byte_send = send(sockFd,buff_send,MAX_LEN_BUFF,0);
    if (byte_send < 0){
        perror("Some thing wrong in loginUser: byte_send");
    }

    free(buff_send);
    byte_recv = recv(sockFd,buff_recv,MAX_LEN_BUFF,0);
    if (byte_recv < 0){
        perror("Some thing wrong in loginUser: byte_recv");
    }
    buff_recv[byte_recv] = '\0';
    char *token = strtok(buff_recv,SEPERATOR);
    printf("%s\n",token);
    //Register Success
    if (strcmp(buff_recv,REGISTER_SUCCESS)==0){
        token = strtok(NULL,"#");
        userData->playerID = atoi(token);
        free(buff_recv);
        free(token);
        return 1;
    }
    else
    {
        return 0;
    }
}