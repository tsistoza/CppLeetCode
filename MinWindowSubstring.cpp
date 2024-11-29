// LeetCode 76
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::cout, std::endl;
using std::string, std::vector;
using std::unordered_map, std::to_string;
using std::sort;

static string s = "ADOBECODEBANC";
static string t = "ABC";
static string s1 = "a";
static string t1 = "a";
static string s2 = "a";
static string t2 = "aa";

namespace Solution {
    class Compare {
        public:
            bool operator()(string s1, string s2) const { return s1.size() < s2.size(); }
    };

    class Program {
        private:
            bool isValid(unordered_map<char,int> numCharsT, unordered_map<char,int> numCharsSub);
        public:
            string minWindow(string s, string t);
    };

    // Idea: Find any char in s that is included in t, that will be the starting point.
    // Keep traversing the string till its valid, save the string. Rinse and repeat.
    string Program::minWindow(string s, string t) {
        unordered_map<char, int> numChars;  // using hashtables, we can see easily do comparisons between t and a substring.
        vector<string> substrings;
        for(string::iterator it=t.begin(); it!=t.end(); it++) // numChars['A'] = # of A's in string t
            numChars[*it]++;

        for (string::iterator it=s.begin(); it!=s.end(); it++) {
            unordered_map<char,int> numCharsSub;
            if(!numChars.contains(*it)) continue;
            string substring = "";
            for (string::iterator it2=it; it2!=s.end(); it2++) {
                substring.push_back(*it2);
                numCharsSub[*it2]++;
                if (!isValid(numChars, numCharsSub)) continue;
                substrings.push_back(substring);
                break;
            }
        }
    
    if (substrings.empty()) return "";
    Compare cmp;
    sort(substrings.begin(),substrings.end(), cmp);
    return substrings[0];
    }

    // Returns true if the substring contains all elements in string t
    bool Program::isValid(unordered_map<char,int> numCharsT, unordered_map<char,int> numCharsSub) {
        for (auto it=numCharsT.begin(); it!=numCharsT.end(); it++)
            if (numCharsSub[it->first] < it->second) return false;
        return true;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.minWindow(s, t) << endl;
    cout << obj.minWindow(s1, t1) << endl;
    cout << obj.minWindow(s1, t2) << endl;
    return 0;
}