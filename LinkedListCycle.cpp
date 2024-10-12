#include <iostream>
#include <vector>
#include <iterator>

using std::cout,std::cin,std::endl;
using std::vector,std::iterator;

int cycleIndex = 2;
static vector<int> cycleList = {3, 2, 0, -4};

namespace Solution {
    class Node{
        public:
            int id;
            Node* next;
        
        Node(int value) {
            this->id = value;
            this->next = NULL;
        }
    };

    class LinkedList {
        public:
            Node* head;
            vector<int> checkList;

            bool hasCycle(Node* head);
            Node* generateLinkedList();
            void readLinkedList(Node* head);
            bool checkInList(int value);

        LinkedList() {
            this->head = NULL;
        }
    };

    bool LinkedList::hasCycle(Node* head){
        if (head != NULL) this->checkList.push_back(head->id);
        for (Node* nodePtr=head; nodePtr!=NULL; nodePtr=nodePtr->next)
            if (checkInList(nodePtr->id)) return true;
        return false;
    }

    Node* LinkedList::generateLinkedList() {
        Node* nodePtr;
        Node* cycleNode;
        Node* newNode = new Node(*cycleList.begin());
        LinkedList* list = new LinkedList();
        list->head = newNode;
        nodePtr = newNode;
        for (auto it = cycleList.begin()+1 ; it != cycleList.end() ; it++) {
            newNode = new Node(*it);
            if (*it == 2) cycleNode = newNode;
            nodePtr->next = newNode;
            nodePtr = nodePtr->next;
        }
        nodePtr->next = cycleNode;
        return list->head;
    }

    void LinkedList::readLinkedList(Node* head) {
        cout << "LinkedList: ";
        for (Node* nodePtr = head; nodePtr != NULL; nodePtr=nodePtr->next) {
            cout << nodePtr->id << " -> ";
        }
        cout << "NULL" << endl;
        return;
    }

    bool LinkedList::checkInList(int value) {
        for (auto it = this->checkList.begin(); it != this->checkList.end(); it++) {
            if (*it == value) return true;
            else {
                this->checkList.push_back(value);
                break;
            }
        }
        return false;
    }
}

int main() {
    using namespace Solution;
    LinkedList obj;
    Node* head = obj.generateLinkedList();
    cout << obj.hasCycle(head) << endl;
    return 0;
}