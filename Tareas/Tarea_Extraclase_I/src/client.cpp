//
// Created by paola on 30/7/19.
//
// Client side C/C++ program to demonstrate Socket programming
#include <cstdio>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#define PORT 8080

int sock = 0, valread;
struct sockaddr_in serv_addr;
char *hello = "Hello";
char buffer[2048] = {0};

bool connect() {

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return false;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return false;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return false;
    }
    return true;
}

void sendMessageToServer(char *message) {
    send(sock , message , strlen(message) , 0);
    printf("Message sent to server\n");
}

char * receiveMessageFromServer() {
    valread = read( sock , buffer, 2048);
    printf("Message receiven from server\n");
    printf("%s\n",buffer );
    return buffer;

}

