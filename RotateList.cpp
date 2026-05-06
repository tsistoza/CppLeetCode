// LeetCode 61
#include <iostream>
#include <vector>
#include <queue>

using std::cout, std::endl;

static std::vector<int> arr { 0, 1, 2 };
static int k = 4;

namespace Solution {
    class ListNode {
        public:
            int val;
            ListNode* next;
            
            ListNode() : val(0), next(NULL) {}
            ListNode(int _x) : val(_x), next(NULL) {}
            ListNode(int _x, ListNode* _next) : val(_x), next(_next) {}
    };

    class ListGroup {
        public:
            ListNode* head;
            ListNode* back;
            size_t size;

            ListGroup() : head(NULL), size(0) {}
            ~ListGroup();

            void createListWithArray(std::vector<int>& arr);
    };

    class Program {
        private:
            size_t getSizeOfList(ListNode* head);
            void getBackOfListAndPrev(ListNode* head, ListNode*& back, ListNode*& prev);
            void prettyPrintList(ListNode* head);
        public:
            ListNode* rotateRight(ListNode* head, int k);
    };

    ListGroup::~ListGroup() {
        if (size == 0) return;
        std::queue<ListNode*> bfsQ;
        bfsQ.push(head);
        
        while (!bfsQ.empty()) {
            ListNode* currNode = bfsQ.front();
            bfsQ.pop();
            

            if (currNode->next == NULL) {
                delete currNode;
                continue;
            }
            delete currNode;
            bfsQ.push(currNode->next);
        }
    }

    void ListGroup::createListWithArray(std::vector<int>& arr) {
        head = new ListNode(arr[0]);
        ListNode* currNode = head;
        for (int i=1; i<arr.size(); i++) {
            ListNode* newNode = new ListNode(arr[i]);
            currNode->next = newNode;
            currNode = currNode->next;
        }

        size = arr.size();
        back = currNode;
        return;
    }

    size_t Program::getSizeOfList(ListNode* head) {
        std::queue<ListNode*> bfsQ;
        if (head == NULL) return 0;
        size_t size = 0;
        bfsQ.push(head);
        while (!bfsQ.empty()) {
            ListNode* currNode = bfsQ.front();
            bfsQ.pop();
            size++;

            if (currNode->next == NULL) continue;
            bfsQ.push(currNode->next);
        }

        return size;
    }

    void Program::getBackOfListAndPrev(ListNode* head, ListNode*& back, ListNode*& prev) {
        std::queue<ListNode*> bfsQ;
        if (head == NULL) {
            back = NULL;
            return;
        }

        bfsQ.push(head);
        while (!bfsQ.empty()) {
            ListNode* currNode = bfsQ.front();
            back = currNode;
            bfsQ.pop();

            if (currNode->next == NULL) continue;
            bfsQ.push(currNode->next);
            prev = currNode;
        }

        return;
    }

    void Program::prettyPrintList(ListNode* head) {
        cout << "Curr List: --> ";
        std::queue<ListNode*> bfsQ;
        bfsQ.push(head);
        while (!bfsQ.empty()) {
            ListNode* currNode = bfsQ.front();
            cout << currNode->val << " --> ";
            bfsQ.pop();

            if (currNode->next == NULL) continue;
            bfsQ.push(currNode->next);
        }
        cout << "NULL\n\n" << endl;
        return;
    }

    ListNode* Program::rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        int numRots = k % getSizeOfList(head);
        
        while (numRots > 0) {
            ListNode* back;
            ListNode* prev;
            getBackOfListAndPrev(head, back, prev);

            back->next = head;
            head = back;
            prev->next = NULL;
            back = prev;
            numRots--;
            prettyPrintList(head);
        }

        return head;
    }
}

int main() {
    using namespace Solution;
    ListGroup* list = new ListGroup();
    list->createListWithArray(arr);

    Program obj;
    obj.rotateRight(list->head, k);

    delete list;
    return 0;
}