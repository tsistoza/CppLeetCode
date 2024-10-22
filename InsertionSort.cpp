#include <iostream>
#include <vector>

using std::cout, std::cin, std::endl;
using std::vector;

static vector<int> nums = {4, 2, 1, 3};
static vector<int> nums2 = {-1, 5, 3, 4, 0};


namespace Solution {
    class Node {
        public:
            int id;
            Node* next;
    
            Node (int val = (int) NULL) {
                this->id = val;
                this->next = NULL;
            }
    };

    class LinkedList {
        public:
            Node* head;

            void insertNode(Node* newNode);
            void readLinkedList();
            void ClearMem();
            LinkedList() {
                this->head = NULL;
            }
    };

    void LinkedList::insertNode(Node* newNode) {
        if (this->head == NULL) {
            this->head = newNode;
            return;
        }

        if (newNode->id < this->head->id) {
            newNode->next = this->head;
            this->head = newNode;
            return;
        }
        
        Node* prevNode = this->head;
        Node* nodePtr = this->head->next;
        for(; nodePtr!=NULL; nodePtr=nodePtr->next) {
            if (nodePtr->id > newNode->id) {
                prevNode->next = newNode;
                newNode->next = nodePtr;
                return;
            }
            prevNode = prevNode->next;
        }

        prevNode->next = newNode;
        return;
    }

    void LinkedList::readLinkedList() {
        cout << "Linked List: ";
        for (Node* nodePtr = this->head; nodePtr!=NULL; nodePtr=nodePtr->next)
            cout << nodePtr->id << " -> ";
        cout << "NULL" << endl;
        return;
    }

    void LinkedList::ClearMem() {
        Node* prevNode = this->head;
        for (Node* nodePtr = this->head->next; nodePtr!=NULL; nodePtr=nodePtr->next) {
            delete prevNode;
            prevNode = nodePtr;
        }
        delete prevNode;
        return;
    }
}

int main() {
    using namespace Solution;
    LinkedList* obj = new LinkedList();
    for(vector<int>::iterator it = nums.begin(); it!=nums.end(); it++)
        obj->insertNode(new Node(*it));
    obj->readLinkedList();
    obj->ClearMem();
    delete obj;
    obj = new LinkedList();
    for(vector<int>::iterator it = nums2.begin(); it!=nums2.end(); it++)
        obj->insertNode(new Node(*it));
    obj->readLinkedList();
    obj->ClearMem();
    delete obj;
    return 0;
}