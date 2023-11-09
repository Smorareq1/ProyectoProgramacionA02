#include <iostream>
#include <cstring>
#include <limits>

#include "myDoubleLinkedList.h"
#include "Hashear.h"

using namespace std;

void menuPrincipal();
myDoubleLinkedList *listahash = new myDoubleLinkedList();
myDoubleLinkedList *listavalue = new myDoubleLinkedList();
Hashear *hashear = new Hashear();

/////////////////////////////////////////////////////////////////////////////////////
void pruebas(){
    listavalue->sortColumns(2);
    cout<<listavalue->countColumns("key_p_1,A,47h67owu47,797xruek0e,key_p_28")<<endl;
    listavalue->printByValue();
}
/////////////////////////////////////////////////////////////////////////////////////
void cargarDatos(){

    string nombreArchivo;
    cout<<"Ingrese el nombre del archivo que desea cargar: "<<endl;
    std::cin.ignore();
    std::getline(std::cin, nombreArchivo);
    hashear->procesarArchivo(nombreArchivo, listahash, listavalue);
    listahash->sortList();

    cout<<listahash->sizeOfMyList()<<endl;
    cout<<listavalue->sizeOfMyList()<<endl;

    menuPrincipal();

}
/////////////////////////////////////////////////////////////////////////////////////
void buscarPorKey(){
    string key, result;
    cout<<"Ingrese la key que desea buscar: "<<endl;
    std::cin.ignore();
    std::getline(std::cin, key);

    result = hashear->hashKey(key);
    listahash->binarySearch(result);
    menuPrincipal();
}
/////////////////////////////////////////////////////////////////////////////////////
void buscarPorValor(){
    string valor, result;
    cout<<"Ingrese el valor que desea buscar: "<<endl;
    std::cin.ignore();
    std::getline(std::cin, valor);

    listavalue->binarySearchByColumn(1,valor);

    menuPrincipal();
}
/////////////////////////////////////////////////////////////////////////////////////
void salir(){
    cout<<"Gracias por usar el programa"<<endl;
    exit(0);
}
/////////////////////////////////////////////////////////////////////////////////////
void menuPrincipal(){

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
