//
// Created by hainguyen on 01/01/2022.
//

#include "handleLogin.h"
int loginUser(int sockFd,UserData *userData)
{
    int byte_recv,byte_send;
    char *buff_send = (char *) calloc(1, MAX_LEN_BUFF);
    char *buff_recv = (char *) calloc(1, MAX_LEN_BUFF);
    char *username = (char *)gtk_entry_get_text(userData->ScreenApp->loginContainer.username_input);
    char *password = (char *)gtk_entry_get_text(userData->ScreenApp->loginContainer.password_input);
    //send
    sprintf(buff_send,"login#%s#%s",username,password);
    byte_send = send(sockFd,buff_send,MAX_LEN_BUFF,0);
    if (byte_send < 0){
        perror("Some thing wrong in loginUser: byte_send");
    }
    memset(buff_send,'\0',strlen(buff_send)+1);

    byte_recv = recv(sockFd,buff_recv,MAX_LEN_BUFF,0);
    if (byte_recv < 0){
        perror("Some thing wrong in loginUser: byte_recv");
    }
    buff_recv[byte_recv] = '\0';
//    Login Success
//  login_sucess#id
    printf("buff_recv: %s\n",buff_recv);
    char *token = strtok(buff_recv,SEPERATOR);
    if (strcmp(buff_recv,LOGIN_SUCCESS)==0){
        token = strtok(NULL,"#");
        userData->playerID = atoi(token);
        printf("id nguoi choi: %d\n",userData->playerID);
        free(buff_recv);
//        free(token);
        return 1;
    }
    else
    {
        return 0;
    }

}

int registerUser(int sockFd,UserData *userData){
    int byte_recv,byte_send;
    char *buff_send = (char *) calloc(1, MAX_LEN_BUFF);
    char *buff_recv = (char *) calloc(1, MAX_LEN_BUFF);
    char *username = (char *)gtk_entry_get_text(userData->ScreenApp->loginContainer.username_input);
    char *password = (char *)gtk_entry_get_text(userData->ScreenApp->loginContainer.password_input);

    //send
    sprintf(buff_send,"register#%s#%s",username,password);

    byte_send = send(sockFd,buff_send,MAX_LEN_BUFF,0);
    if (byte_send < 0){
        perror("Some thing wrong in loginUser: byte_send");
    }

    memset(buff_send,'\0',strlen(buff_send)+1);
    byte_recv = recv(sockFd,buff_recv,MAX_LEN_BUFF,0);
    if (byte_recv < 0){
        perror("Some thing wrong in loginUser: byte_recv");
    }
    buff_recv[byte_recv] = '\0';
    printf("%s\n",buff_recv);
    char *token = strtok(buff_recv,SEPERATOR);
    //Register Success
    if (strcmp(buff_recv,REGISTER_SUCCESS)==0){
        token = strtok(NULL,"#");
        userData->playerID = atoi(token);
        free(buff_recv);
//        memset(buff_recv,'\0',strlen(buff_recv)+1);
//        memset(token,'\0',strlen(token)+1);
        return 1;
    }
    else
    {
        return 0;
    }
}