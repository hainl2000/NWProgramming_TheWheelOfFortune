//
// Created by hainguyen on 01/01/2022.
//

#ifndef LTM_PROJECT_CLIENTERROR_H
#define LTM_PROJECT_CLIENTERROR_H

#define ERROR_CREATE_SOCKET -1      //"Can't create socket!"
#define ERROR_CONNECT_FAIL -2       //"Can't connect to server!"
#define ERROR_INVALID_PARAMS -3       //"Invalid params!"

void printErrorMessage(int error);

#endif //LTM_PROJECT_CLIENTERROR_H
