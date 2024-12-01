#ifndef _HEADERS_H
#define _HEADERS_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<errno.h>
#include<stdbool.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<ifaddrs.h>
#include<stdbool.h>
#include<sys/time.h>
#include<dirent.h>
#include<sys/wait.h>

// error, status types

#define SUCCESS 1
#define INVALID_PATH_1 2
#define INVALID_PATH_2 3
#define INVALID_PATH 4
#define FILE_EXISTS 5
#define DIR_EXISTS 6
#define ACCESS_DENIED 7
#define ASYNC_IN_PROGRESS 8

// sizes on paths, etc.

#define PATHSIZE 1024
#define DATASEND 16384

// request types

#define READ_R 1
#define WRITE_R 2
#define APPEND_R 3
#define STREAM_R 4
#define COPY_R 5
#define LIST_R 6
#define CREATE_R 7
#define DELETE_R 8
#define INFO_R 9
#define A_WRITE_R 10
#define SS_INIT_R 11

// send-receive packet types

#define REQUEST_P 1
#define STATUS_P 2
#define DATA_P 3
#define SS_DETAILS_P 4

typedef struct st_REQUEST{

    int REQUEST_TYPE;
    char path1[PATHSIZE];
    char path2[PATHSIZE];    

}st_REQUEST;

typedef st_REQUEST* REQUEST;

typedef struct st_STATUS{

    int status;
    int REQUEST_TYPE;

}st_STATUS;

typedef st_STATUS* STATUS;

typedef struct st_DATA{

    int number_of_packets;
    char data[DATASEND];

}st_DATA;

typedef st_DATA* DATA;

typedef struct st_SS_DETAILS{

    char ip[100];
    int port;

}st_SS_DETAILS;

typedef st_SS_DETAILS* SS_DETAILS;

// functions from helper

void easterEgg();
REQUEST makeRequest(int REQUEST_TYPE, char* path1, char* path2);
void printError(int errorType, char* path1, char* path2);

#endif