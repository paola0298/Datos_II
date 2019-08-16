//
// Created by paola on 30/7/19.
//


// Server side C/C++ program to demonstrate Socket programming
#include <unistd.h>
#include <cstdio>
#include <sys/socket.h>
#include <cstdlib>
#include <netinet/in.h>
#include <cstring>
#define PORT 8080
int main(int argc, char const *argv[])
{
    while (true) {
        int server_fd, new_socket, valread;
        sockaddr_in address;
        int opt = 1;
        int addrlen = sizeof(address);
        char buffer[2048] = {0};
        const char *hello = "Hola desde el servidor";
        const char *estado = "Bien y usted?";
        const char *bye = "Adios desde el servidor";
        const char *noReconocido = "Palabra no reconocida";


        // Creating socket file descriptor
        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
            perror("socket failed");
            exit(EXIT_FAILURE);
        }

        // Forcefully attaching socket to the port 8080
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                       &opt, sizeof(opt))) {
            perror("setsockopt");
            exit(EXIT_FAILURE);
        }
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);

        // Forcefully attaching socket to the port 8080
        if (bind(server_fd, (struct sockaddr *) &address,
                 sizeof(address)) < 0) {
            perror("bind failed");
            exit(EXIT_FAILURE);
        }
        if (listen(server_fd, 3) < 0) {
            perror("listen");
            exit(EXIT_FAILURE);
        }
        if ((new_socket = accept(server_fd, (struct sockaddr *) &address,
                                 (socklen_t *) &addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        valread = read(new_socket, buffer, 2048);
        printf("%s\n", buffer);
        if (strcmp(buffer, "Hola") == 0){

            send(new_socket, hello, strlen(hello), 0);
        } else if (strcmp(buffer, "Como esta") == 0){
            send(new_socket, estado, strlen(estado), 0);
        } else if (strcmp(buffer, "Bien gracias") == 0){
        	send(new_socket, bye, strlen(bye), 0);
        } else {
        	send(new_socket, noReconocido, strlen(bye), 0);
        }
        printf("Message sent from server\n");
        close(server_fd);
    }

    return 0;
}
