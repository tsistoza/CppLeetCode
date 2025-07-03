// LeetCode 3330
#include <iostream>
#include <string>
#include <vector>

using std::cout, std::endl, std::string;
using std::vector;

static string word = "aaaa";

namespace Solution {
    class Program {
        public:
            int possibleStringCount(string word);
    };

    int Program::possibleStringCount(string word) {
        int ans = 1;
        vector<int> dict(26, 0);
        for (char c : word) {
            dict[c-97]++;
            if (dict[c-97] > 1) ans++;
        }

        return ans;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.possibleStringCount(word) << endl;
    return 0;
}