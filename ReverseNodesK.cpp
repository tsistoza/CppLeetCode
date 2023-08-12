#include <iostream>
#include <stack>

using std::cout,std::cin,std::endl;
using std::stack;

namespace solution
{
    class Node{
        public:
            int value;
            Node* next;

            //CONSTRUCTOR FUNCTION
            Node(int value){
                this->value = value;
                this->next = NULL;
            }
    };

    class LinkedList{
        public:
            Node* head;

            //CONSTRUCTOR FUNCTION
            LinkedList(){
                this->head = NULL;
            }

            void createList(int size);
            void printList(Node* head);
            void deleteList(Node* head);
            void ReverseNodes(int reverseIndex,int sizeOfList);
    };

    void LinkedList::createList(int size){
        Node* newNode = new Node(0);
        this->head = newNode;
        Node* current = this->head;
        int value = 1;
        
        do{
            newNode = new Node(value);
            current->next = newNode;
            current = newNode;
            value++;
        }while(value<size);
        printList(this->head);
        return;
    }

    void LinkedList::printList(Node* head){
        cout << "Current List Goes As: " << endl;
        for(Node* curr = head ; curr != NULL ; curr=curr->next){
            cout << curr->value << " -> ";
        }
        cout << "NULL" << endl;
        return;
    }

    void LinkedList::deleteList(Node* head){
        Node* curr = head;
        Node* nextNode = curr->next;
        
        do{
            delete curr;
            curr = nextNode;
            nextNode = nextNode->next;
        }while(nextNode != NULL);

        delete curr;
        head = NULL;
        return;
    }

    //IDEA IS TO USE STACKS TO CREATE A NEW LINKEDLIST.
    void LinkedList::ReverseNodes(int k,int sizeofList){
        //FIND ALL THE GROUPS
        int kcut=k;
        int size = sizeofList;
        int groups=0;
        while (size > -1){
            if(kcut == 0){
                groups++;
                kcut = k;
            }
            size--;
            kcut--;
        }


        Node* curr = this->head;
        Node* temp = NULL;

        if(k > sizeofList){
            cout << "K-Group is larger then the size of Linked List\n";
            return;
        }

        stack<Node*> Reverse; //WE CAN GROUP THEM USING STACKS
        int index = 1;
        while( curr != NULL ) {
            Reverse.push(curr);
            if(groups > 0 && index == k && temp == NULL){ //SAVE THE HEAD OF THE LIST
                this->head = Reverse.top();
                Reverse.pop();
                temp = this->head;
            }

            curr=curr->next;

            if( groups > 0 && index == k ){  // REVERSE INTO GROUP

                while( !Reverse.empty() ){
                    Node* newNode = Reverse.top();
                    temp->next = newNode;
                    temp = newNode;
                    
                    Reverse.pop();
                }
                temp->next = NULL;
                groups--;
                index = 0;
            }
            else if (groups == 0){ //DO NOT REVERSE THE REST
                Node* newNode = Reverse.top();
                temp->next = newNode;
                temp = newNode;
                newNode->next = NULL;
                Reverse.pop();
            }
            index++;
        }

        printList(this->head);
        deleteList(this->head);

        return;
    }

}

int main() {
    int reverseIndex = 7;
    int sizeOfList = 8;
    solution::LinkedList list;
    list.createList(sizeOfList);
    list.ReverseNodes(reverseIndex,sizeOfList);
    return 0;
}