// LeetCode 1048
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::sort;
using std::string, std::vector, std::to_string;

static vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
static vector<string> test_words = { "xbc","pcxbcf","xb","cxbc","pcxbc" };
static vector<string> test_words2 = { "abcd","dbqca" };

namespace Solution {
    class Compare {
        public:
            bool operator()(string word1,string word2) const { return word1.size() < word2.size(); }
    };

    class Program {
        public:
            int longestStrChain(vector<string>& words);
            bool isPredecessor(string wordA, string wordB);
    };

    int Program::longestStrChain(vector<string>& words) {
        Compare obj;
        sort(words.begin(), words.end(), obj);
        vector<int> dp(words.size(), 1); // Populate vector<int> with 1's, as that is the minimum possible answer
        
        // Check if each word[j] is a predecessor of word[i]
        for (int i=0; i<words.size(); i++)
            for (int j=0; j<i; j++)
                if (isPredecessor(words[j], words[i]) && dp[i] < dp[j] + 1) // we know if word[j] is also a predecessor of word[j-1] because dp[i] < dp[j] + 1
                    dp[i] = dp[j] + 1;
        return dp[words.size()-1];
    }

    // Checks if wordA is predecessor of wordB
    bool Program::isPredecessor(string wordA, string wordB) {
        // WordA can only be a predecessor of wordB only if we add exactly one letter, and it still be the same as wordB
        if (wordA.size()+1 != wordB.size()) return false;
        string modWordA;
        string::iterator it = wordA.begin();
        int index=0;

        for (; it!=wordA.end() ;it++) {
            if (*it != wordB[index]) { // Find the difference, and append it to the modified word A
                modWordA.push_back(wordB[index]);
                break;
            }
            index++;
            modWordA.push_back(*it);
        }
        if (it==wordA.end()) modWordA.push_back(wordB[index]); // continue on with copying wordA to modWordA
        for(; it!=wordA.end(); it++) modWordA.push_back(*it);

        //Check if modWordA == wordB
        for (int i=0; i<modWordA.size(); i++) if (modWordA[i] != wordB[i]) return false;
        return true;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.longestStrChain(words) << endl;
    return 0;
}