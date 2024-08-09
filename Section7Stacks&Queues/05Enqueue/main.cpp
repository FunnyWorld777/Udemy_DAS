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

class Queue{
    private:
        Node* first;
        Node* last;
        int length;
    
    public:
        Queue(int value){
            Node* newNode = new Node(value);
            first = newNode;
            last = newNode;
            length = 1;
        }

        void printQueue(){
            std::cout << "The queue is: [ ";
            Node* temp = first;
            while(temp){
                std::cout << temp->value << " ";
                temp = temp->next;
            }
            std::cout << "]" << std::endl;
        }

        void getFirst(){
            std::cout << "First is: " << first->value << std::endl;
        }

        void getLast(){
            std::cout << "Last is: " << last->value << std::endl;
        }

        void getLength(){
            std::cout << "Length is: " << length << std::endl;
        }

        void enqueue(int value){
            Node* newNode = new Node(value);
            if(!first){
                first = newNode;
                last = newNode;
            } else{
                last->next = newNode;
                last = newNode;
            }
            length++;
        }

        int dequeue(){
            if(!first) return INT_MIN;

            int dequeueValue = first->value;
            Node* temp = first;
            if(!first->next){
                first = nullptr;
                last = nullptr;
            } else{
                first = first->next;
            } 
            delete temp;
            length--;
            return dequeueValue;
        }

};

int main(){
    Queue* myQueue = new Queue(5);
    myQueue->enqueue(6);
    myQueue->enqueue(7);

    myQueue->printQueue();

    std::cout << "Dequeue value: " << myQueue->dequeue() << std::endl;
    std::cout << "Dequeue value: " << myQueue->dequeue() << std::endl;
    std::cout << "Dequeue value: " << myQueue->dequeue() << std::endl;
    std::cout << "Dequeue value: " << myQueue->dequeue() << std::endl;

    delete myQueue;
}