//
// Created by hainguyen on 29/12/2021.
//

#include "stdio.h"
#include "handleLogin.h"
#include "structScreen.h"
#include "string.h"
#include "gtk/gtk.h"
#include "LoginController.h"
#include "constant.h"
#include "handleThread.h"

void on_login_clicked(GtkButton *button, UserData *userData) {
    printf("Clicked login\n");
    char *username = (char *) gtk_entry_get_text(GTK_ENTRY(userData->ScreenApp->loginContainer.username_input));
    char *password = (char *) gtk_entry_get_text(GTK_ENTRY(userData->ScreenApp->loginContainer.password_input));

    printf("Username dang nhap la: %s - PW la %s\n", username, password);
    if (strcmp(username, "") == 0 || strcmp(password, "") == 0)
    {
        printf("login NULL\n");
        gtk_label_set_text(userData->ScreenApp->loginContainer.show_login_status, "Input all password and username");
        gtk_widget_set_visible(userData->ScreenApp->loginContainer.show_login_status,TRUE);
        if (strcmp(username, "") != 0)
        {
            memset(username,'\0',strlen(username)+1);
        }
        if(strcmp(password, "") != 0)
        {
            memset(password,'\0',strlen(password)+1);
        }
        return;
    }
    else
    {
        if(loginUser(userData->sockFd,userData) ==1){
            strcpy(userData->playerName, username);
            memset(username,'\0',strlen(username)+1);
            memset(password,'\0',strlen(password)+1);
            gtk_label_set_text(userData->ScreenApp->mainContainer.show_player_name, userData->playerName);
            gtk_widget_hide(userData->ScreenApp->loginContainer.login_window);
            gtk_widget_show(userData->ScreenApp->mainContainer.main_window);


            //    Set priority
            int ret;
            struct sched_param schedParam;
            pthread_attr_t attr;
            pthread_attr_init(&attr);
            pthread_attr_getschedparam(&attr, &schedParam);
            schedParam.sched_priority = 50;

            pthread_attr_setschedpolicy(&attr, SCHED_RR);
            pthread_attr_setschedparam(&attr, &schedParam);
            ret = pthread_create(&(userData->childThreadId), NULL, multiModeHandle, userData);
            if (ret) {
                printf("pthread_create() error number=%d\n", ret);
                return;
            }
        }
        else{
            gtk_label_set_text(userData->ScreenApp->loginContainer.show_login_status,"Wrong User or Password");
//            memset(username,"\0",strlen(username)+1);
//            memset(password,"\0",strlen(password)+1);
        }
    }
    return;

}



void on_register_clicked(GtkButton *button, UserData *userData) {
    printf("Clicked register\n");
    char *username = (char *) gtk_entry_get_text(GTK_ENTRY(userData->ScreenApp->loginContainer.username_input));
    char *password = (char *) gtk_entry_get_text(GTK_ENTRY(userData->ScreenApp->loginContainer.password_input));
    printf("Username dang ky la: %s - PW la %s\n", username, password);

    if (strcmp(username, "") == 0 || strcmp(password, "") == 0){
        printf("dki NULL\n");
        gtk_label_set_text(userData->ScreenApp->loginContainer.show_login_status, "Input all password and username");
        gtk_widget_set_visible(userData->ScreenApp->loginContainer.show_login_status,TRUE);
        if (strcmp(username, "") != 0)
        {
            memset(username,'\0',strlen(username)+1);
        }
        if(strcmp(password, "") != 0)
        {
            memset(password,'\0',strlen(password)+1);
        }
        return;
    }
    else
    {
        if(registerUser(userData->sockFd,userData)==1){
            strcpy(userData->playerName, username);
            gtk_label_set_text(userData->ScreenApp->mainContainer.show_player_name, userData->playerName);
            gtk_widget_hide(userData->ScreenApp->loginContainer.login_window);
            gtk_widget_show(userData->ScreenApp->mainContainer.main_window);
        }else{
            gtk_label_set_text(userData->ScreenApp->loginContainer.show_login_status, "Username is existed");
        }
        memset(username,'\0',strlen(username)+1);
        memset(password,'\0',strlen(password)+1);
    }
    return;
}




