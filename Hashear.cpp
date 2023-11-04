//
// Created by smora on 4/11/2023.
//

#include "Hashear.h"
#include "LineData.h"


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>


Hashear::Hashear() {

        myDoubleList = new myDoubleLinkedList();

}

std::string Hashear::hashKey(const std::string& key) {
    std::unordered_set<std::string> hashSet;
    std::hash<std::string> hasher;
    std::string hashedKey = key; // Inicializa hashedKey con el valor original

    while (true) {
        std::size_t hashValue = hasher(hashedKey);
        std::string hashString = std::to_string(hashValue);

        hashString.resize(10, '0');
        std::string result = hashString.substr(0, 10);

        if (hashSet.find(result) == hashSet.end()) {
            // No hay colisión, retornar el hash
            return result;
        } else {
            // Hay colisión, intentar con el siguiente hash
            hashedKey = result;
        }
    }
}


void Hashear::procesarArchivo(const std::string& rutaArchivo) {
    std::ifstream archivo(rutaArchivo);
    if (!archivo) {
        std::cout << "No se pudo abrir el archivo: " << rutaArchivo << '\n';
        return;
    }

    std::string linea;

    while (std::getline(archivo, linea)) {
        std::istringstream lineStream(linea);
        std::string token, key, restOfLine;

        if (std::getline(lineStream, token, ',')) {
            key = token;
            restOfLine = linea;  // restOfLine contiene toda la línea original
        }


        std::string hashedKey = hashKey(key);
        LineData lineData(hashedKey, restOfLine);
        myDoubleList->addSorted(lineData);
    }

    archivo.close();
}

