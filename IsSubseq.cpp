// LeetCode 392
#include <iostream>
#include <vector>
#include <string>
#include <ios>

using std::cout, std::endl, std::vector;
using std::string;

static string s = "axc", t = "ahbgdc";

namespace Solution {
    class Program {
        public:
            bool isSubsequence(string s, string t);
    };

    bool Program::isSubsequence(string s, string t) {
        int j=0;
        for (int i=0; i<t.size() && j<s.size(); i++) {
            if (t[i] == s[j]) j++;
        }
        return (j == s.size());
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << std::boolalpha << obj.isSubsequence(s, t) << endl;
    return 0;
}