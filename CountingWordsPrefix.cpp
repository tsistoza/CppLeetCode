// LeetCode 2185
#include <iostream>
#include <vector>
#include <string>

using std::cout, std::endl;
using std::vector, std::string;

static vector<string> words { "pay", "attention", "practice", "attend" };
static string pref = "at";
static vector<string> words1 { "leetcode", "win", "loops", "success" };
static string pref1 = "code";

namespace Solution {
    class Program {
        public:
            int prefixCount(vector<string>& words, string pref);
    };

    int Program::prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (string word : words) {
            int i=0;
            for (; i<pref.size(); i++)
                if (word[i] != pref[i]) break;
            if (i == pref.size()) count++;
        }
        return count;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.prefixCount(words, pref) << endl;
    cout << obj.prefixCount(words1, pref1) << endl;
    return 0;
}