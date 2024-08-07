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
            if(!head){
                std::cout << "Empty List" << std::endl;
                return;
            }
            // or Node* temp = tail; declare first, *** temp = TAIL***
            Node* temp = tail;
            if(!head->next){
                // delete head;
                // delete tail;
                head = nullptr;
                tail = nullptr;
            } else{
                // Node* temp = tail;
                tail = tail->prev;
                tail->next = nullptr;
                // delete temp;
            }
            delete temp;
            length--;
        }

        void prepend(int value){
            Node* newNode = new Node(value);
            if(!head){
                head = newNode;
                tail = newNode;
            } else{
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            length++;
        }

        void deleteFirst(){
            if(!head) return;

            Node* temp = head;
            if(!head->next){
                head = nullptr;
                tail = nullptr;
            } else{
                head = head->next;
                head->prev = nullptr;
            }
            length--;
            delete temp;
        }

};

int main(){
    DoublyLinkedList* myDLL = new DoublyLinkedList(7);
    myDLL->append(2);

    myDLL->prepend(5);

    std::cout<<"DLL before deleteFirst(): \n";
    myDLL->printList();

    myDLL->deleteFirst();
    std::cout<<"DLL 1st deleteFirst(): \n";
    myDLL->printList();

    myDLL->deleteFirst();
    std::cout<<"DLL 2nd deleteFirst(): \n";
    myDLL->printList();

    myDLL->deleteFirst();
    std::cout<<"DLL 3rd deleteFirst(): \n";
    myDLL->printList();

    myDLL->deleteFirst();
    std::cout<<"DLL 4th deleteFirst(): \n";
    myDLL->printList();

}