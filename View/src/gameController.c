//
// Created by hainguyen on 30/12/2021.
//

#include "stdio.h"
#include "handleMain.h"
#include "handleGame.h"
#include "structScreen.h"
#include "string.h"
#include "stdlib.h"
#include "gtk/gtk.h"
#include "LoginController.h"
#include "gameController.h"
#include "constant.h"
#include "time.h"


const int point[] = {-200,-100,0,100 ,200,300,500,600,800,1000};

void on_turn_clicked(GtkButton *button, UserData *userData)
{
    srand(time(NULL));
    int random = rand()%10;
    userData->current_turning_point = point[random];
    printf("quay vao o:%d\n",userData->current_turning_point);
    return ;
}

void on_submit_clicked(GtkButton *button, UserData *userData)
{
    char *annountcement = (char *) calloc(1, MAX_LEN_BUFF);
//    strcpy(annountcement,"truyen gia tri");
//    sendResultAfterTurning(userData->sockFd,annountcement);
    char *current_result = (char *) calloc(1, 100);
    char *character = (char *) gtk_entry_get_text(GTK_ENTRY(userData->ScreenApp->gameContainer.value_input));
//    printf("Chu nhap: %s\n",character);
    int times = 0;
    strcpy(current_result,userData->ScreenApp->gameContainer.result_now);
    char *show_result = (char *) gtk_label_get_text(GTK_LABEL(userData->ScreenApp->gameContainer.show_result));
//    printf("Ket qua cu: %s\n",show_result);
    for (int i = 0; i < strlen(current_result); ++i) {
        if (current_result[i] == character[0] && show_result[i] == '*')
        {
            times++;
            show_result[i] = character[0];
        }
    }
//    printf("so lan tra loi dung: %d va ket qua moi: %s\n",times,show_result);

    if (userData->isTurn == 1)
    {
        printf("Turn cua: %s\n",userData->playerName);
        userData->current_point = userData->current_point + userData->current_turning_point*times;
//        printf("diem moi: %d\n",userData->current_point);
    }
    userData->isTurn = 0;
    gtk_label_set_text(userData->ScreenApp->gameContainer.show_turn,"Not your turn");
//    gtk_widget_set_visible(userData->ScreenApp->gameContainer.value_input,FALSE);
//    gtk_widget_set_visible(userData->ScreenApp->gameContainer.submit_button,FALSE);
//    gtk_widget_set_visible(userData->ScreenApp->gameContainer.turn_button,FALSE);
    sprintf(annountcement,"result_after_turning#%d#%d#%s#%d#%d#%s",userData->position,userData->current_turning_point,
            character,times,userData->current_point,show_result);
    printf("thong bao:%s\n",annountcement);
    userData->current_turning_point = 0;
    sendResultAfterTurning(userData->sockFd,annountcement);
    free(annountcement);
    free(current_result);
    return;
}
