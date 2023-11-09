//
// Created by smora on 4/11/2023.
//

#ifndef PROYECTOAPLICACION02_NODE_H
#define PROYECTOAPLICACION02_NODE_H

#include "LineData.h"
#include <string>

class Node {
public:
    LineData data;
    std::string value;

    Node* next;
    Node* prev;

    // Constructores
    Node(const LineData& newData);
    Node(const std::string& newValue);
};


#endif //PROYECTOAPLICACION02_NODE_H
