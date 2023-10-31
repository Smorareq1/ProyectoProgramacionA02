#include <iostream>



#include "myDoubleLinkedList.h"

using namespace std;

int main() {
    myDoubleLinkedList list;
    list.addSorted("ABC");
    list.addSorted("AAB");
    list.addSorted("AAA");
    list.print();
    cout<<list.sizeOfMyList()<<endl;
    return 0;
}
