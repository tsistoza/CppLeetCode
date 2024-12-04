// LeetCode 139
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::cout, std::endl;
using std::string, std::vector;
using std::unordered_map;

static string s = "leetcode";
static vector<string> wordDict {"leet", "code"};
static string s1 = "applepenapple";
static vector<string> wordDict1 {"apple", "pen"};
static string s2 = "catsandog";
static vector<string> wordDict2 {"cats", "dogs", "sand", "and", "cat"};

namespace Solution {
    class Program {
        public:
            bool wordBreak(string s, vector<string>& wordDict);
    };
    
    bool Program::wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> map;
        for(string word : wordDict) map[word]++;

        // Start from the beginning, find all words starting with the char s[0].
        for (vector<string>::iterator it=wordDict.begin(); it!=wordDict.end(); it++) {
            int index=0;
            if ((*it)[0] != s[index]) continue;
            string word = *it;
            vector<string> wordDictCopy(wordDict);
            while (index < s.size()) {
                index+=word.size();
                for (string wrd : wordDictCopy) {
                    if (index+wrd.size() > s.size()) continue;
                    string check = s.substr(index,wrd.size());
                    if (check == wrd) { // If the substring of s is in wordDict, add the size to the index
                        word = wrd;
                        break;
                    }
                }
                if (index == s.size()) return true; // if the index reaches the string size() then s can be segemented.
            }
        }
        return false;
    }
}

int main () {
    using namespace Solution;
    Program obj;
    cout << obj.wordBreak(s, wordDict) << endl;
    cout << obj.wordBreak(s1, wordDict1) << endl;
    cout << obj.wordBreak(s2, wordDict2) << endl;
    return 0;
}