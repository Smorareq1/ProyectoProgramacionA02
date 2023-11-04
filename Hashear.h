//
// Created by smora on 4/11/2023.
//

#ifndef PROYECTOAPLICACION02_HASHEAR_H
#define PROYECTOAPLICACION02_HASHEAR_H


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "myDoubleLinkedList.h"

class Hashear {
public:
    Hashear();
    std::string hashKey(const std::string& key);
    void procesarArchivo(const std::string& filename);

    myDoubleLinkedList* myDoubleList;
};




#endif //PROYECTOAPLICACION02_HASHEAR_H
