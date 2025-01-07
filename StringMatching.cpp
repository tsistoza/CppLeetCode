// LeetCode 1408
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::cout, std::endl;
using std::vector, std::string;
using std::unordered_map;

static vector<string> words { "mass", "as", "hero", "superhero" };
static vector<string> words1 { "leetcode", "et", "code" };

namespace Solution {
    class Program{
        private:
            bool isSubstring(string word, string substring);
        public:
            vector<string> stringMatching(vector<string>& words);
    };

    bool Program::isSubstring(string word, string substring) {
        for(string::iterator it=word.begin(); it!=word.end(); it++) {
            if (*it != substring[0])
                continue;
                
            int i=0;
            string::iterator it2=it;
            for (; i<substring.size(); i++,it2++) {
                if (it2 == word.end()) break;
                if (*it2 != substring[i]) break;
            }
            if (i == substring.size()) return true;
        }
        return false;
    }


    vector<string> Program::stringMatching(vector<string>& words) {
        vector<string> result;

        for (vector<string>::iterator it=words.begin(); it!=words.end(); it++) {
            for (vector<string>::iterator it2=words.begin(); it2!=words.end(); it2++) {
                if (it == it2) continue;
                if (it2->size() < it->size()) continue;
                if (isSubstring(*it2, *it)) result.push_back(*it);
            }
        }
        return result;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    for (string s : obj.stringMatching(words))
        cout << s << " ";
    cout << endl;

    for (string s : obj.stringMatching(words1))
        cout << s << " ";
    cout << endl;
    return 0;
}