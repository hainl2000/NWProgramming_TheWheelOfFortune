//
// Created by hainguyen on 29/12/2021.
//

#ifndef LTM_PROJECT_INITCLIENT_H
#define LTM_PROJECT_INITCLIENT_H

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "structScreen.h"
#include "clientError.h"

int initSocket(char *address,int port, UserData *userData);

#endif //LTM_PROJECT_INITCLIENT_H
