//
// Created by smora on 4/11/2023.
//

#include "Node.h"


Node::Node(){}
Node::Node(const LineData& newData) : data(newData), next(nullptr), prev(nullptr) {}
Node::Node(const std::vector<std::string>& stringArray) : stringArray(stringArray), next(nullptr), prev(nullptr) {}

