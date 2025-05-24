// LeetCode 2942
#include <iostream>
#include <vector>
#include <string>

using std::cout, std::endl, std::vector;
using std::string;

static vector<string> words { "leet", "code" };
static char x = 'e';

namespace Solution {
    class Program {
        public:
            static inline void prettyPrint(vector<int> idx) {
                cout << "{ ";
                for (int i : idx) cout << i << ", ";
                cout << "}" << endl;
                return;
            }
            vector<int> findWordsContaining(vector<string>& words, char x);
    };

    vector<int> Program::findWordsContaining(vector<string>& words, char x) {
        vector<int> idx;
        for (int i=0; i<words.size(); i++) {
            for (int j=0; j<words[i].size(); j++) {
                if (words[i][j] != x) continue;
                idx.push_back(i);
                break;
            }
        }
        return idx;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    Program::prettyPrint(obj.findWordsContaining(words, x));
    return 0;
}