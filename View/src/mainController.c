//
// Created by hainguyen on 30/12/2021.
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

void on_join_random_room_clicked(GtkButton *button, UserData *userData){
    printf("Clicked join random\n");
}

void on_create_room_clicked(GtkButton *button, UserData *userData){
    char room_id = (char *) gtk_entry_get_text(GTK_ENTRY(userData->ScreenApp->mainContainer.room_id));
    printf("room-ID: %s\n",room_id);
}

void on_join_room_clicked(GtkButton *button, UserData *userData){
    char room_id = (char *) gtk_entry_get_text(GTK_ENTRY(userData->ScreenApp->mainContainer.room_id));
    printf("room-ID: %s\n",room_id);
}
