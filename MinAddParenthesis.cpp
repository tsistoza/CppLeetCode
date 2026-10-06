// LeetCode 921
#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

static string s = "()))((";

namespace Solution {
    class Program {
        public:
            int minAddToMakeValid(string s);
    };

    int Program::minAddToMakeValid(string s) {
        int moves = 0, open = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') {
                moves++;
                open++;
                continue;
            }

            if (s[i] == ')') {
                if (open == 0) {
                    moves++;
                    continue;
                }
                moves--;
                open--;
            }
        }

        return moves;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.minAddToMakeValid(s) << endl;
    return 0;
}