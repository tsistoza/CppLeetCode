#include <iostream>
#include <vector>
#include <unordered_set>

using std::cout, std::endl, std::unordered_set;

static int k = 1;

namespace Solution {
    class Program {
        public:
            int smalledRepunditDivByK(int k);
    };

    int Program::smalledRepunditDivByK(int k) {
        unordered_set<int> remainders;
        if (k%2 == 0 || k%5 == 0) return -1;
        int n = 1;
        int rem = n % k;
        while (!remainders.contains(rem) && rem != 0) {
            cout << "rem = " << rem << " n = " << n << endl;
            remainders.insert(rem);
            n = (n*10) + 1;
            rem = n % k;
        }

        if (rem == 0) return n;
        else return -1;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.smalledRepunditDivByK(k) << endl;
    return 0;
}