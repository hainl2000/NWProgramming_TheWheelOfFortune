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

#include "constant.h"


void handleRecvData(char *dataRecv, UserData *userData)
{
    printf("data recv: %s\n", dataRecv);
    char *tmp = (char *) calloc(1, MAX_LEN_BUFF);
    strcpy(tmp, dataRecv);
    char *token = strtok(tmp, SEPERATOR);

    if(strcmp(token,CREATE_ROOM_SUCCESS) == 0)
    {
        //    success#2#1#player 1  success#2#2#player 1#player 2
        token = strtok(NULL,"#");
        printf("token la: %s\n",token);
        gtk_label_set_text(userData->ScreenApp->roomContainer.show_room_id,token);
        gtk_widget_hide(userData->ScreenApp->mainContainer.main_window);
        gtk_widget_show(userData->ScreenApp->roomContainer.room_window);
        if (tmp != NULL)
        {
            free(tmp);
        }
        return;
    }
    else if(strcmp(token,CREATE_ROOM_FAILURE) == 0)
    {
        gtk_label_set_text(userData->ScreenApp->mainContainer.show_main_status,"Create room fail");
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
            gtk_label_set_text(userData->ScreenApp->roomContainer.player2_name,userData->playerName);
            gtk_widget_hide(userData->ScreenApp->mainContainer.main_window);
            gtk_widget_show(userData->ScreenApp->roomContainer.room_window);
        }
        else if(players == 2)
        {
            token = strtok(NULL,"#");
            printf("nguoi choi 2 la: %s\n",token);
            gtk_label_set_text(userData->ScreenApp->roomContainer.player2_name,token);
            gtk_label_set_text(userData->ScreenApp->roomContainer.player3_name,userData->playerName);
            gtk_widget_hide(userData->ScreenApp->mainContainer.main_window);
            gtk_widget_show(userData->ScreenApp->roomContainer.room_window);
        }

        if (tmp != NULL) {
            free(tmp);
        }
        return;
    }
    else if(strcmp(token,JOIN_RANDOM_ROOM_FAILURE) == 0)
    {
        gtk_label_set_text(userData->ScreenApp->mainContainer.show_main_status,"Join random room fail");
        if (tmp != NULL)
            free(tmp);
        return;
    }
    else if(strcmp(token,JOIN_ROOM_BY_ID_FAILURE) == 0)
    {
        gtk_label_set_text(userData->ScreenApp->mainContainer.show_main_status,"Join room by ID fail");
        if (tmp != NULL)
            free(tmp);
        return;
    }

    if(strcmp(token,NEW_PLAYER_JOIN_ROOM) == 0)
    {
//      new_player_join_room#2/3#player name
        token = strtok(NULL,SEPERATOR);
        int player = atoi(token);
        if (player == 2)
        {
            token = strtok(NULL,SEPERATOR);
            printf("Player 2 vao room %s",token);
            gtk_label_set_text(userData->ScreenApp->roomContainer.player2_name,token);
        }
        if (player == 3)
        {
            token = strtok(NULL,SEPERATOR);
            printf("Player 3 vao room %s",token);
            gtk_label_set_text(userData->ScreenApp->roomContainer.player3_name,token);
        }
        if (tmp != NULL)
            free(tmp);
        return;
    }

}




