// LeetCode 2145
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector;
using std::min, std::max;

static vector<int> differences { 1, -3, 4 };
static int lower = 1;
static int upper = 6;

namespace Solution {
    class Program {
        public:
            int numberOfArrays(vector<int>& differences, int lower, int upper);
    };

    int Program::numberOfArrays(vector<int>& differences, int lower, int upper) {
        int x=0, minVal=0, maxVal=0;
        for (int i=0; i<differences.size(); i++) {
            x = differences[i] + x;
            minVal = min(x, minVal);
            maxVal = max(x, maxVal);
            if (maxVal-minVal > upper-lower) return 0;
        }
        return (upper-lower + 1) - (maxVal-minVal);
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.numberOfArrays(differences, lower, upper) << endl;
}