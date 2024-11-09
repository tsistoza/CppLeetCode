#include <iostream>
#include <vector>
#include <cmath>

using std::cout, std::endl;
using std::vector;

static const int n = 3;
static const int x = 4;

namespace Solution {
    class Program {
        public:
            long long minEnd(int n, int x);
    };

    long long Program::minEnd(int n, int x) {
        vector<int> nums = { x };
        long result = x;
        long remaining = n - 1;
        long position = 1;

        while (remaining) {
            if (!(x & position)) {
                result |= (remaining & 1) * position;
                remaining >>= 1;
                nums.push_back(result);
            }
            position <<=1;
        }
        return nums.back();
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.minEnd(n, x) << endl;
    return 0;
}