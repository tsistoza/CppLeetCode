// LeetCode 3577
#include <iostream>
#include <vector>
#include <map>

using std::cout, std::endl, std::vector, std::map;

static vector<int> complexity { 1, 2, 3 };

namespace Solution {
    class Program {
        private:
            unsigned long long factorial(int n);
        public:
            int countPermutations(vector<int>& complexity);
    };

    unsigned long long Program::factorial(int n) {
        int start = n;
        for (int i=n-1; i>0; i--)
            start *= i;
        return start;
    }

    int Program::countPermutations(vector<int>& complexity) {
        int mod = 1e10 + 7;
        map<int, int> uniqueElems;
        for (int i=0; i<complexity.size(); i++) {
            if (uniqueElems.contains(complexity[i])) {
                uniqueElems[complexity[i]]++;
                continue;
            }
            uniqueElems.insert({ complexity[i], 1 });
        }

        if (complexity[0] != uniqueElems.begin()->first || uniqueElems[complexity[0]] > 1) return 0;
        unsigned long long ans = factorial(complexity.size()-1);
        return (ans % mod);
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.countPermutations(complexity) << endl;
    return 0;
}