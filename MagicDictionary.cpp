// LeetCode 676
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::cout, std::endl;
using std::vector, std::string;
using std::unordered_map;

static vector<string> dictionary { "hello", "leetcode" };

namespace Solution {
    class MagicDictionary {
        private:
            unordered_map<int, vector<string>> dict; // Stores strings based on current size of string, Ex: dict[5] = {"hello"}
        public:
            void buildDict(vector<string>& dictionary);
            bool search(string searchWord);
    };
    void MagicDictionary::buildDict(vector<string>& dictionary) {
        for (string s : dictionary)
            dict[s.size()].push_back(s);
        return;
    }

    // Get all strings with the same size, ignore anyone ones that dont have the same size as searchword
    // Keep track of the differences, if there is only one difference return true, otherwise move on to the next word
    // If all words are exhausted, return false.
    bool MagicDictionary::search(string searchWord) {
        for (string s : this->dict[searchWord.size()]) {
            int changes=0;
            for (int i=0; i<s.size(); i++)
                if (s[i] != searchWord[i]) changes++;
            if (changes == 1) return true;
        }
        return false;
    }
}

int main () {
    using namespace Solution;
    MagicDictionary* magicDictionary = new MagicDictionary();
    magicDictionary->buildDict(dictionary);
    cout << magicDictionary->search("hello") << endl;
    cout << magicDictionary->search("hhllo") << endl;
    cout << magicDictionary->search("hell") << endl;
    cout << magicDictionary->search("leetcoded") << endl;
    return 0;
}