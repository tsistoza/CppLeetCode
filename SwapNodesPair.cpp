#include <iostream>
#include <vector>

using std::cout,std::cin,std::endl;

namespace solution{

    class Node{
            public:
                int value;
                Node* next;

                Node(int data){
                    this->value = data;
                    this->next = NULL;
                }
    }; //Node

    class LinkedList
    {
        public:
            solution::Node* head;

            LinkedList(){
                this->head = NULL;
            } //LinkedList Constructor

            void InsertNode(int value){
                //cout << "CREATING A NEW NODE" << endl;
                solution::Node* newNode = new solution::Node(value); //SIMILAR TO MALLOC IN C

                if(head == NULL){
                    head = newNode;
                    return;
                }
                
                solution::Node* temp = this->head;
                while(temp->next != NULL){
                    //Iterate over the solution till you reach the end
                    temp=temp->next;
                }
                temp->next = newNode; //Set next to the next node
                return;
            } //InsertNode()
            
            void ClearList(){
                cout << "CLEARING LIST" << endl;
                solution::Node* prev = this->head;
                solution::Node* curr = prev->next;
                while(curr->next != NULL) {
                    delete prev;
                    prev = curr;
                    curr = curr->next;
                }
                delete curr;
                this->head = NULL;
                return;
            }

            void PrintList(){
                if(head == NULL){
                    cout << "LIST IS EMPTY" << endl;
                    return;
                }
                cout << "THE LIST GOES AS: " << endl;
                for(solution::Node* temp = this->head ; temp != NULL ; temp=temp->next){
                    cout << " " << temp->value;
                }
                cout << endl;
                return;
            } //PrintList()

            void SwapPair(){
                cout << "STARTING SWAP PAIRS" << endl;
                int swap=2;
                int currVal;
                int nextVal;
                Node* prev = this->head;
                if(head->next == NULL){
                    cout << "LIST IS TOO SMALL TO SWAP PAIRS" << endl;
                    return;
                }
                for (Node* curr = this->head ; curr != NULL ; curr = curr->next){
                    if (swap % 2 == 0 && curr->next != NULL){
                        currVal = curr->value;
                        nextVal = curr->next->value;
                    }
                    else if ( swap%2==1 ){
                        //cout << "SWAP PAIRS" << endl;
                        curr->value = currVal;
                        prev->value = nextVal;
                    }
                    swap++;
                    prev = curr;
                }
            } // SwapPair()

    };//class

} //namespace

int main(){
    
    solution::LinkedList list1;

    for(int i=0 ; i<10 ; i++)
        list1.InsertNode(i);
    list1.PrintList();
    list1.SwapPair();
    list1.PrintList();
    list1.ClearList();

    if(list1.head == NULL)
        cout << "LIST IS EMPTIED";
    return 0;
}