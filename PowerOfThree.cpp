// LeetCode 326
#include <iostream>
#include <cmath>
#include <ios>

using std::cout, std::endl, std::log;
using std::boolalpha;

static int n = -1;

namespace Solution {
    class Program {
        public:
            bool isPowerOfThree(int n);
    };

    bool Program::isPowerOfThree(int n) {
        float ans = log(n) / log(3);
        return (ans*ans*ans) == (float)n;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << boolalpha << obj.isPowerOfThree(n) << endl;
}