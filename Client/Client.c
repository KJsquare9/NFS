#include"../headers.h"

int SERVER_PORT;
char SERVER_IP[20];
int sock;

int main(){

    printf("Enter the server IP: ");
    scanf("%s", SERVER_IP);
    printf("Enter the server port: ");
    scanf("%d", &SERVER_PORT);
 
    struct sockaddr_in serv_addr;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);

     // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("Invalid address or address not supported\n");
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed\n");
        return -1;
    }

    printf("Connected to server\n\n");

    // print all the available commands

    printf("Available commands:\n");
    printf("1. READ <path>\n");
    printf("2. WRITE <path> --SYNC (optional)\n");
    printf("3. APPEND <path>\n");
    printf("4. STREAM <path>\n");
    printf("5. COPY <source> <destination>\n");
    printf("6. LIST\n");
    printf("7. CREATE <path> <name>\n");
    printf("8. DELETE <path>\n");
    printf("9. INFO <path>\n");

    char command[100];

    while(1){

        // make a packet to send to the server

        printf("Enter command: ");

        scanf("%s", command);
        char* token = strtok(command, " ");
        if(strcmp(token, "READ") == 0)
        {
            token = strtok(NULL, " ");
            if(token == NULL)
            {
                // EASTER EGG
                easterEgg();
            }
            else
            {
                
                // send the request to the Naming Server

                REQUEST req = makeRequest(READ_R, token, "");
                int packet_type = REQUEST_P;
                send(sock, &packet_type, sizeof(int), 0);
                send(sock, req, sizeof(st_REQUEST), 0);

                // receive the status from the Naming Server

                STATUS status;
                recv(sock, status, sizeof(st_STATUS), 0);
                
                printError(status->status, req->path1, req->path2);
                if(status->status != 1){
                    continue;
                }

                // receive the Storage data information from the Naming Server

                SS_DETAILS ss_details;
                recv(sock, ss_details, sizeof(st_SS_DETAILS), 0);

                // create a function, which will connect to the Storage Server and get the data

            }

        }
        else if(strcmp(token, "WRITE") == 0)
        {

        }
        else if(strcmp(token, "APPEND") == 0)
        {

        }
        else if(strcmp(token, "STREAM") == 0)
        {

        }
        else if(strcmp(token, "COPY") == 0)
        {

        }
        else if(strcmp(token, "LIST") == 0)
        {

        }
        else if(strcmp(token, "CREATE") == 0)
        {

        }
        else if(strcmp(token, "DELETE") == 0)
        {

        }
        else if(strcmp(token, "INFO") == 0)
        {

        }
        else
        {
            printf("Invalid command, please try again!\n");
        }
    }
    
}