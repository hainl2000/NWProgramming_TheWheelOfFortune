//
// Created by hainguyen on 30/12/2021.
//

#include "stdio.h"
#include "handleClient.h"
#include "structScreen.h"
#include "string.h"
#include "stdio.h"
#include "gtk/gtk.h"
#include "LoginController.h"
#include "gameController.h"
#include "constant.h"

void on_turn_clicked(GtkButton *button, UserData *userData)
{

}

void on_submit_clicked(GtkButton *button, UserData *userData)
{
    char *character = (char *) gtk_entry_get_text(GTK_ENTRY(userData->ScreenApp->gameContainer.value_input));
    printf("%s\n",character);
}
