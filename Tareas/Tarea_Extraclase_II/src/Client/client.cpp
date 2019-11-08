//
// Created by paola on 30/7/19.
//
// Client side C/C++ program to demonstrate Socket programming
#include <cstdio>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <jansson.h>
#include <assert.h>
#define PORT 8080

int sock = 0, valread;
struct sockaddr_in serv_addr;
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

void sendMessageToServer(json_t *message) {

    char *bufferJson = nullptr;
    std::string bufferSend;
    size_t size_json;
    
    //string of json
    bufferJson = json_dumps(message, JSON_PRESERVE_ORDER);
    std::cout << bufferJson << ", Json \n";
    size_json = strlen(bufferJson);

    // //size of json to string of json
    // bufferSend = std::to_string(static_cast<long long unsigned int>(size_json));

    send(sock , bufferJson, size_json , 0);
    printf("Message sent to server\n");

    for (int i=0; i<size_json; i++) {
        bufferJson[i] = '\0';
    }

    free(bufferJson);
    // printf("free\n");
}

json_t * receiveMessageFromServer() {

    // buffer[2048] = {0};
    // std::cout << buffer << ", buffer before read\n";

    // printf("Leyendo mensaje");
    valread = read(sock, buffer, 2048);
    std::cout << buffer << ", buffer \n";
    json_t *jsonRead = json_loads(buffer, JSON_PRESERVE_ORDER, NULL);
    // printf("Casting json\n");
    std::cout << jsonRead << "\n";
    return jsonRead;
}

// int main(int argc, char const *argv[]){
//     connect();
//     json_t *send = json_object();
//     json_object_set_new(send, "test", json_string("Hola")); 
//     sendMessageToServer(send);
//     std::cout << receiveMessageFromServer();
// }


