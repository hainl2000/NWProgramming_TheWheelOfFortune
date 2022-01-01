//
// Created by hainguyen on 30/12/2021.
//

#include "stdio.h"
#include "handleMain.h"
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
    char annountcement[MAX_LEN_BUFF];
    memset(annountcement,'\0',strlen(annountcement)+1);
    userData->current_point = point[random];
//    printf("current_point: %d\n",userData->current_point);
    sprintf(annountcement,"Hai quay vao o %d va co ",point[random]);
    gtk_label_set_text(userData->ScreenApp->gameContainer.show_announcement,annountcement);
//    printf("thong bao: %s\n",annountcement);
}

void on_submit_clicked(GtkButton *button, UserData *userData)
{
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
    char annountcement[MAX_LEN_BUFF];
    char temp[MAX_LEN_BUFF];
    sprintf(temp,"%d chu %s xuat hien",times,character);

    strcpy(annountcement,(char *) gtk_label_get_text(GTK_LABEL(userData->ScreenApp->gameContainer.show_announcement)));
    strcat(annountcement,temp);
    gtk_label_set_text(userData->ScreenApp->gameContainer.show_announcement,annountcement);
    gtk_label_set_text(userData->ScreenApp->gameContainer.show_result,show_result);

    printf("Now\n");
    char *current_point = (char *) gtk_label_get_text(GTK_LABEL(userData->ScreenApp->gameContainer.p1_point));
    printf("current: %s\n",current_point);
    int temp_point = atoi(current_point);
    printf("diem: %d\n",temp_point);
    temp_point += times*userData->current_point;
    char point[MAX_LEN_BUFF];
    sprintf(point, "%d", temp_point);
    gtk_label_set_text(userData->ScreenApp->gameContainer.p1_point,point);
}
