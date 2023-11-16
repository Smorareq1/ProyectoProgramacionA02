#include "myDoubleLinkedList.h"
#include <iostream>

myDoubleLinkedList::myDoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {} //Constructor

myDoubleLinkedList::~myDoubleLinkedList() { //Destructor
    clearList();
}

void myDoubleLinkedList::clearList() { //Funcion para limpiar la lista
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


int myDoubleLinkedList::sizeOfMyList() { //Funcion para obtener el tamanio de la lista
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

void myDoubleLinkedList::sortHashList() { //Funcion para ordenar la lista
    std::vector<LineData> elementos;

    while (head != nullptr) { //Meter los datos al vector
        elementos.push_back(head->data);
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        delete temp;
    }


    std::sort(elementos.begin(), elementos.end()); //Ordenar el vector
    clearList(); //Limpiar la lista

    for (const LineData& elemento : elementos) { //Meter los datos ordenados a la lista
        addElement(elemento);
    }
}
/////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////// BUSQUEDA POR VALOR

void myDoubleLinkedList::addVector(const std::vector<std::string>& stringArray) {//Funcion para agregar un vector a la lista

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

void myDoubleLinkedList::printListVector() { //pruebas
    Node* current = head;
    while (current) {
        for (int i = 0; i < current->stringArray.size(); ++i) {
            std::cout << current->stringArray[i] << ",";
        }
        std::cout << std::endl;
        current = current->next;
    }
}


void myDoubleLinkedList::binarySearchVector(const std::string &value) { //Busqueda binaria por valor
    Node* current = head;
    bool found = false;

    while (current) { //Recorrer la lista
        if (!current->stringArray.empty()) { //Si el vector no esta vacio
            std::vector<std::string>& array = current->stringArray;

            // Ordenar el vector
            std::sort(array.begin(), array.end());

            // Buscar el valor en el vector ordenado
            if (std::binary_search(array.begin(), array.end(), value)) {
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
    // Si no se encontro el valor
    if (!found) {
        std::cout << "Valor no encontrado." << std::endl;
    }
}





























