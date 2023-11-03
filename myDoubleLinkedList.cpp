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

void myDoubleLinkedList::print() {
    Node* current = head;
    while (current) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

int myDoubleLinkedList::sizeOfMyList() {
    return size;
}

void myDoubleLinkedList::binarySearch(std::string value) {
    int low = 0;
    int high = size - 1;
    bool found = false;

    while (low <= high) {
        int mid = (low + high) / 2;
        Node* current = head;
        for (int i = 0; i < mid; i++) {
            current = current->next;
        }

        if (current->data == value) {
            found = true;
            std::cout << current->data << std::endl;

            // Buscar hacia la izquierda
            Node* left = current->prev;
            while (left && left->data == value) {
                std::cout << left->data << std::endl;
                left = left->prev;
            }

            // Buscar hacia la derecha
            Node* right = current->next;
            while (right && right->data == value) {
                std::cout << right->data << std::endl;
                right = right->next;
            }
            break;
        } else if (current->data > value) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (!found) {
        std::cout << "Not found" << std::endl;
    }
}