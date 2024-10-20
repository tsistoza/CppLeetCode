#include <iostream>

using std::cout,std::cin,std::endl;

static const int MAX = 10;

namespace Solution {
    
    class MinStack {
        private:
            void popMin();
        public:
            int a[MAX];
            int index;
            int min;
            void push(int val);
            void pop();
            int top();
            int getMin();

            MinStack () {
                this->index = 0;
            }
    };

    void MinStack::popMin() {
        if (this->index != 0) {
            this->min = a[this->index-1];
            for(int index=this->index-1; index>0; index--)
                if (this->min > a[index]) this->min = a[index];
        }
        return;
    }

    void MinStack::push(int val) {
        if(this->index==0) this->min = val;
        if(this->min > val) this->min = val;
        this->index++;
        a[this->index] = val;
        return;
    }

    void MinStack::pop() {
        cout << "Popping " << a[this->index] << " off the stack" << endl;
        if(a[this->index] == this->min) popMin();
        a[this->index] = (int) NULL;
        this->index--;
        return;
    }

    int MinStack::top() {
        return a[this->index];
    }

    int MinStack::getMin() {
        return this->min;
    }
}

int main() {
    using namespace Solution;
    MinStack* stack = new MinStack();
    stack->push(-2);
    stack->push(0);
    stack->push(-3);
    cout << "Minimum number is: " << stack->getMin() << endl;
    stack->pop();
    cout << "Top of Stack is: " << stack->top() << endl;
    cout << "Minimum number is: " << stack->getMin() << endl;
    delete stack;
    return 0;
}