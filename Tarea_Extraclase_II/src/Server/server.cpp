//
// Created by paola on 30/7/19.
//


// Server side C/C++ program to demonstrate Socket programming
#include <unistd.h>
#include <cstdio>
#include <iostream>
#include <sys/socket.h>
#include <cstdlib>
#include <netinet/in.h>
#include <cstring>
#include <jansson.h>
#include <assert.h>
#include "../Structures/LinkedList.cpp"
#include "../Structures/BinaryTree.cpp"
#define PORT 8080

// int server_fd, new_socket, valread;
// sockaddr_in address;
// int opt = 1;
// int addrlen = sizeof(address);


// const char *hello = "Hola desde el servidor";
// const char *estado = "Bien y usted?";
// const char *bye = "Adios desde el servidor";
// const char *noReconocido = "Palabra no reconocida";


int server_fd, new_socket, valread;
sockaddr_in address;
int opt = 1;
int addrlen = sizeof(address);
char buffer[2048] = {0};
LinkedList *list = new LinkedList();
BinaryTree *tree = new BinaryTree();

bool prepare() {
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
            perror("socket failed");
            exit(EXIT_FAILURE);
            return false;
        }

        // Forcefully attaching socket to the port 8080
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                       &opt, sizeof(opt))) {
            perror("setsockopt");
            exit(EXIT_FAILURE);
            return false;
        }
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);

        // Forcefully attaching socket to the port 8080
        if (bind(server_fd, (struct sockaddr *) &address,
                 sizeof(address)) < 0) {
            perror("bind failed");
            exit(EXIT_FAILURE);
            return false;
        }
        if (listen(server_fd, 3) < 0) {
            perror("listen");
            exit(EXIT_FAILURE);
            return false;
        }

        return true;
}


bool connect() {
    // Creating socket file descriptor
        std::cout <<"Esperando nueva conexion\n";
        if ((new_socket = accept(server_fd, (struct sockaddr *) &address,
                                 (socklen_t *) &addrlen)) < 0) {
            printf("accept");
            exit(EXIT_FAILURE);
            return false;
        }

        std::cout <<"Conectado\n";

    return true;
}

json_t * receiveMessageFromClient() {
    printf("Reading..\n");
    valread = read(new_socket, buffer, 2048);
    std::cout << buffer << ", buffer \n";
    json_t *jsonRead = json_loads(buffer, JSON_PRESERVE_ORDER, NULL);
    printf("Casting json\n");
    std::cout << jsonRead << "\n";
    return jsonRead;

}

void sendMessageToClient(json_t *message) {
    
    char *bufferJson = nullptr;
    std::string bufferSend;
    size_t size_json;

    //string of json
    bufferJson = json_dumps(message, JSON_PRESERVE_ORDER);
    size_json = strlen(bufferJson);

    // //size of json to string of json
    // bufferSend = std::to_string(static_cast<long long unsigned int>(size_json));
    // bufferSend += "#";
    // bufferSend += std::string(bufferJson);


    send(new_socket, bufferJson, size_json, 0);

    for (int i=0; i<size_json; i++) {
        bufferJson[i] = '\0';
    }

    free(bufferJson);
}

void connectionListener() {
    prepare();

    while (true) {
        
        if (connect()) {
            json_t *message = receiveMessageFromClient();
            json_t *actionJson = json_object_get(message, "action");
            json_t *valueJson = json_object_get(message, "value");

            const char* action = json_string_value(actionJson);
            int value = json_integer_value(valueJson);

            std::cout <<"action " << action << "\n";
            std::cout <<"value " << value << "\n";

            if (strcmp(action, "agregarL") == 0){
                std::cout << "Adding to list\n";
                list->insertStart(value);
                list->print();
                json_t *response = json_object();
                json_object_set_new(response, "Status", json_string("Success"));
                sendMessageToClient(response);
                std::cout << "Response sent\n";
            } else if (strcmp(action, "eliminarL") == 0) {
                std::cout << "Removing from list\n";
                int deleted = list->deleteStart();
                list->print();
                json_t *response = json_object();
                json_object_set_new(response, "Status", json_string("Success"));
                json_object_set_new(response, "deleted", json_integer(deleted));
                sendMessageToClient(response);
                std::cout << "Response sent\n";

            } else if (strcmp(action, "modificar") == 0) {
                json_t *indexJson = json_object_get(message, "index");
                int index = json_integer_value(indexJson);
                std::cout <<"index " << index << "\n";
                std::cout << "Modifying list in position " << index << " \n";
                list->modify(value, index);
                list->print();
                json_t *response = json_object();
                json_object_set_new(response, "Status", json_string("Success"));
                sendMessageToClient(response);
                std::cout << "Response sent\n";

            } else if (strcmp(action, "obtener") == 0) {
                std::cout << "Getting from list\n";
                int valueGetted = list->getValueAtPos(value);
                list->print();
                json_t *response = json_object();
                json_object_set_new(response, "Status", json_string("Success"));
                json_object_set_new(response, "get", json_integer(valueGetted));
                sendMessageToClient(response);
                std::cout << "Response sent\n";

            } else if (strcmp(action, "agregarT") == 0) {
                std::cout << "Adding to Tree\n";
                tree->add(value);
                tree->inorder();
                json_t *response = json_object();
                json_object_set_new(response, "Status", json_string("Success"));
                sendMessageToClient(response);
                std::cout << "Response sent\n";
            } else {
                std::cout << "Removing from Tree\n";
                tree->deleteValue(value);
                tree->inorder();
                json_t *response = json_object();
                json_object_set_new(response, "Status", json_string("Success"));
                sendMessageToClient(response);
                std::cout << "Response sent\n";
            }
            // std::cout<<"closing connection \n";
            // close(server_fd);
        } else {
            json_t *response = json_object();
            json_object_set_new(response, "Status", json_string("Failed"));
            sendMessageToClient(response);
        }
    }
}


int main(int argc, char const *argv[]) {

    tree->add(5);
    tree->add(51);
    tree->add(10);
    tree->add(5);
    tree->add(2);
    tree->add(1);

    tree->inorder();

    std::cout <<"\n";

    list->insertStart(5);
    list->insertStart(9);
    list->insertStart(23);
    list->insertStart(7);
    list->insertStart(1);

    list->print();

    

    connectionListener();

    return 0;
}
