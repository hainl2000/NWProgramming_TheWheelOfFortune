//
// Created by hainguyen on 29/12/2021.
//

#ifndef LTM_PROJECT_HANDLECLIENT_H
#define LTM_PROJECT_HANDLECLIENT_H

#include "structScreen.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
int loginUser(int sockFd,char *username);
int sendValue();
int sendChar();

#endif //LTM_PROJECT_HANDLECLIENT_H
