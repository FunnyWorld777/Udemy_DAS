#include <iostream>
#include "LinkedList.h"

void LinkedList::printList() const{
    Node* temp = head;
    if(!temp){
        std::cout << "The Linked List is empty!" << std::endl;
    } else{
        std::cout << "The Linked List Node Values: [ ";
        while(temp){
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << "]" << std::endl;
    }
}
