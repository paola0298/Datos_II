#include <iostream>

class Node {
    private:
         int value;
         Node *next = NULL;
        
    public:
        Node(int value);
        int getValue();
        void setValue(int value);
        Node * getNext();
        void setNext(Node* next);
};

Node::Node(int value) {
    this->value = value;
}

int Node::getValue() {
    return value;
}

void Node::setValue(int value) {
    this->value = value;
}

Node* Node::getNext() {
    return next;
}

void Node::setNext(Node* next) {
    this->next = next;
}
