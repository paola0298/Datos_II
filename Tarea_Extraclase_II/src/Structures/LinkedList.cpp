#include "SimpleNode.cpp"
using namespace std;


class LinkedList {
    private:
        Node *head, *tail;
        int size;

    public:
        LinkedList();
        int getSize();
        void insertStart(int value);
        int deleteStart();
        void modify(int value, int index);
        int getValueAtPos(int index);
        void print();
};

LinkedList::LinkedList(){
    size = 0;
    head, tail = NULL;
}

int LinkedList::getSize(){
    return size;
}

void LinkedList::insertStart(int value) {
    Node *temp = new Node(value);
    if (size > 0) {
        temp->setNext(head);
    }

    head = temp;
    size++;
}

int LinkedList::deleteStart(){

    if (size>0){
        int value = head->getValue();
        Node *temp = head->getNext();
        delete(head);
        head = temp;
        size--;
        return value;
    }

    return -1;
}

void LinkedList::modify(int value, int index){
    if (index >= 0 && index < size){
        Node *temp = head;
        int count = 0;
        while (count<index) {
            temp = temp->getNext();
            count++;
        }
        temp->setValue(value);
    }
}

int LinkedList::getValueAtPos(int index){
    if (index >= 0 && index < size) {
        Node *temp = head;
        int count = 0;
        while (count<index) {
            temp = temp->getNext();
            count++;
        }
        return temp->getValue();
    } else {
        return -1;
    }
}

void LinkedList::print(){
    Node *temp = head;
    cout << "[";
    for (int i=0; i<size; i++) {
        if (i == size-1){
            cout << temp->getValue();
        } else {
            cout << temp->getValue() << ", ";
        }
        temp = temp->getNext();
    }

    cout << "]\n";
}

// int main(int argc, char *argv[]) { 
//     LinkedList *list = new LinkedList();
    
//     list->print();

//     list->insertStart(5);
//     list->insertStart(9);
//     list->insertStart(23);
//     list->insertStart(7);
//     list->insertStart(1);

//     list->print();

//     list->deleteStart();
//     list->deleteStart();

//     list->print();

//     list->modify(500, 0);

//     list->print();


// }