#include <iostream>



#include "myDoubleLinkedList.h"

using namespace std;

int main() {
    myDoubleLinkedList list;
    list.addSorted("AAA");
    list.addSorted("AAA");
    list.addSorted("123");
    list.print();
    cout<<list.sizeOfMyList()<<endl;

    cout<<"Ingrese el dato que quiere buscar: ";
    string dato;
    cin>>dato;
    list.binarySearch(dato);

    return 0;
}
