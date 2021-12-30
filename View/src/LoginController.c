//
// Created by hainguyen on 29/12/2021.
//

#include "stdio.h"
#include "handleClient.h"
#include "structScreen.h"
#include "string.h"
#include "stdio.h"
#include "gtk/gtk.h"
#include "LoginController.h"
#include "mainController.h"
#include "constant.h"

 void on_login_clicked(GtkButton *button, UserData *userData){
    char *username = (char *) gtk_entry_get_text(GTK_ENTRY(userData->ScreenApp->loginContainer.username_input));
    char *password = (char *) gtk_entry_get_text(GTK_ENTRY(userData->ScreenApp->loginContainer.password_input));
    printf("Username dang nhap la: %s - PW la %s\n",username,password);

//     printf("name: %s\n",username);
    strcpy(userData->playerName,username);
    gtk_label_set_text(userData->ScreenApp->mainContainer.show_player_name , username);
    gtk_widget_hide(userData->ScreenApp->loginContainer.login_window);
    gtk_widget_show_all(userData->ScreenApp->mainContainer.main_window);
    return;
}

void on_register_clicked(GtkButton *button, UserData *userData){
    char *username = (char *) gtk_entry_get_text(GTK_ENTRY(userData->ScreenApp->loginContainer.username_input));
    char *password = (char *) gtk_entry_get_text(GTK_ENTRY(userData->ScreenApp->loginContainer.password_input));
    strcpy(userData->playerName,username);
    printf("Username dang ky la: %s - PW la %s\n",username,password);

    gtk_label_set_text(userData->ScreenApp->mainContainer.show_player_name , username);
    gtk_widget_hide(userData->ScreenApp->loginContainer.login_window);
    gtk_widget_show_all(userData->ScreenApp->mainContainer.main_window);
    return;
}


