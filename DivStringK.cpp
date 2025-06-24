// LeetCode 2138
#include <iostream>
#include <string>
#include <vector>

using std::cout, std::endl, std::string, std::vector;

static string s = "abcdefghij";
static int k = 3;
static char fill = 'x';

namespace Solution {
    class Program {
        public:
            static inline void prettyPrint(vector<string> ans) {
                cout << "{ ";
                for(string s : ans) cout << s << " ";
                cout << "}" << endl;
                return;
            }
            vector<string> divideString(string s, int k, char fill);
    };
    vector<string> Program::divideString(string s, int k, char fill) {
        vector<string> result;
        string currStr = "";
        for (int i=0; i<s.size(); i++) {
            currStr += s[i];
            if (currStr.size() == k) {
                result.push_back(currStr);
                currStr = "";
            }
        }

        if (currStr.size() < k && currStr.size() > 0) {
            while (currStr.size() < k)
                currStr += fill;
            result.push_back(currStr);
        }

        return result;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    Program::prettyPrint(obj.divideString(s, k, fill));
    return 0;
}