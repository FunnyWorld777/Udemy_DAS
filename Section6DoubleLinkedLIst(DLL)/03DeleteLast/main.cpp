#include <iostream>

class Node{
    public:
        int value;
        Node* next;
        Node* prev;

        Node(int value){
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:
        DoublyLinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        void printList(){
            Node* temp = head;
            std::cout << "Doubly Linked List: [ ";
            while(temp){
                std::cout << temp->value << " ";
                temp = temp->next;
            }
            std::cout << "]" << std::endl;
        }

        void getHead(){
            std::cout << "Head: " << head->value << std::endl;
        }

        void getTail(){
            std::cout << "Tail: " << tail->value << std::endl;
        }

        void getLength(){
            std::cout << "Length: " << length << std::endl;
        }

        void append(int value){
            Node* newNode = new Node(value);
            if(!head) {
                head = newNode;
                tail = newNode;
            } else{
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }

        void deleteLast(){
            if(!head) return;
            
            if(!head->next){
                delete head;
                delete tail;
                head = nullptr;
                tail = nullptr;
            } else{
                Node* temp = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete temp;
            }
            length--;
        }

};

int main(){
    DoublyLinkedList* myDLL = new DoublyLinkedList(7);
    myDLL->printList();
    myDLL->getLength();

    myDLL->append(2);
    myDLL->printList();
    myDLL->getLength();

    myDLL->append(99);
    myDLL->printList();
    myDLL->getLength();

}