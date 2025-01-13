// LeetCode 3223
#include <iostream>
#include <string>
#include <unordered_map>

using std::cout, std::endl;
using std::string, std::unordered_map;

static string s = "abaacbcbb";
static string s1 = "aa";

namespace Solution {
    class Program {
        public:
            int MinimumLength(string s);
    };
    int Program::MinimumLength(string s) {
        unordered_map<char, int> count;
        for (char c : s)
            count[c]++;
        
        int stringSize = 0;
        for (unordered_map<char,int>::iterator it=count.begin(); it!=count.end(); it++) {
            if (count[it->first] % 2 == 0) stringSize += 2;
            else stringSize++;
        }
        return stringSize;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.MinimumLength(s) << endl;
    cout << obj.MinimumLength(s1) << endl;
    return 0;
}