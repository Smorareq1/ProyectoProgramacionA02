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

void myDoubleLinkedList::printByValue() {
    Node* current = head;
    while (current) {
        std::cout << current->value << std::endl;
        current = current->next;
    }
}

void myDoubleLinkedList::addElementByValue(std::string value){
    Node* newNode = new Node{value};
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
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
void myDoubleLinkedList::sortColumns(int column) {
    std::vector<Node*> nodes;
    Node* current = head;
    while (current) {
        nodes.push_back(current);
        current = current->next;
    }

    std::sort(nodes.begin(), nodes.end(), [column](Node* a, Node* b) {
        std::istringstream streamA(a->value);
        std::istringstream streamB(b->value);
        std::string tokenA, tokenB;
        for (int i = 0; i < column; ++i) {
            std::getline(streamA, tokenA, ',');
            std::getline(streamB, tokenB, ',');
        }
        return tokenA < tokenB;
    });

    head = nodes[0];
    tail = nodes.back();
    for (size_t i = 1; i < nodes.size(); ++i) {
        nodes[i]->prev = nodes[i - 1];
        nodes[i - 1]->next = nodes[i];
    }
    tail->next = nullptr;
}
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
int myDoubleLinkedList::countColumns(const std::string &value) {
    std::istringstream stream(value);
    std::string token;
    int count = 0;
    while (std::getline(stream, token, ',')) {
        ++count;
    }
    return count;
}

Node* myDoubleLinkedList::getNodeAt(int index) const {
    if (index < 0 || index >= size) {
        return nullptr;
    }

    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    return current;
}


void myDoubleLinkedList::binarySearchByColumn(int column, const std::string& value) {
    sortColumns(column);
    std::vector<std::string> results; // Vector para almacenar las coincidencias

    // Búsqueda binaria
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Evitar desbordamiento

        Node* current = getNodeAt(mid);
        std::istringstream stream(current->value);
        std::string token;
        for (int i = 0; i < column; ++i) {
            std::getline(stream, token, ',');
        }

        if (token == value) {
            results.push_back(current->value);

            // Buscar a la izquierda
            int leftIndex = mid - 1;
            while (leftIndex >= 0) {
                Node* leftNode = getNodeAt(leftIndex);
                std::istringstream leftStream(leftNode->value);
                std::string leftToken;
                for (int i = 0; i < column; ++i) {
                    std::getline(leftStream, leftToken, ',');
                }

                if (leftToken == value) {
                    results.push_back(leftNode->value);
                } else {
                    break;  // Romper si no hay más coincidencias a la izquierda
                }

                --leftIndex;
            }

            // Buscar a la derecha
            int rightIndex = mid + 1;
            while (rightIndex < size) {
                Node* rightNode = getNodeAt(rightIndex);
                std::istringstream rightStream(rightNode->value);
                std::string rightToken;
                for (int i = 0; i < column; ++i) {
                    std::getline(rightStream, rightToken, ',');
                }

                if (rightToken == value) {
                    results.push_back(rightNode->value);
                } else {
                    break;  // Romper si no hay más coincidencias a la derecha
                }

                ++rightIndex;
            }

            break;  // Romper después de manejar todas las coincidencias
        }

        if (token <= value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Mostrar las coincidencias encontradas
    if (!results.empty()) {
        std::cout << "Coincidencias encontradas en columna " << column << ":" << std::endl;
        for (const auto& match : results) {
            std::cout << match << std::endl;
        }
    }

    // Llamada recursiva para la siguiente columna
    if (column < countColumns(head->value)) {
        binarySearchByColumn(column + 1, value);
    }
}













