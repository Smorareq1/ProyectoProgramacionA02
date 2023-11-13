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
#include <limits>
#include <unordered_set>



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
    /////////////////////////////
    ////////// Iterando ////////////
    void addVector(const std::vector<std::string>& stringArray);
    void printListVector();
    void binarySearchVector(const std::string& value);
    void sortVector(std::vector<std::string>& stringArray);
    /////////////////////////////



};


#endif //PROYECTOAPLICACION02_MYDOUBLELINKEDLIST_H
