// LeetCode 1922
#include <iostream>
#include <string>
#include <cmath>

using std::cout, std::endl;
using std::pow;

static long long n = 1;

namespace Solution {
    class Program{
        private:
            long long modExp(long long base, long long exp, long long mod);
        public:
            int countGoodNumbers(long long n);
    };

    long long Program::modExp(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp&1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }

        return result;
    }

    int Program::countGoodNumbers(long long n) {
        int kMod = 1000000007;
        return (modExp(5, (n+1)/2, kMod) * modExp(4, n/2, kMod)) % kMod;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.countGoodNumbers(n) << endl;
}