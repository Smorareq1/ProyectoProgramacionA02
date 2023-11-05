//
// Created by smora on 4/11/2023.
//

#ifndef PROYECTOAPLICACION02_NODE_H
#define PROYECTOAPLICACION02_NODE_H

#include "LineData.h"

class Node {
public:
    LineData data;
    Node* next;
    Node* prev;

    Node(const LineData& newData);
};


#endif //PROYECTOAPLICACION02_NODE_H
