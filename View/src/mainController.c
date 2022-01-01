//
// Created by hainguyen on 30/12/2021.
//

#include "stdio.h"
#include "handleMain.h"
#include "structScreen.h"
#include "string.h"
#include "stdio.h"
#include "gtk/gtk.h"
#include "LoginController.h"
#include "mainController.h"
#include "constant.h"

void on_join_random_room_clicked(GtkButton *button, UserData *userData){
    char player3Name[MAX_LEN_BUFF];
    printf("Clicked join random\n");
    userData->playerID = 1;
    strcpy(userData->playerName,"Toi ten la tao");
    joinRandomRoom(userData->sockFd,userData);
//    int status = joinRandomRoom(userData->sockFd,userData);
//    if (status == 1)
//    {
//        gtk_widget_hide(userData->ScreenApp->mainContainer.main_window);
//        gtk_widget_show(userData->ScreenApp->roomContainer.room_window);
//    }
//    strcpy(player3Name, gtk_label_get_text(userData->ScreenApp->roomContainer.player3_name));
//    printf("ten ng 3: %s\n",player3Name);
//    if(strcmp(player3Name,"Waiting player 3") == 0)
//    {
//        memset(player3Name,'\0',strlen(player3Name)+1);
//        printf("Nhap ten 3\n");
//        scanf("%s",player3Name);
//    }
//    gtk_label_set_text(userData->ScreenApp->roomContainer.player3_name,player3Name);
    return;
}

void on_create_room_clicked(GtkButton *button, UserData *userData){
    printf("Clicked create room: \n");
//    userData->playerID = 1;
//    int status = createRoom(userData->sockFd,userData);
    createRoom(userData->sockFd,userData);
//    if(status == 1)
//    {
//        gtk_widget_hide(userData->ScreenApp->mainContainer.main_window);
//        gtk_widget_show(userData->ScreenApp->roomContainer.room_window);
//    }
    return ;
}

void on_join_room_clicked(GtkButton *button, UserData *userData){
    printf("Click join room by ID\n");
    char room_id = (char *) gtk_entry_get_text(GTK_ENTRY(userData->ScreenApp->mainContainer.input_room_id));
    if (strcmp(room_id,"") == 0)
    {
        gtk_label_set_text(userData->ScreenApp->mainContainer.show_main_status,"Input room ID");
    }
    joinRoomByID(userData->sockFd,userData);
//    printf("room-ID: %s\n",room_id);
}
