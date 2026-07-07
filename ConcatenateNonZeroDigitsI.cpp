// LeetCode 3754
#include <iostream>
#include <vector>
#include <cmath>

using std::cout, std::endl;

static int n = 1000;

namespace Solution {
    class Program {
        private:
            int findNumDigits(int n);
        public:
            long long sumAndMultiply(int n);
    };

    int Program::findNumDigits(int n) {
        if (n == 0) return 1;
        return std::log10(n) + 1;
    }

    long long Program::sumAndMultiply(int n) {
        long long sum = 0;
        long long x = 0;
        int numDigits = findNumDigits(n);
        int num = std::pow(10, numDigits);

        std::vector<int> numbers;
        for (int i=0, j=num; i<=numDigits; i++,num/=10) {
            int digit = (n / num) % 10;
            if (digit > 0) numbers.push_back(digit);
            else continue;
            sum += digit;
        }

        numDigits = numbers.size()-1;
        for (int i=0, j=std::pow(10, numDigits); i<numbers.size(); i++, j/=10)
            x += (numbers[i] * j);

        return x * sum;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.sumAndMultiply(n) << endl;
    return 0;
}
