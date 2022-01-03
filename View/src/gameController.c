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
//    printf("%d\n",random);
    userData->current_turning_point = point[random];
    return ;
//    printf("current_point: %d\n",userData->current_point);
//    sprintf(annountcement,"Hai quay vao o %d va co ",point[random]);
//    gtk_label_set_text(userData->ScreenApp->gameContainer.show_announcement,annountcement);
//    printf("thong bao: %s\n",annountcement);
}

void on_submit_clicked(GtkButton *button, UserData *userData)
{
    char annountcement = (char *) calloc(1, MAX_LEN_BUFF);
    char *character = (char *) gtk_entry_get_text(GTK_ENTRY(userData->ScreenApp->gameContainer.value_input));
    int times = 0;
    char *current_result = userData->ScreenApp->gameContainer.result_now;
    char *show_result = (char *) gtk_label_get_text(GTK_LABEL(userData->ScreenApp->gameContainer.show_result));
    for (int i = 0; i < strlen(current_result); ++i) {
        if (current_result[i] == character[0] && show_result[i] == '*')
        {
            times++;
            show_result[i] = character[0];
        }
    }
    if (userData->isTurn == 1)
    {
        userData->current_point += userData->current_turning_point*times;
        userData->current_turning_point = 0;

    }
    userData->isTurn = 0;

    sprintf(annountcement,"result_after_turning#%d#%d#%s#%d#%d#%s",userData->position,userData->current_turning_point,
            character,times,userData->current_point,show_result);
    sendResultAfterTurning(userData->sockFd,userData,annountcement);
    free(annountcement);
    free(character);
    free(current_result);
    free(show_result);
}
