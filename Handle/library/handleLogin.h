//
// Created by hainguyen on 01/01/2022.
//

#ifndef LTM_PROJECT_HANDLELOGIN_H
#define LTM_PROJECT_HANDLELOGIN_H

#include "structScreen.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include "constant.h"

int loginUser(int sockFd,UserData *userData);
int registerUser(int sockFd,UserData *userData);



#endif //LTM_PROJECT_HANDLELOGIN_H
