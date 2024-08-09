#include <iostream>

class Node{
    public:
        int value;
        Node* next;

        Node(int value){
            this->value = value;
            next = nullptr;
        }

};

class Stack{
    private: 
        Node* top;
        // Node* tail; since stack only adding or removing from top, so we don't need this
        int height;

    public:
        Stack(int value){
            Node* newNode = new Node(value);
            top = newNode;
            height = 1;
        }

        void printStack(){
            Node* temp = top;
            std::cout << "Stack is: [ ";
            while(temp){
                std::cout << temp->value << " ";
                temp = temp->next;
            }
            std::cout << "]" << std::endl;
        }

        void getTop(){
            std::cout << "Top is: " << top->value << std::endl;
        }

        void getHeight(){
            std::cout << "Height is: " << height << std::endl;
        }

};

int main(){
    Stack* myStack = new Stack(4);
    myStack->getTop();
    myStack->getHeight();
    myStack->printStack();

    delete myStack;
}

