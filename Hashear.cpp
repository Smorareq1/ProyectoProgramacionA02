//
// Created by smora on 4/11/2023.
//

#include "Hashear.h"
#include "LineData.h"

Hashear::Hashear() {

}

std::string Hashear::hashKey(const std::string& key) {
    std::hash<std::string> hasher;
    std::size_t hashedKey = hasher(key);
    return std::to_string(hashedKey).substr(0, 10);
}


void Hashear::procesarArchivo(const std::string& rutaArchivo, myDoubleLinkedList* myDoubleList) {
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

