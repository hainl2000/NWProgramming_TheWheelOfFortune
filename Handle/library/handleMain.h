//
// Created by hainguyen on 29/12/2021.
//

#ifndef LTM_PROJECT_HANDLEMAIN_H
#define LTM_PROJECT_HANDLEMAIN_H

#include "structScreen.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>

void createRoom(int sockFd, UserData *userData);
void joinRandomRoom(int sockFd, UserData *userData);
void joinRoomByID(int sockFd,UserData *userData);


#endif //LTM_PROJECT_HANDLEMAIN_H
