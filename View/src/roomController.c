//
// Created by hainguyen on 30/12/2021.
//

#include "structScreen.h"
#include "string.h"
#include "stdio.h"
#include "gtk/gtk.h"
#include "LoginController.h"
#include "gameController.h"
#include "handleRoom.h"
#include "roomController.h"
#include "constant.h"

void on_start_button_clicked(GtkButton *button, UserData *userData)
{
    userData->current_point = 0;
    char *result1 = (char *) calloc(1, MAX_LEN_BUFF);
    char *result1_show = (char *) calloc(1, MAX_LEN_BUFF);
    printf("result 1: %s\n",userData->ScreenApp->gameContainer.result1);
    printf("hint 1: %s\n",userData->ScreenApp->gameContainer.hint1);
    strcpy(result1,userData->ScreenApp->gameContainer.result1);
    for (int i= 0; i<strlen(result1);i++)
    {
        result1_show[i] = '*';
    }

    gtk_label_set_text(userData->ScreenApp->gameContainer.show_result,result1_show);
    gtk_label_set_text(userData->ScreenApp->gameContainer.show_hint, userData->ScreenApp->gameContainer.hint1);
    free(result1);
    free(result1_show);
    gtk_widget_hide(userData->ScreenApp->roomContainer.room_window);
    gtk_widget_show(userData->ScreenApp->gameContainer.game_window);
}

void on_out_button_clicked(GtkButton *button, UserData *userData)
{
    userData->position = -1;
    outRoom(userData->sockFd,userData);
    gtk_widget_hide(userData->ScreenApp->roomContainer.room_window);
    gtk_widget_show(userData->ScreenApp->mainContainer.main_window);
}
