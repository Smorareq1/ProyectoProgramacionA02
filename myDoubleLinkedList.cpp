#include "myDoubleLinkedList.h"
#include <iostream>

myDoubleLinkedList::myDoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

myDoubleLinkedList::~myDoubleLinkedList() {
    clearList();
}

void myDoubleLinkedList::clearList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}


void myDoubleLinkedList::print() {
    Node* current = head;
    while (current) {
        std::cout << current->data.hashedKey<< std::endl;
        current = current->next;
    }
}

void myDoubleLinkedList::binarySearch(std::string value) {
    int low = 0;
    int high = size - 1;
    bool found = false;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        Node* current = head;
        for (int i = 0; i < mid; i++) {
            current = current->next;
        }

        if (current->data.hashedKey == value) {
            found = true;
            std::cout << "Encontrado: " << current->data.restOfLine << std::endl;

            // Buscar hacia la izquierda
            Node* left = current->prev;
            while (left && left->data.hashedKey == value) {
                std::cout << "Encontrado: " << left->data.restOfLine << std::endl;
                left = left->prev;
            }

            // Buscar hacia la derecha
            Node* right = current->next;
            while (right && right->data.hashedKey == value) {
                std::cout << "Encontrado: " << right->data.restOfLine << std::endl;
                right = right->next;
            }
            break;
        } else if (current->data.hashedKey < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        std::cout << "No encontrado" << std::endl;
    }
}


int myDoubleLinkedList::sizeOfMyList() {
    return size;
}
///////////////////////////////////////////////////////
void myDoubleLinkedList::addElement(const LineData& data){
    Node* newNode = new Node{data};
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

Node* myDoubleLinkedList::partition(Node* low, Node* high) {
    LineData pivot = high->data;
    Node* i = low->prev;

    for (Node* j = low; j != high; j = j->next) {
        if (j->data < pivot) {
            i = (i == nullptr) ? low : i->next;
            std::swap(i->data, j->data);
        }
    }

    i = (i == nullptr) ? low : i->next;
    std::swap(i->data, high->data);
    return i;
}


void myDoubleLinkedList::quickSort(Node* low, Node* high) {
    if (high != nullptr && low != high && low != high->next) {
        Node* pivot = partition(low, high);
        quickSort(low, pivot->prev);
        quickSort(pivot->next, high);
    }
}

void myDoubleLinkedList::sortList() {
    quickSort(head, tail);
}
/////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////// BUSQUEDA POR VALOR

void myDoubleLinkedList::sortVector(std::vector<std::string>& stringArray) {
    std::sort(stringArray.begin(), stringArray.end());
}


void myDoubleLinkedList::addVector(const std::vector<std::string>& stringArray) {
    std::vector<std::string> sortedArray = stringArray;
    sortVector(sortedArray);

    Node* newNode = new Node{sortedArray};
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void myDoubleLinkedList::printListVector() {
    Node* current = head;
    while (current) {
        for (int i = 0; i < current->stringArray.size(); ++i) {
            std::cout << current->stringArray[i] << ",";
        }
        std::cout << std::endl;
        current = current->next;
    }
}


void myDoubleLinkedList::binarySearchVector(const std::string &value) {
    std::vector<std::vector<std::string>> results;
    Node* current = head;

    while (current) {
        if (current->stringArray.empty()) {
            current = current->next;
            continue;  // Saltar iteración si el vector está vacío
        }

        std::vector<std::string>& array = current->stringArray;
        int arraySize = array.size();

        for (int i = 0; i < arraySize; ++i) {
            if (array[i] == value) {
                results.push_back(array);
                break;  // Salir del bucle una vez que se encuentra una coincidencia
            }
        }

        current = current->next;
    }

    for (const auto& result : results) {
        for (const auto& element : result) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}




















