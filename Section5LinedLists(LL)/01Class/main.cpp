#include <iostream>
// #include "LinkedList.h"

using namespace std;

class Node{
    public:
        int value;
        Node* next;

        Node(int value) : value(value), next(nullptr){
        }
};

class LinkedList
{
    Node* head;
    Node* tail;
    int length;
public:
    LinkedList(int value){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList(){
        Node* temp = head;
        while(head!=nullptr){
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList() const{
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

    //getters
    Node* getHead(){
        std::cout << "Head is: " << head->value << std::endl;
        return head;};

    Node* getTail(){
        std::cout << "Tail is: " << tail->value << std::endl;
        return tail;};

    int getLength(){
        std::cout << "List length is: " << length << std::endl;
        return length;};
};


int main(){
    LinkedList* myList = new LinkedList(4);
    myList->printList();
    delete myList;
    cout<<":"<<endl;
    return 0;
}