#include <iostream>
#include <string>
#include <vector>

using std::cout, std::cin, std::endl;
using std::to_string, std::string, std::vector;

static vector<int> binary = {1, 1, 1};

/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.
*/

class Node {
    public:
        int id;
        Node* next;

        Node (int val) {
            this->id = val;
            this->next = NULL;
        }

        Node () {
            this->id = -1;
            this->next = NULL;
        }

        int getDecimalValue(Node* head);
        Node* createLinkedList();
        void readLinkedList(Node* head);
        void destroyLinkedList(Node* head);
};

int Node::getDecimalValue(Node* head) {
    int sum = 0;
    int multiplicand = 1;
    for (Node* nodePtr = head; nodePtr!=NULL; nodePtr=nodePtr->next) {
        sum+=(multiplicand*nodePtr->id);
        multiplicand*=2;
    }
    return sum;
}

Node* Node::createLinkedList() {
    Node* newNode;
    Node* head = new Node(*binary.begin());
    Node* nodePtr = head;
    for (vector<int>::iterator it = binary.begin()+1; it!=binary.end(); it++) {
        newNode = new Node(*it);
        nodePtr->next = newNode;
        nodePtr = nodePtr->next;
    }
    return head;
}

void Node::readLinkedList(Node* head) {
    cout << "Linked List: ";
    for (Node* nodePtr = head; nodePtr!=NULL; nodePtr=nodePtr->next) 
        cout << nodePtr->id << " -> ";
    cout << "NULL" << endl;
}

void Node::destroyLinkedList(Node* head) {
    Node* prevNode = head;
    for (Node* nodePtr = head->next; nodePtr != NULL; nodePtr=nodePtr->next) {
        delete prevNode;
        prevNode = nodePtr;
    }
    return;
}


int main() {
    Node object;
    Node* head = object.createLinkedList();
    object.readLinkedList(head);
    cout << object.getDecimalValue(head) << endl;
    object.destroyLinkedList(head);
    return 0;
}
