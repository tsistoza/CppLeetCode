// LeetCode 3754
#include <iostream>
#include <vector>
#include <cmath>

using std::cout, std::endl;

static int n = 1000000000;

namespace Solution {
    class Program {
        public:
            long long sumAndMultiply(int n);
    };

    long long Program::sumAndMultiply(int n) {
        long long sum = 0;
        long long x = 0;

        int cnt=1;
        while (n > 0) {
            int remainder = n%10;
            if (remainder > 0) {
                x += (cnt * remainder);
                cnt *= 10;
            }
            sum += remainder;
            n -= remainder;
            n /= 10;
        }

        return x * sum;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.sumAndMultiply(n) << endl;
    return 0;
}
