//
// Created by hainguyen on 29/12/2021.
//

#ifndef LTM_PROJECT_STRUCTSCREEN_H
#define LTM_PROJECT_STRUCTSCREEN_H

#include "gtk/gtk.h"
#include "constant.h"

typedef struct{
    GtkWidget *login_window;
    GtkWidget *username_input;
    GtkWidget *password_input;
    GtkWidget *login_button;
    GtkWidget *register_button;
    GtkWidget *show_login_status;
} LoginContainer;

typedef struct{
    GtkWidget *main_window;
    GtkWidget *show_player_name;
    GtkWidget *input_room_id;
    GtkWidget *join_random_room;
    GtkWidget *create_room;
    GtkWidget *join_room;
    GtkWidget *show_main_status;
    GtkWidget *submit_button;
} MainContainer;

typedef struct{
    GtkWidget *room_window;
    GtkWidget *start_button;
    GtkWidget *out_button;
    GtkWidget *player1_name;
    GtkWidget *player2_name;
    GtkWidget *player3_name;
    GtkWidget *show_room_id;
    GtkWidget *show_room_status;
} RoomContainer;

typedef struct{
    GtkWidget *game_window;
    GtkWidget *turn_button;
    GtkWidget *submit_button;
    GtkWidget *value_input;
    GtkWidget *show_result;
    GtkWidget *show_hint;
    GtkWidget *p1_point;
    GtkWidget *p2_point;
    GtkWidget *p3_point;
    GtkWidget *show_announcement;
    GtkWidget *show_turn;
    GtkWidget *next2_button;
    GtkWidget *next3_button;
    GtkWidget *next_final_button;
    GtkWidget *p1_name;
    GtkWidget *p2_name;
    GtkWidget *p3_name;
    char result1[MAX_LEN_BUFF];
    char result2[MAX_LEN_BUFF];
    char result3[MAX_LEN_BUFF];
    char hint1[MAX_LEN_BUFF];
    char hint2[MAX_LEN_BUFF];
    char hint3[MAX_LEN_BUFF];
    char result_final[MAX_LEN_BUFF];
    char hint_final[MAX_LEN_BUFF];
    char result_now[MAX_LEN_BUFF];
} GameContainer;


typedef struct{
    LoginContainer loginContainer;
    MainContainer mainContainer;
    GameContainer gameContainer;
    RoomContainer roomContainer;
} ScreenApp;

typedef struct{
    ScreenApp *ScreenApp;
    pthread_t childThreadId;
    int sockFd;
    int playerID;
    char playerName[30];
    int current_turning_point;
    int current_point;
    int isTurn;
    int position;
} UserData;



#endif //LTM_PROJECT_STRUCTSCREEN_H


