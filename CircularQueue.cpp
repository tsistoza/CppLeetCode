#include <iostream>

using std::cout,std::cin,std::endl;

namespace Solution {
    
    class Node{
        public:
            int id;
            Node* next;

        Node (int value) {
            this->id = value;
            this->next = NULL;
        }
    };

    class MyCircularQueue {
        public:
            Node* front;
            Node* rear;
            int maxSizeOfQueue;
            int sizeofQueue;

            bool enQueue(int value);
            bool deQueue();
            int Front();
            int Rear();
            bool isEmpty();
            bool isFull();
            void readQueue();

            MyCircularQueue (int k) {
                this->front = NULL;
                this->rear = NULL;
                this->maxSizeOfQueue = k;
                this->sizeofQueue = 0;
            }
    };

    bool MyCircularQueue::enQueue(int value) {
                Node* newNode = new Node(value);
                Node* nodePtr;
                if (this->sizeofQueue == 0 && this->front == NULL) // init queue
                {
                    this->front = newNode;
                    this->rear = newNode;
                    this->rear->next = this->front;
                    this->sizeofQueue++;
                    return true;
                } else if (this->sizeofQueue > 0 && this->sizeofQueue < maxSizeOfQueue) { // there is already a node in queue
                    this->rear->next = newNode;
                    this->rear = this->rear->next;
                    this->rear->next = this->front;
                    this->sizeofQueue++;
                    return true;
                }
                // no space in the queue free node and return false
                delete newNode;
                return false;
    }

    bool MyCircularQueue::deQueue() {
        Node* nodePtr = this->front;
        this->front = this->front->next;
        this->rear->next = this->front;
        delete nodePtr;
        this->sizeofQueue--;
        return false;
    }

    int MyCircularQueue::Front() {
        return this->front->id;
    }

    int MyCircularQueue::Rear() {
        return this->rear->id;
    }

    bool MyCircularQueue::isEmpty() {
        return (this->sizeofQueue == 0) ? true : false;
    }

    bool MyCircularQueue::isFull() {
        return (this->sizeofQueue == maxSizeOfQueue) ? true : false;
    }

    void MyCircularQueue::readQueue() {
        cout << "Circle Queue: ";
        if (this->front != NULL)
            for(Node* nodePtr = this->front; nodePtr != NULL; nodePtr=nodePtr->next)
                cout << nodePtr->id << " -> ";
        return;
    }
}

int main() {
    using namespace Solution;
    MyCircularQueue* queue =  new MyCircularQueue(3);
    queue->enQueue(1);
    queue->enQueue(2);
    queue->enQueue(3);
    queue->enQueue(4);
    //queue->readQueue();
    cout << queue->Rear() << endl;
    cout << queue->isFull() << endl;
    cout << queue->isEmpty() << endl;
    queue->deQueue();
    queue->enQueue(4);
    cout << queue->Rear() << endl;
    //queue->readQueue();
    delete queue;
    return 0;
}