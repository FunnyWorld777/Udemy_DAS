#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"
using namespace std;


int main(){
    LinkedList* myList = new LinkedList(4);
    myList->printList();
    delete myList;
    cout<<":"<<endl;
    return 0;
}