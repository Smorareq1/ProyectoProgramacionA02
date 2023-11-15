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


void myDoubleLinkedList::print() { //[pruebas]
    Node* current = head;
    while (current) {
        std::cout << current->data.hashedKey<< std::endl;
        current = current->next;
    }
}

void myDoubleLinkedList::binarySearch(std::string value) { //Busqueda binaria por hashedKey
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

void myDoubleLinkedList::sortHashList() {
    std::vector<LineData> elementos;

    while (head != nullptr) {
        elementos.push_back(head->data);
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        delete temp;
    }


    std::sort(elementos.begin(), elementos.end());
    clearList();

    for (const LineData& elemento : elementos) {
        addElement(elemento);
    }
}
/////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////// BUSQUEDA POR VALOR

void myDoubleLinkedList::sortVector(std::vector<std::string>& stringArray) {
    std::sort(stringArray.begin(), stringArray.end());
}


void myDoubleLinkedList::addVector(const std::vector<std::string>& stringArray) {

    Node* newNode = new Node{stringArray};
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
    Node* current = head;
    bool found = false;

    while (current) {
        if (!current->stringArray.empty()) {
            std::vector<std::string>& array = current->stringArray;


            std::sort(array.begin(), array.end());

            // Busqueda binaria
            auto range = std::equal_range(array.begin(), array.end(), value);

            if (range.first != range.second) {
                found = true;
                std::cout << "Vector completo: ";
                for (const auto& element : array) {
                    std::cout << element << " ";
                }
                std::cout << std::endl;
            }
        }

        current = current->next;
    }

    if (!found) {
        std::cout << "Valor no encontrado." << std::endl;
    }
}




























