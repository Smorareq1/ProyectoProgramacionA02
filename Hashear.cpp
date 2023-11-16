//
// Created by smora on 4/11/2023.
//

#include "Hashear.h"
#include "LineData.h"

Hashear::Hashear() {
}

std::string Hashear::hashKey(const std::string& key) { //Funcion para hashear la key
    std::hash<std::string> hasher;
    std::size_t hashedKey = hasher(key);
    return std::to_string(hashedKey).substr(0, 10);
}

std::vector<std::string> Hashear::stringToVector(std::string &str) { //Funcion para convertir un string en un vector
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, ',')) {
        result.push_back(token);
    }

    return result;
}


void Hashear::procesarArchivo(const std::string& rutaArchivo, myDoubleLinkedList* myDoubleListHash, myDoubleLinkedList* myDoubleLinkedListValues) {
    std::ifstream archivo(rutaArchivo);

    if (!archivo) { //Si no se puede abrir el archivo
        std::cout << "No se pudo abrir el archivo: " << rutaArchivo << '\n';
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {  // Mientras se pueda leer una línea del archivo
        std::istringstream lineStream(linea);
        std::string token, key, restOfLine;

        if (std::getline(lineStream, token, ',')) {
            key = token;
            restOfLine = linea;  // restOfLine contiene toda la línea original
        }

        std::string hashedKey = hashKey(key);
        LineData lineData(hashedKey, restOfLine);

        myDoubleListHash->addElement(lineData);
        //Values//
        std::vector<std::string> result = stringToVector(restOfLine);
        myDoubleLinkedListValues->addVector(result);
    }

    archivo.close();
}

