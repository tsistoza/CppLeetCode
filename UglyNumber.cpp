// LeetCode 263
#include <iostream>
#include <ios>
#include <vector>
#include <cmath>

using std::cout, std::endl, std::vector;
using std::boolalpha, std::sqrt;

static int n = 21;

namespace Solution {
    class Program {
        private:
            bool isPrime(int n);
        public:
            bool isUgly(int n);
    };

    bool Program::isPrime(int n) {
        if (n <= 1) return false;

        for (int i=2; i<=sqrt(n); i++)
            if (n%i==0) return false;
        return true;
    }

    bool Program::isUgly(int n) {
        vector<int> divisor { 2, 3, 5 };
        int factor = n;
        if (factor == 1) return true;

        while (!isPrime(factor)) {
            for (int i=0; i<divisor.size(); i++) {
                if (factor % divisor[i] == 0) {
                    factor /= divisor[i];
                    break;
                }
            }
        }

        return (factor == 2) || (factor == 3) || (factor == 5);
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << boolalpha << obj.isUgly(n) << endl;
    return 0;
}