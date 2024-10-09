#include <iostream>
#include <stack>

using std::cout,std::endl;
using std::stack;

int numNodes = 5;

namespace Solution {
    class Node {
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
            void reverseLinkedList(LinkedList* list);
            LinkedList* GenerateLinkedList();
            void readList(LinkedList* list);

            LinkedList() {
                this->head = NULL;
            }
    };

    void LinkedList::reverseLinkedList(LinkedList* list) {
        Node* current;
        LinkedList* reversedList = new LinkedList();
        stack<Node*> reverseNode;
        for (Node* nodePtr=list->head ; nodePtr != NULL ; nodePtr=nodePtr->next) reverseNode.push(nodePtr);
        reversedList->head = reverseNode.top();
        current = reversedList->head;
        reverseNode.pop();
        while(!reverseNode.empty()) {
            current->next = reverseNode.top();
            current=current->next;
            reverseNode.pop();
        }
        current->next = NULL;
        readList(reversedList);
        delete list;
        delete reversedList;
        return;
    }

    LinkedList* LinkedList::GenerateLinkedList() {
        int i=2;
        LinkedList* list = new LinkedList();
        Node* newNode = new Node(1);
        list->head = newNode;
        Node* nodePtr = list->head;
        do {
            newNode = new Node(i);
            nodePtr->next = newNode;
            nodePtr=nodePtr->next;
            i++;
        } while(i <= numNodes);
        return list;
    }

    void LinkedList::readList(LinkedList* list) {
        cout << "Linked List: ";
        for (Node* node=list->head ; node != NULL ; node=node->next) {
            cout << node->id << " -> ";
        }
        cout << "null" << endl;
    }
}

int main() {
    using namespace Solution;
    LinkedList object;
    LinkedList* list = object.GenerateLinkedList();
    object.readList(list);
    object.reverseLinkedList(list);
    return 0;
}