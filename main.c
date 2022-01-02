#include <stdio.h>
#include <gtk/gtk.h>

#include "InitScreen.h"
#include "InitClient.h"

#define PORT 5550
#define ADD_R "127.0.0.1"

int main(int argc, char *argv[]) {
    UserData userData;
    ScreenApp screenApp;
    gtk_init(&argc, &argv);

    if ((userData.sockFd = initSocket(ADD_R, PORT, &userData)) <= 0)
        return userData.sockFd;

    userData.ScreenApp = &screenApp;
    initApp(&userData);
//    printf("init done\n");
    gtk_widget_show(screenApp.loginContainer.login_window);
    gtk_main();
    return 0;
}