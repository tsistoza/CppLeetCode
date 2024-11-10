// LeetCode 201
#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

using std::cout, std::endl;
using std::vector, std::pair, std::make_pair;

namespace Solution {
    class Program {
        public:
            int rangeBitwiseAnd(int left, int right);
    };

    int Program::rangeBitwiseAnd(int left, int right) {
        if (left == 0) return 0;
        vector<pair<int,int>> prefix;

        int sum=0;
        int shiftleft = left;
        int shiftright = right;
        int numBits = (int)log2(right) + 1;

        // Find the common prefix between the two bits
        for(int i=0; i<numBits; i++) {
            if ((shiftleft & 1) == (shiftright & 1)) prefix.push_back(make_pair(shiftleft&1, i)); // push a pair, with its bit pos, and bit
            else prefix.clear();
            shiftleft >>= 1;
            shiftright >>= 1;
        }

        for(vector<pair<int,int>>::iterator it=prefix.begin(); it!=prefix.end(); it++) // and then just calculate the sum of the bit
            sum += it->first * pow(2, it->second);
        return sum;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.rangeBitwiseAnd(5, 7) << endl;
    cout << obj.rangeBitwiseAnd(0, 0) << endl;
    cout << obj.rangeBitwiseAnd(1, INT_MAX) << endl;
    return 0;
}