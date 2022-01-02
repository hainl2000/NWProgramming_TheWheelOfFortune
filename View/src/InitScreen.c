//
// Created by hainguyen on 29/12/2021.
//
#include "gtk/gtk.h"
#include "InitScreen.h"
#include "LoginController.h"
#include "mainController.h"
#include "gameController.h"
#include "roomController.h"
#include "structScreen.h"

void initLoginScreen(UserData* userData)
{
    printf("init login\n");
    GtkBuilder *builder = gtk_builder_new_from_file("/home/hainguyen/Desktop/LapTrinhMang/Chiecnonkydieu/cmake-build-debug/View/Client.glade");
    userData->ScreenApp->loginContainer.login_window = (GtkWidget *) gtk_builder_get_object(builder,"login_window");
    userData->ScreenApp->loginContainer.username_input = (GtkWidget *) gtk_builder_get_object(builder,"username_input");
    userData->ScreenApp->loginContainer.password_input = (GtkWidget *) gtk_builder_get_object(builder,"password_input");
    userData->ScreenApp->loginContainer.login_button = (GtkWidget *) gtk_builder_get_object(builder,"login_button");
    userData->ScreenApp->loginContainer.register_button = (GtkWidget *) gtk_builder_get_object(builder,"register_button");
    userData->ScreenApp->loginContainer.show_login_status = (GtkWidget *) gtk_builder_get_object(builder,"show_login_status");

    g_signal_connect(userData->ScreenApp->loginContainer.login_button, "clicked",G_CALLBACK(on_login_clicked), userData);
    g_signal_connect(userData->ScreenApp->loginContainer.register_button, "clicked",G_CALLBACK(on_register_clicked), userData);
}

void initMainScreen(UserData* userData)
{
    printf("init main\n");
    GtkBuilder *builder = gtk_builder_new_from_file("/home/hainguyen/Desktop/LapTrinhMang/Chiecnonkydieu/cmake-build-debug/View/Client.glade");
    userData->ScreenApp->mainContainer.main_window = (GtkWidget *) gtk_builder_get_object(builder,"main_window");
    userData->ScreenApp->mainContainer.show_player_name = (GtkWidget *) gtk_builder_get_object(builder,"show_player_name");
    userData->ScreenApp->mainContainer.join_random_room = (GtkWidget *) gtk_builder_get_object(builder,"join_random_room");
    userData->ScreenApp->mainContainer.create_room = (GtkWidget *) gtk_builder_get_object(builder,"create_room");
    userData->ScreenApp->mainContainer.join_room= (GtkWidget *) gtk_builder_get_object(builder,"join_room");
    userData->ScreenApp->mainContainer.input_room_id = (GtkWidget *) gtk_builder_get_object(builder,"input_room_id");
    userData->ScreenApp->mainContainer.show_main_status = (GtkWidget *) gtk_builder_get_object(builder,"show_main_status");

    g_signal_connect(userData->ScreenApp->mainContainer.join_random_room, "clicked",G_CALLBACK(on_join_random_room_clicked), userData);
    g_signal_connect(userData->ScreenApp->mainContainer.create_room, "clicked",G_CALLBACK(on_create_room_clicked), userData);
    g_signal_connect(userData->ScreenApp->mainContainer.join_room, "clicked",G_CALLBACK(on_join_room_clicked), userData);
}

void initRoomScreen(UserData *userData)
{
    printf("init room\n");
    GtkBuilder *builder = gtk_builder_new_from_file("/home/hainguyen/Desktop/LapTrinhMang/Chiecnonkydieu/cmake-build-debug/View/Client.glade");
    userData->ScreenApp->roomContainer.room_window = (GtkWidget *) gtk_builder_get_object(builder,"room_window");
    userData->ScreenApp->roomContainer.player1_name = (GtkWidget *) gtk_builder_get_object(builder,"player1_name");
    userData->ScreenApp->roomContainer.player2_name = (GtkWidget *) gtk_builder_get_object(builder,"player2_name");
    userData->ScreenApp->roomContainer.player3_name = (GtkWidget *) gtk_builder_get_object(builder,"player3_name");
    userData->ScreenApp->roomContainer.out_button= (GtkWidget *) gtk_builder_get_object(builder,"out_button");
    userData->ScreenApp->roomContainer.start_button = (GtkWidget *) gtk_builder_get_object(builder,"start_button");
    userData->ScreenApp->roomContainer.show_room_id = (GtkWidget *) gtk_builder_get_object(builder,"show_room_id");
    userData->ScreenApp->roomContainer.show_room_status = (GtkWidget *) gtk_builder_get_object(builder,"show_room_status");

    g_signal_connect(userData->ScreenApp->roomContainer.start_button, "clicked",G_CALLBACK(on_start_button_clicked), userData);
    g_signal_connect(userData->ScreenApp->roomContainer.out_button, "clicked",G_CALLBACK(on_out_button_clicked), userData);
}

void initGameScreen(UserData *userData)
{
    printf("init game\n");
    GtkBuilder *builder = gtk_builder_new_from_file("/home/hainguyen/Desktop/LapTrinhMang/Chiecnonkydieu/cmake-build-debug/View/Client.glade");
    userData->ScreenApp->gameContainer.game_window = (GtkWidget *) gtk_builder_get_object(builder,"game_window");
    userData->ScreenApp->gameContainer.submit_button = (GtkWidget *) gtk_builder_get_object(builder,"submit_button");
    userData->ScreenApp->gameContainer.value_input = (GtkWidget *) gtk_builder_get_object(builder,"value_input");
    userData->ScreenApp->gameContainer.turn_button = (GtkWidget *) gtk_builder_get_object(builder,"turn_button");
    userData->ScreenApp->gameContainer.show_turn = (GtkWidget *) gtk_builder_get_object(builder,"show_turn");
    userData->ScreenApp->gameContainer.show_result = (GtkWidget *) gtk_builder_get_object(builder,"show_result");
    userData->ScreenApp->gameContainer.show_suggest = (GtkWidget *) gtk_builder_get_object(builder,"show_suggest");
    userData->ScreenApp->gameContainer.p1_point = (GtkWidget *) gtk_builder_get_object(builder,"p1_point");
    userData->ScreenApp->gameContainer.p2_point = (GtkWidget *) gtk_builder_get_object(builder,"p2_point");
    userData->ScreenApp->gameContainer.p3_point = (GtkWidget *) gtk_builder_get_object(builder,"p3_point");
    userData->ScreenApp->gameContainer.show_announcement = (GtkWidget *) gtk_builder_get_object(builder,"show_announcement");
    userData->ScreenApp->gameContainer.p1_name = (GtkWidget *) gtk_builder_get_object(builder,"p1_name");
    userData->ScreenApp->gameContainer.p2_name = (GtkWidget *) gtk_builder_get_object(builder,"p2_name");
    userData->ScreenApp->gameContainer.p3_name = (GtkWidget *) gtk_builder_get_object(builder,"p3_name");

    g_signal_connect(userData->ScreenApp->gameContainer.turn_button, "clicked",G_CALLBACK(on_turn_clicked), userData);
    g_signal_connect(userData->ScreenApp->gameContainer.submit_button, "clicked",G_CALLBACK(on_submit_clicked), userData);
}



void initApp(UserData *userData){
    printf("init\n");
    initLoginScreen(userData);
    initMainScreen(userData);
    initRoomScreen(userData);
    initGameScreen(userData);
}


