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
    GtkWidget *show_status;
} LoginContainer;

typedef struct{
    GtkWidget *main_window;
    GtkWidget *show_player_name;
    GtkWidget *room_id;
    GtkWidget *join_random_room;
    GtkWidget *create_room;
    GtkWidget *join_room;
} MainContainer;

typedef struct{
    GtkWidget *room_window;
    GtkWidget *start_button;
    GtkWidget *out_button;
    GtkWidget *player1_name;
    GtkWidget *player2_name;
    GtkWidget *player3_name;
} RoomContainer;

typedef struct{
    GtkWidget *game_window;
    GtkWidget *turn_button;
    GtkWidget *submit_button;
    GtkWidget *value_input;
} GameContainer;


typedef struct{
    LoginContainer loginContainer;
    MainContainer mainContainer;
    GameContainer gameContainer;
    RoomContainer roomContainer;
} ScreenApp;

typedef struct{
    ScreenApp *ScreenApp;
    int sockFd;
    int playerID;
    char playerName[30];
} UserData;

typedef struct{
    ScreenApp *ScreenApp;
    char player1[30];
    char player2[30];
    char player3[30];
} RoomData;

typedef struct{
    ScreenApp *ScreenApp;
    char result1[MAX_LEN_BUFF];
    char suggest1[MAX_LEN_BUFF];
    char result1Show[MAX_LEN_BUFF];
    char result2[MAX_LEN_BUFF];
    char suggest2[MAX_LEN_BUFF];
    char result2Show[MAX_LEN_BUFF];
    char result3[MAX_LEN_BUFF];
    char suggest3[MAX_LEN_BUFF];
    char result3Show[MAX_LEN_BUFF];
    char resultFinal[MAX_LEN_BUFF];
    char suggestFinal[MAX_LEN_BUFF];
    char resultFinalShow[MAX_LEN_BUFF];
    char player1Point[30];
    char player2Point[30];
    char player3Point[30];
    char annoucement[MAX_LEN_BUFF];
}GameData;

#endif //LTM_PROJECT_STRUCTSCREEN_H


