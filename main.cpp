#include <iostream>



#include "myDoubleLinkedList.h"

using namespace std;

int main() {
    myDoubleLinkedList list;
    for(int i  = 0; i < 10; i++){
        list.addSorted(to_string(i));
    }
    list.print();
    cout<<list.sizeOfMyList()<<endl;

    cout<<"Ingrese el dato que quiere buscar: ";
    string dato;
    cin>>dato;
    list.binarySearch(dato);

    return 0;
}
