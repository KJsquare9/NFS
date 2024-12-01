#include"headers.h"

extern int sock;


void easterEgg() 
{
    printf("                    ***********************\n");
    printf("               *********************************\n");
    printf("           *******   *     *       *    *    *******\n");
    printf("        *******   ***      **     **     ***   *******\n");
    printf("      ******   *****       *********      *****    *****\n");
    printf("    ******  ********       *********       ******    *****\n");
    printf("   ****   **********       *********       *********   *****\n");
    printf("  ****  **************    ***********     ************   ****\n");
    printf(" ****  *************************************************  ****\n");
    printf("****  ***************************************************  ****\n");
    printf("****  ****************************************************  ****\n");
    printf("****  ****************************************************  ****\n");
    printf("****  ***************************************************  ****\n");
    printf(" ****  *******     ****  ***********  ****     *********  ****\n");
    printf("   ****   *****      *      *******      *      ********  ****\n");
    printf("    *****   ****             *****             ******   *****\n");
    printf("      *****   **              ***              **    ******\n");
    printf("       ******   *              *              *   *******\n");
    printf("         *******                                *******\n");
    printf("            ********                         *******\n");
    printf("               *********************************\n");
    printf("                    ***********************\n");
}

REQUEST makeRequest(int REQUEST_TYPE, char* path1, char* path2){

    REQUEST req = (REQUEST)malloc(sizeof(st_REQUEST));
    req->REQUEST_TYPE = REQUEST_TYPE;
    strcpy(req->path1, path1);
    strcpy(req->path2, path2);

    return req;

}

void printError(int errorType, char* path1, char* path2)
{

    if(errorType == 1)
    {
        printf("Connected to SS!\n");
    }
    else if(errorType == 2)
    {
        printf("Error! Invalid path : %s\n", path1);
    }
    else if(errorType == 3)
    {
        printf("Error! Invalid path : %s\n", path2);
    }
    else if(errorType == 4)
    {
        printf("Error! File not found : %s\n", path1);
    }
    else if(errorType == 5)
    {
        printf("Error! File already exists!\n");
    }
    else if(errorType == 6)
    {
        printf("Error! Directory already exists!\n");
    }
    else if(errorType == 7)
    {
        printf("Error! Access denied\n");
    }
    else if(errorType == 8)
    {
        printf("Asynchronous write has been started\n");
    }
    else
    {
        printf("Error! Unknown error\n");
    }

    return;

}

void READhandler(int SS_port, char SS_IP[20])
{

    // create a new socket to connect to the Storage Server

    int sock_SS = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_SS < 0)
    {
        perror("Error in creating socket\n");
        return;
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SS_port);

    if(inet_pton(AF_INET, SS_IP, &serv_addr.sin_addr) <= 0)
    {
        perror("Invalid address or address not supported\n");
        return;
    }

    if(connect(sock_SS, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Connection failed\n");
        return;
    }

    // printf("Connected to Storage Server\n");

    // receive packets from the Storage Server

    char** data = NULL;
    char temp[DATASEND];
    int number_of_packets = 0;
    // demarcate the first packet received, useful for the memory allocation, to record the number of packets
    int counter = 0;

    while(1){

        // keep receiving send-receive packet type, followed by the actual packet;

        int packet_type;
        recv(sock_SS, &packet_type, sizeof(int), 0);

        // in case of error, break the loop

        if(packet_type == STATUS_P)
        {
            STATUS status;
            recv(sock_SS, status, sizeof(st_STATUS), 0);
            printError(status->status, NULL, NULL);
            break;
        }

        // in case of data packet, store the data

        else if(packet_type == DATA_P){

            if(counter == 0)
            {
                
            }
            else
            {

            }

        }
        

    }

    return 0;

}