//
// Created by smora on 4/11/2023.
//

#include "Node.h"

Node::Node(const LineData& newData) : data(newData), next(nullptr), prev(nullptr) {}

Node::Node(const std::string& newValue) : value(newValue), next(nullptr), prev(nullptr) {}

