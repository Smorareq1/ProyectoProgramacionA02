#include <iostream>



#include "myDoubleLinkedList.h"

using namespace std;

int main() {
    myDoubleLinkedList list;
    list.addSorted("1234");
    list.addSorted("1111");
    list.addSorted("12356");
    list.print();
    cout<<list.sizeOfMyList()<<endl;

    cout<<"Ingrese el dato que quiere buscar: ";
    string dato;
    cin>>dato;
    list.binarySearch(dato);
    return 0;
}
