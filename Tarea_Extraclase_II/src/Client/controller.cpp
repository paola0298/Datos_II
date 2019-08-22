#include "client.cpp"
#include <stdio.h>
#include <string.h>
#include <jansson.h>

class Controller {
    
    public:
        Controller();
        int addToList(int value);
        int removeFromList();
        int modifyList(int value, int index);
        int get(int index);
        // void getList();
        int addToTree(int value);
        int removeFromTree(int value);
        // void getTree();
};


Controller::Controller(){}

int Controller::addToList(int value) {
    connect();

    json_t *action = json_object();

    json_object_set_new(action, "action", json_string("agregarL"));
    json_object_set_new(action, "value", json_integer(value));

    sendMessageToServer(action);

    printf("Esperando");
    json_t *response = receiveMessageFromServer();
    printf("Listo");
    json_t *statusJson = json_object_get(response, "Status");

    const char* status = json_string_value(statusJson);
    std::cout << "Status " << status << "\n";
    if (strcmp(status,"Success") == 0) {
        std::cout << "Status " << status << "\n";
        return 1;
    } else {
        return 0;
    }
}

int Controller::removeFromList(){
    connect();
    json_t *action = json_object();

    json_object_set_new(action, "action", json_string("eliminarL"));
    json_object_set_new(action, "value", json_integer(-1));

    sendMessageToServer(action);

    json_t *response = receiveMessageFromServer();
    json_t *statusJson = json_object_get(response, "Status");
    json_t *deletedJson = json_object_get(response, "deleted");

    const char* status = json_string_value(statusJson);
    int valueDeleted = json_integer_value(deletedJson);
    std::cout << "Status " << status << "\n";
    if (strcmp(status,"Success") == 0) {
        std::cout << "Status " << status << "\n";
        return valueDeleted;
    } else {
        return -1;
    }
}

int Controller::modifyList(int value, int index) {
    connect();
    json_t *action = json_object();

    json_object_set_new(action, "action", json_string("modificar"));
    json_object_set_new(action, "value", json_integer(value));
    json_object_set_new(action, "index", json_integer(index));

    sendMessageToServer(action);

    json_t *response = receiveMessageFromServer();
    json_t *statusJson = json_object_get(response, "Status");

    const char* status = json_string_value(statusJson);
    std::cout << "Status " << status << "\n";
    if (strcmp(status,"Success") == 0) {
        std::cout << "Status " << status << "\n";
        return 1;
    } else {
        return 0;
    }
}

int Controller::get(int index) {
    connect();
    json_t *action = json_object();

    json_object_set_new(action, "action", json_string("obtener"));
    json_object_set_new(action, "value", json_integer(index));

    sendMessageToServer(action);

    json_t *response = receiveMessageFromServer();
    json_t *statusJson = json_object_get(response, "Status");
    json_t *valueG = json_object_get(response, "get");

    const char* status = json_string_value(statusJson);
    int valueGetted = json_integer_value(valueG);

    std::cout << "Status " << status << "\n";
    if (strcmp(status,"Success") == 0) {
        // std::cout << "Status " << status << "\n";
        return valueGetted;
    } else {
        return -1;
    }
}

int Controller::addToTree(int value) {
    connect();

    json_t *action = json_object();

    json_object_set_new(action, "action", json_string("agregarT"));
    json_object_set_new(action, "value", json_integer(value));

    sendMessageToServer(action);

    json_t *response = receiveMessageFromServer();
    json_t *statusJson = json_object_get(response, "Status");

    const char* status = json_string_value(statusJson);
    std::cout << "Status " << status << "\n";
    if (strcmp(status,"Success") == 0) {
        std::cout << "Status " << status << "\n";
        return 1;
    } else {
        return 0;
    }
}

int Controller::removeFromTree(int value) {
    connect();

    json_t *action = json_object();

    json_object_set_new(action, "action", json_string("eliminarT"));
    json_object_set_new(action, "value", json_integer(value));

    sendMessageToServer(action);

    json_t *response = receiveMessageFromServer();
    json_t *statusJson = json_object_get(response, "Status");

    const char* status = json_string_value(statusJson);
    std::cout << "Status " << status << "\n";
    if (strcmp(status,"Success") == 0) {
        std::cout << "Status " << status << "\n";
        return 1;
    } else {
        return 0;
    }
}

// int main(int argc, char const *argv[]) {
//     Controller *contr = new Controller();
//     contr->addToList(1);
// }