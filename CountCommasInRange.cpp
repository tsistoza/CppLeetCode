// LeetCode 3870
#include <iostream>

using std::cout, std::endl;

static int n = 100000;

namespace Solution {
    class Program {
        public:
            int countCommas(int n);
    };

    int Program::countCommas(int n) {
        if (n < 1000) return 0;
        return n - 999;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.countCommas(n) << endl;
    return 0;
}