//
// Created by smora on 4/11/2023.
//

#ifndef PROYECTOAPLICACION02_NODE_H
#define PROYECTOAPLICACION02_NODE_H

#include "LineData.h"
#include <string>
#include <vector>

class Node {
public:
    LineData data;
    std::string value;
    //
    std::vector<std::string> stringArray;

    Node* next;
    Node* prev;

    // Constructores
    Node();
    Node(const LineData& newData);
    Node(const std::vector<std::string>& stringArray);
};


#endif //PROYECTOAPLICACION02_NODE_H
