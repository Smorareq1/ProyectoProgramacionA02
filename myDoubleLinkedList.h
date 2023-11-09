//
// Created by smora on 30/10/2023.
//

#ifndef PROYECTOAPLICACION02_MYDOUBLELINKEDLIST_H
#define PROYECTOAPLICACION02_MYDOUBLELINKEDLIST_H

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
#include <iterator>


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


    void print(); //pruebas
    void binarySearch(std::string value);
    void clearList();
    int sizeOfMyList();

    ///////////////////////////// Hashed Key
    void addElement(const LineData& data);
    Node* partition(Node* low, Node* high);
    void quickSort(Node* low, Node* high);
    void sortList();
    ///////////////////////////// Por valor
    Node* getNodeAt(int index) const;
    void addElementByValue(std::string value);


    void sortColumns(int column);


    int countColumns(const std::string& value);
    void printByValue();//pruebas

    void binarySearchByColumn(int column, const std::string& value);

};


#endif //PROYECTOAPLICACION02_MYDOUBLELINKEDLIST_H
