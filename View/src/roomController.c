//
// Created by hainguyen on 30/12/2021.
//

#include "structScreen.h"
#include "string.h"
#include "stdio.h"
#include "gtk/gtk.h"
#include "LoginController.h"
#include "gameController.h"
#include "roomController.h"
#include "constant.h"

void on_start_button_clicked(GtkButton *button, UserData *userData)
{
    char *result1 = "cauhoi1c";
    char *suggest1 = "Goiy1";
    char result1_show[MAX_LEN_BUFF];
    char *result2 = "cauhoi2";
    char *suggest2 = "Goiy2";
    char *result2_show[MAX_LEN_BUFF];
    char *result3 = "cauhoi3";
    char *suggest3 = "Goiy3";
    char *result3_show[MAX_LEN_BUFF];
    printf("result: %s\n",result1);
    strcpy(userData->ScreenApp->gameContainer.result1,result1);
    strcpy(userData->ScreenApp->gameContainer.result2,result2);
    strcpy(userData->ScreenApp->gameContainer.result3,result3);
    strcpy(userData->ScreenApp->gameContainer.result_now,result1);
//    printf("%d\n",strlen(result1));
    for (int i= 0; i<strlen(result1);i++)
    {
//        printf("%d\n",i);
        result1_show[i] = '*';
//        printf("show: %s\n",result1_show);
    }
    result1_show[strlen(result1)] = '\0';
    for (int i= 0; i<strlen(result2);i++)
    {
        result2_show[i] = '*';
    }
    result2_show[strlen(result2)] = '\0';
    for (int i= 0; i<strlen(result3);i++)
    {
        result3_show[i] = '*';
    }
    result3_show[strlen(result3)] = '\0';
//    printf("%s-%s\n",result1_show,result1);

    gtk_label_set_text(userData->ScreenApp->gameContainer.show_result,result1_show);
    gtk_label_set_text(userData->ScreenApp->gameContainer.show_suggest,suggest1);

    gtk_widget_hide(userData->ScreenApp->roomContainer.room_window);
    gtk_widget_show(userData->ScreenApp->gameContainer.game_window);
}

void on_out_button_clicked(GtkButton *button, UserData *userData)
{
    gtk_widget_hide(userData->ScreenApp->roomContainer.room_window);
    gtk_widget_show_all(userData->ScreenApp->mainContainer.main_window);
}
