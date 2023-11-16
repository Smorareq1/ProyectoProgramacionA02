#include <iostream>
#include <cstring>
#include <limits>

#include "myDoubleLinkedList.h"
#include "Hashear.h"

using namespace std;

//Creacion de variables en el heap por que se requiere conservar las funciones y listas
void menuPrincipal();
myDoubleLinkedList *listahash = new myDoubleLinkedList();
myDoubleLinkedList *listavalue = new myDoubleLinkedList();
Hashear *hashear = new Hashear();



/////////////////////////////////////////////////////////////////////////////////////
void pruebas(){ //pruebas de las listas
    listavalue->printListVector();
}
/////////////////////////////////////////////////////////////////////////////////////
void cargarDatos(){ //Funcion para procesar el archivo y cargar los datos en las listas

    string nombreArchivo;
    cout<<"Ingrese el nombre del archivo que desea cargar: "<<endl;
    std::cin.ignore();
    std::getline(std::cin, nombreArchivo);
    hashear->procesarArchivo(nombreArchivo, listahash, listavalue);
    cout<<"Ordenando Lista"<<endl;
    listahash->sortHashList();


    cout<<"Tamanio de las listas: "<<endl;
    cout<<listahash->sizeOfMyList()<<endl;
    cout<<listavalue->sizeOfMyList()<<endl;

    menuPrincipal();

}
/////////////////////////////////////////////////////////////////////////////////////
void buscarPorKey(){ //Funcion para buscar por key
    string key, result;
    cout<<"Ingrese la key que desea buscar: "<<endl;
    std::cin.ignore();
    std::getline(std::cin, key);

    result = hashear->hashKey(key);
    listahash->binarySearch(result);
    menuPrincipal();
}
/////////////////////////////////////////////////////////////////////////////////////
void buscarPorValor(){ //Funcion para buscar por valor
    string valor, result;
    cout<<"Ingrese el valor que desea buscar: "<<endl;
    std::cin.ignore();
    std::getline(std::cin, valor);

    listavalue->binarySearchVector(valor);

    menuPrincipal();
}
/////////////////////////////////////////////////////////////////////////////////////
void salir(){ //Funcion para salir del programa
    cout<<"Gracias por usar el programa"<<endl;
    exit(0);
}
/////////////////////////////////////////////////////////////////////////////////////
void menuPrincipal(){ //Funcion para mostrar el menu principal

    int opcion;
    char entrada[100];

    cout << "1. Agregar un nuevo elemento" << endl;
    cout << "2. Buscar un elemento por nombre de la llave" << endl;
    cout << "3. Buscar por valor" << endl;
    cout << "4. Salir" << endl;

    cout << "Ingrese la opcion que desea consultar: ";
    cin >> entrada;
    if (strlen(entrada) > 1 || !isdigit(entrada[0])) {
        cout << "Entrada invalida. Por favor, ingrese un numero valido." << '\n';
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        menuPrincipal();
    }
    else {
        opcion = atoi(entrada);
        switch (opcion) {
            case 1:
                cargarDatos();
                break;
            case 2:
                buscarPorKey();
                break;
            case 3:
                buscarPorValor();
                break;
            case 4:
                salir();
                break;
            default:
                cout << "Opcion invalida. Por favor, elija una opcion valida (1-4)." << '\n';
                menuPrincipal();
                break;
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////
int main() {
    menuPrincipal();

    return 0;
}
