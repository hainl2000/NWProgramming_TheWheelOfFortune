//
// Created by hainguyen on 01/01/2022.
//

#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include "constant.h"
#include "handleRecvData.h"
#include "gtk/gtk.h"



void handleRecvData(char *dataRecv, UserData *userData)
{
    printf("data recv: %s\n", dataRecv);
    char *tmp = (char *) calloc(1, MAX_LEN_BUFF);
    strcpy(tmp, dataRecv);
    char *token = strtok(tmp, SEPERATOR);

    if(strcmp(token,CREATE_ROOM_SUCCESS) == 0)
    {
        //    success#2#1#player 1  success#2#2#player 1#player 2
        userData->position = 1;
        token = strtok(NULL,"#");
        printf("token la: %s\n",token);
        gtk_label_set_text(userData->ScreenApp->roomContainer.show_room_id,token);
        gtk_label_set_text(userData->ScreenApp->roomContainer.player1_name,userData->playerName);
        gtk_widget_set_visible(userData->ScreenApp->mainContainer.submit_button,TRUE);
        if (tmp != NULL)
        {
            free(tmp);
        }
        return;
    }

    if(strcmp(token,CREATE_ROOM_FAILURE) == 0)
    {
        printf("Vao day fial\n");
        gtk_label_set_text(userData->ScreenApp->mainContainer.show_main_status,"Create room fail");
        gtk_widget_set_visible(userData->ScreenApp->mainContainer.show_main_status,TRUE);
        if (tmp != NULL)
        {
            free(tmp);
        }
        return;
    }

    if(strcmp(token,JOIN_RANDOM_ROOM_SUCCESS) == 0 || strcmp(token,JOIN_ROOM_BY_ID_SUCCESS) == 0)
    {
//        join(_random)_room_success#room_id#players#player name
        token = strtok(NULL,SEPERATOR);
        gtk_label_set_text(userData->ScreenApp->roomContainer.show_room_id,token);
        token = strtok(NULL,SEPERATOR);
        printf("so nguoi choi la: %s\n",token);
        int players = atoi(token);
        token = strtok(NULL,"#");
        printf("nguoi choi 1 la: %s\n",token);
        gtk_label_set_text(userData->ScreenApp->roomContainer.player1_name,token);
        if(players == 1)
        {
            userData->position = 2;
            gtk_label_set_text(userData->ScreenApp->roomContainer.player2_name,userData->playerName);
//            gtk_widget_hide(userData->ScreenApp->mainContainer.main_window);
//            gtk_widget_show(userData->ScreenApp->roomContainer.room_window);
        }
        else if(players == 2)
        {
            userData->position = 3;
            token = strtok(NULL,"#");
            printf("nguoi choi 2 la: %s\n",token);
            gtk_label_set_text(userData->ScreenApp->roomContainer.player2_name,token);
            gtk_label_set_text(userData->ScreenApp->roomContainer.player3_name,userData->playerName);
//            gtk_widget_hide(userData->ScreenApp->mainContainer.main_window);
//            gtk_widget_show(userData->ScreenApp->roomContainer.room_window);
        }
//        gtk_widget_set_visible(userData->ScreenApp->mainContainer.submit_button,TRUE);
        if (tmp != NULL) {
            free(tmp);
        }
        gtk_widget_set_visible(userData->ScreenApp->mainContainer.submit_button,TRUE);
        return;
    }

    if(strcmp(token,JOIN_RANDOM_ROOM_FAILURE) == 0)
    {
        token = strtok(NULL,SEPERATOR);
        printf("ly do join rd room fail: %s",token);
        gtk_label_set_text(userData->ScreenApp->mainContainer.show_main_status,token);
        gtk_widget_set_visible(userData->ScreenApp->mainContainer.show_main_status,TRUE);
//        gtk_label_set_text(userData->ScreenApp->mainContainer.show_main_status,"Join random room fail");
        if (tmp != NULL)
            free(tmp);
        return;
    }

    if(strcmp(token,JOIN_ROOM_BY_ID_FAILURE) == 0)
    {
        token = strtok(NULL,SEPERATOR);
        printf("ly do join room fail: %s",token);
        gtk_label_set_text(userData->ScreenApp->mainContainer.show_main_status,token);
        gtk_widget_set_visible(userData->ScreenApp->mainContainer.show_main_status,TRUE);
//        gtk_label_set_text(userData->ScreenApp->mainContainer.show_main_status,"Join room by ID fail");
        if (tmp != NULL)
            free(tmp);
        return;
    }

    if(strcmp(token,NEW_PLAYER_JOIN_ROOM) == 0)
    {
//      new_player_join_room#2/3#player name
        token = strtok(NULL,SEPERATOR);
        int player = atoi(token);
        if (player == 1)
        {
            token = strtok(NULL,SEPERATOR);
//            printf("Player 2 vao room %s",token);
            gtk_label_set_text(userData->ScreenApp->roomContainer.player2_name,token);
        }
        if (player == 2)
        {
            token = strtok(NULL,SEPERATOR);
//            printf("Player 3 vao room %s",token);
            gtk_label_set_text(userData->ScreenApp->roomContainer.player3_name,token);
        }
        if (tmp != NULL)
            free(tmp);
        return;
    }

    if (strcmp(token,CAN_START_GAME) == 0)
    {
        //can_start_game#cauhoi#goiy#first_turn
        printf("userPosition: %d\n",userData->position);
        char *result =  (char *) calloc(1, MAX_LEN_BUFF);
        char *hint = (char *) calloc(1, MAX_LEN_BUFF);
        //cauhoi
        token = strtok(NULL,SEPERATOR);
        strcpy(result,token);
        //goi y
        token = strtok(NULL,SEPERATOR);
        strcpy(hint,token);
        strcpy(userData->ScreenApp->gameContainer.result1,result);
        strcpy(userData->ScreenApp->gameContainer.hint1,hint);
        strcpy(userData->ScreenApp->gameContainer.result_now,result);
        //first turn
        token = strtok(NULL,SEPERATOR);
        int firstTurn = atoi(token);
        if (firstTurn == userData->position)
        {
            userData->isTurn =1;
            gtk_widget_set_visible(userData->ScreenApp->gameContainer.turn_button ,TRUE);
            gtk_widget_set_visible(userData->ScreenApp->gameContainer.value_input,TRUE);
            gtk_widget_set_visible(userData->ScreenApp->gameContainer.submit_button,TRUE);
        }
        gtk_widget_set_visible(userData->ScreenApp->roomContainer.start_button,TRUE);
        printf("dap an: %s\n",result);
        printf("hint: %s\n",hint);
        free(result);
        free(hint);
        return;
    }

    if (strcmp(token,PLAYER_OUT_ROOM) == 0)
    {
        gtk_widget_set_visible(userData->ScreenApp->roomContainer.start_button,FALSE);
        token = strtok(NULL,SEPERATOR);
        if (strcmp(token,"1") == 0)
        {
            char *playerName = (char *)gtk_label_get_text(userData->ScreenApp->roomContainer.player2_name);
            gtk_label_set_text(userData->ScreenApp->roomContainer.player1_name,playerName);
            gtk_label_set_text(userData->ScreenApp->roomContainer.player2_name,"");
            userData->position = 1;
            memset(playerName,'\0',strlen(playerName)+1);
        }
        else if (strcmp(token,"2") == 0)
        {
            token = strtok(NULL,SEPERATOR);
            if (strcmp(token,"1") == 0)
            {
                char *playerName = (char *)gtk_label_get_text(userData->ScreenApp->roomContainer.player2_name);
                gtk_label_set_text(userData->ScreenApp->roomContainer.player1_name,playerName);
                char *playerName2 = (char *)gtk_label_get_text(userData->ScreenApp->roomContainer.player3_name);
                gtk_label_set_text(userData->ScreenApp->roomContainer.player2_name,playerName2);
                gtk_label_set_text(userData->ScreenApp->roomContainer.player3_name,"");
                userData->position -=1;
                memset(playerName,'\0',strlen(playerName)+1);
                memset(playerName2,'\0',strlen(playerName2)+1);
            }
            else if (strcmp(token,"2") == 0)
            {
                char *playerName = (char *)gtk_label_get_text(userData->ScreenApp->roomContainer.player3_name);
                gtk_label_set_text(userData->ScreenApp->roomContainer.player2_name,playerName);
                gtk_label_set_text(userData->ScreenApp->roomContainer.player3_name,"");
                memset(playerName,'\0',strlen(playerName)+1);
                if (userData->position = 3)
                {
                    userData->position = 2;
                }
            }
            else if(strcmp(token,"3") == 0)
            {
                gtk_label_set_text(userData->ScreenApp->roomContainer.player3_name,"");
            }
        }

    }

    if (strcmp(token,RESULT_AFTER_TURNING) == 0)
    {
        //result_after_turning#vi tri cua player#diem o chu quay trung#chu cai nhap vao#so chu xuat hien#new point#show_kq
        char *announcement[MAX_LEN_BUFF];
        char *playerName[MAX_LEN_BUFF];
        //vi tri cua ng quay
        token = strtok(NULL,SEPERATOR);
        int position = atoi(token);
        printf("nguoi quay: %d\n",position);
        //diem o chu quay trung
        token = strtok(NULL,SEPERATOR);
        printf("diem o chu: %s\n",token);
        if (position == 1)
        {
            strcpy(playerName, gtk_label_get_text(userData->ScreenApp->gameContainer.p1_name));
        }
        else if (position == 2)
        {
            strcpy(playerName, gtk_label_get_text(userData->ScreenApp->gameContainer.p2_name));
        }
        else if (position == 3)
        {
            strcpy(playerName, gtk_label_get_text(userData->ScreenApp->gameContainer.p3_name));
        }
        sprintf(announcement,"Player %s quay vao o %s diem va doan chu ",playerName,token);
        //chu nhap
        token = strtok(NULL,SEPERATOR);
        printf("chu: %s\n",token);
        strcat(announcement,token);
        strcat(announcement," va xuat hien ");
        //so lan xuat hien
        token = strtok(NULL,SEPERATOR);
        printf("xuat hien: %s\n",token);
        strcat(announcement,token);
        strcat(announcement," lan.");
        printf("Toan bo thong bao: %s\n",announcement);
        gtk_label_set_text(userData->ScreenApp->gameContainer.show_announcement,announcement);
        //new point
        token = strtok(NULL,SEPERATOR);
        printf("diem sau vong nay: %s\n",token);
        if (position == 1)
        {
            gtk_label_set_text(userData->ScreenApp->gameContainer.p1_point,token);
        }
        else if (position == 2)
        {
            gtk_label_set_text(userData->ScreenApp->gameContainer.p2_point,token);
        }
        else if (position == 3)
        {
            gtk_label_set_text(userData->ScreenApp->gameContainer.p3_point,token);
        }
        //show ket qua
        token = strtok(NULL,SEPERATOR);
        printf("ket qua sau vong nay: %s\n",token);
        gtk_label_set_text(userData->ScreenApp->gameContainer.show_result,token);
        //turn moi
        token = strtok(NULL,SEPERATOR);
        int nextPosition = atoi(token);
        printf("loi 0\n");
        if (userData->position == nextPosition)
        {
            printf("loi 1\n");
            userData->isTurn =1;
            printf("loi 2\n");
            gtk_widget_set_visible(userData->ScreenApp->gameContainer.turn_button ,TRUE);
            printf("loi 3\n");
            gtk_widget_set_visible(userData->ScreenApp->gameContainer.value_input,TRUE);
            printf("loi 4\n");
            gtk_widget_set_visible(userData->ScreenApp->gameContainer.submit_button,TRUE);
            printf("loi 5\n");
        }
        printf("vi tri tiep theo: %s\n",token);
        return;
//        free(announcement);
//        free(playerName);
    }

}




