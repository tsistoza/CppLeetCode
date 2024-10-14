#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stack>

using std::cout, std::cin, std::endl;
using std::vector, std::string, std::to_string;
using std::stoi, std::stack;

static vector<int> l1 = {2, 4, 3};
static vector<int> l2 = {5, 6, 4};

class Node {
    public:
        int id;
        Node* next;
    
    Node(int val) {
        this->id = val;
        this->next = NULL;
    }
};
class LinkedList {
    public:
        Node* head;

        LinkedList* generateLinkedList(vector<int>& list);
        void readLinkedList(LinkedList* list);
        LinkedList* addTwoNumbers(LinkedList* l1, LinkedList* l2);
        void createLinkedList(LinkedList* list, string& result);
        void ClearMem(LinkedList* list);

    LinkedList() {
        this->head = NULL;
    }
};

LinkedList* LinkedList::generateLinkedList(vector<int>& ln) {
    Node* nodePtr;
    LinkedList* list = new LinkedList();
    Node* newNode = new Node(*ln.begin());
    list->head = newNode;
    nodePtr = list->head;
    for (auto it = ln.begin()+1; it != ln.end(); it++) {
        newNode = new Node(*it);
        nodePtr->next = newNode;
        nodePtr = nodePtr->next;
    }
    return list;
}

void LinkedList::readLinkedList(LinkedList* list) {
    cout << "Linked List: ";
    for(Node* nodePtr = list->head; nodePtr != NULL; nodePtr=nodePtr->next)
        cout << nodePtr->id << " -> ";
    cout << "NULL" << endl;
    return;
}

LinkedList* LinkedList::addTwoNumbers(LinkedList* l1, LinkedList* l2) {
    LinkedList* list = new LinkedList();
    Node*  head;
    string number;
    string number2;
    for (Node* nodePtr = l1->head; nodePtr != NULL; nodePtr=nodePtr->next)
        number.insert(0, to_string(nodePtr->id));
    for (Node* nodePtr = l2->head; nodePtr != NULL; nodePtr=nodePtr->next)
        number2.insert(0, to_string(nodePtr->id));
    string result = to_string(stoi(number) + stoi(number2));
    createLinkedList(list, result);
    return list;
}

void LinkedList::createLinkedList(LinkedList* list, string& result) {
    stack<Node*> queue;
    for (int i=0; i<result.length(); i++) {
        int x = result[i] - '0';
        Node* newNode = new Node(x);
        queue.push(newNode);
    }
    Node* nodePtr;
    list->head = queue.top();
    nodePtr = list->head;
    queue.pop();
    while (!queue.empty()) {
        nodePtr->next = queue.top();
        queue.pop();
        nodePtr = nodePtr->next;
    }
    return;
}

void LinkedList::ClearMem(LinkedList* list) {
    Node* prevNode = list->head;
    for (Node* nodePtr=list->head->next; nodePtr != NULL; nodePtr=nodePtr->next) {
        delete prevNode;
        prevNode = nodePtr;
    }
    delete prevNode;
    delete list;
    return;
}

int main() {
    LinkedList list;
    LinkedList* list1;
    LinkedList* list2;
    LinkedList* result;
    list1 = list.generateLinkedList(l1);
    list2 = list.generateLinkedList(l2);
    result = list.addTwoNumbers(list1, list2);
    list.readLinkedList(result);
    list.ClearMem(list1);
    list.ClearMem(list2);
    list.ClearMem(result);
    return 0;
}