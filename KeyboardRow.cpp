// LeetCode 500
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using std::cout, std::endl, std::vector, std::string;
using std::unordered_set;

static vector<string> words { "adsdf" , "sfd" };

namespace Solution {
    class Program {
        public:
            static void prettyPrint(vector<string> words);
            vector<string> findWords(vector<string>& words);
    };

    void Program::prettyPrint(vector<string> words) {
        cout << "{ ";
        for (string s : words)
            cout << s << ", ";
        cout << "}" << endl;
        return;
    }

    vector<string> Program::findWords(vector<string>& words) {
        vector<string> results;
        unordered_set<char> row1 { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        unordered_set<char> row2 { 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l' };
        unordered_set<char> row3 { 'z', 'x', 'c', 'v', 'b', 'n', 'm' };
        vector<unordered_set<char>> row { row1, row2, row3 };
        
        for (int i=0; i<words.size(); i++) {
            for (int j=0; j<row.size(); j++) {
                int k=0;
                for (; k<words[i].size(); k++) {
                    char ch = words[i][k];
                    if (words[i][k] < 97) ch += 32;
                    if (!row[j].contains(ch)) break;
                }
                if (k < words[i].size()) continue;
                results.push_back(words[i]);
                break;
            }
        }
        return results;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    Program::prettyPrint(obj.findWords(words));
    return 0;
}
