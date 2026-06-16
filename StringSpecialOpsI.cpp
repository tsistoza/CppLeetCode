// LeetCode 3612
#include <iostream>
#include <string>
#include <algorithm>

using std::cout, std::endl, std::string, std::reverse;

static string s = "z*#";

namespace Solution {
    class Program {
        public:
            string processStr(string s);
    };

    string Program::processStr(string s) {
        string result = "";

        for (char c : s) {
            switch(c) {
                case '*': result.pop_back();
                    break;
                case '#': result.append(result);
                    break;
                case '%': reverse(result.begin(), result.end());
                    break;
                default: result += c;
                    break;
            }
        }

        return result;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.processStr(s) << endl;
    return 0;
}