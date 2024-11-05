// LeetCode 2914
#include <iostream>
#include <string>

using std::cout, std::endl;
using std::string, std::iterator;

static string s = "1001";
static string testWords1 = "10";
static string testWords2 = "0000";

namespace Solution {
    class Program {
        public:
            int minChanges(string s);
    };

    int Program::minChanges(string s) {
        int change=0;
        char c = s[0];
        string modS = "";
        string substring;
        substring.push_back(c);
        for (string::iterator it=s.begin()+1; it!=s.end(); it++) 
        {
            if (c != *it && !substring.size() % 2) substring.clear();
            if (c != *it && substring.size() % 2) {
                substring.push_back(c);
                change++;
                modS += substring;
                substring.clear();
                continue;
            }
            substring.push_back(*it);
            c = *it;
        }
        if (substring.size() != 0) modS+=substring;
        return change;
    }
}

int main() {
    Solution::Program obj;
    cout << obj.minChanges(s) << endl;
    cout << obj.minChanges(testWords1) << endl;
    cout << obj.minChanges(testWords2) << endl;
    return 0;
}