//
// Created by smora on 30/10/2023.
//

#ifndef PROYECTOAPLICACION02_MYDOUBLELINKEDLIST_H
#define PROYECTOAPLICACION02_MYDOUBLELINKEDLIST_H

#include <string>
#include "Node.h"
#include "LineData.h"

class myDoubleLinkedList {
private:
    Node *head;
    Node *tail;
    int size;

public:
    myDoubleLinkedList();
    ~myDoubleLinkedList();

    void addSorted(const LineData& data);
    void print();
    void binarySearch(std::string value);
    void clearList();
    int sizeOfMyList();
    ///////////////////////////// PRUEBA
    void addElement(const LineData& data);
    Node* partition(Node* low, Node* high);
    void quickSort(Node* low, Node* high);
    void sortList();
};


#endif //PROYECTOAPLICACION02_MYDOUBLELINKEDLIST_H
