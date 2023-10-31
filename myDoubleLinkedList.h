//
// Created by smora on 30/10/2023.
//

#ifndef PROYECTOAPLICACION02_MYDOUBLELINKEDLIST_H
#define PROYECTOAPLICACION02_MYDOUBLELINKEDLIST_H

#include <string>

struct Node {
    std::string data;
    Node *next;
    Node *prev;
};

class myDoubleLinkedList {
private:
    Node *head;
    Node *tail;
    int size;

public:
    myDoubleLinkedList();
    ~myDoubleLinkedList();

    void addSorted(std::string data);
    void print();
    int sizeOfMyList();
};


#endif //PROYECTOAPLICACION02_MYDOUBLELINKEDLIST_H
