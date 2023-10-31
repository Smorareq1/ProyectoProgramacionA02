//
// Created by smora on 30/10/2023.
//

#include "myDoubleLinkedList.h"

#include <iostream>

myDoubleLinkedList::myDoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {} //Constructor

myDoubleLinkedList::~myDoubleLinkedList() { //Destructor
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void myDoubleLinkedList::addSorted(std::string data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        Node* current = head;
        while (current) {
            if (current->data > data) {
                if (current == head) {
                    newNode->next = current;
                    current->prev = newNode;
                    head = newNode;
                } else {
                    newNode->next = current;
                    newNode->prev = current->prev;
                    current->prev->next = newNode;
                    current->prev = newNode;
                }
                break;
            } else if (current == tail) {
                newNode->prev = current;
                current->next = newNode;
                tail = newNode;
                break;
            }
            current = current->next;
        }
    }
    size++;
}