// LeetCode 2429
#include <iostream>
#include <vector>
#include <cmath>

using std::cout, std::endl;
using std::vector, std::log2;

static int num1 = 3;
static int num2 = 5;
static int num1a = 1;
static int num2a = 12;
static int num1b = 7;
static int num2b = 1;

namespace Solution {
    class Program {
        private:
            vector<int> toBinary(int num);
            unsigned int toInteger(vector<int> bitset);
            unsigned int numSetBits(int num2);
            unsigned int countBits(int num);
        public:
            int minimizeXor(int num1, int num2);
    };

    vector<int> Program::toBinary(int num) {
        vector<int> bitset;

        for (int i=countBits(num)-1; i>=0; i--) {
            int bit = (num >> i) & 1;
            bitset.push_back(bit);
        }
        return bitset;
    }

    unsigned int Program::toInteger(vector<int> bitset) {
        unsigned int count = 0;
        int multiplicand = 1;
        for (vector<int>::reverse_iterator itr = bitset.rbegin(); itr!=bitset.rend(); itr++) {
            count += (*itr) * multiplicand;
            multiplicand *= 2;
        }
        return count;
    }

    unsigned int Program::numSetBits(int num2) {
        unsigned int count = 0;
        while(num2 > 0) {
            count += num2 & 1;
            num2 = num2 >> 1;
        }
        return count;
    }

    unsigned int Program::countBits(int num) {
        return (int)log2(num)+1;
    }

    int Program::minimizeXor(int num1, int num2) {
        int setBits = numSetBits(num2);
        vector<int> num1bits = toBinary(num1);
        int maxBits = (num1bits.size() < setBits) ? setBits : num1bits.size();
        if (maxBits == setBits) {
            int x = toInteger(vector<int>(setBits, 1));
            return x;
        }

        vector<int> xBits(maxBits, 0);
        for (int i=0; i<num1bits.size(); i++) {
            if (num1bits[i] == 1 && setBits > 0) {
                xBits[i] = 1;
                setBits--;
            }
        }


        int x = toInteger(xBits);
        return x;
    }
};

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.minimizeXor(num1, num2) << endl;
    cout << obj.minimizeXor(num1a, num2a) << endl;
    cout << obj.minimizeXor(num1b, num2b) << endl;
    return 0;
}