// LeetCode 190
#include <iostream>
#include <stack>

using std::cout, std::endl, std::stack;

static int n = 2147483644;

namespace Solution {
    class Program {
        public:
            int reverseBits(int n);
    };

    int Program::reverseBits(int n) {
        int num = n;
        int mask = 1;
        
        stack<bool> reverse;
        for (int i=0; i<32; i++) {
            reverse.push(num & mask);
            num >>= 1;
        }

        int reversedNumber = 0;
        int multiplier = 1;
        while (!reverse.empty()) {
            reversedNumber += (multiplier * reverse.top());
            reverse.pop();
            multiplier *= 2;
        }
        return reversedNumber;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.reverseBits(n) << endl;
    return 0;
}
