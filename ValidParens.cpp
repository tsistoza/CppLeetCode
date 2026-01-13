// LeetCode 20
#include <iostream>
#include <ios>
#include <stack>
#include <string>

using std::cout, std::endl, std::string, std::stack;

static string s = "([])";

namespace Solution {
    class Program {
        public:
            bool isValid(string s);
    };

    bool Program::isValid(string s) {
        stack<char> check;

        for (int i=0 ;i<s.size(); i++) {
            if (check.size() == 0) {
                check.push(s[i]);
                continue;
            }

            char top = check.top();
            if (top == '}' || top == ')' || top == ']') return false;
            
            bool popped = false;
            switch (top) {
                case '(': if (s[i] == ')') popped = true;
                    break;
                case '{': if (s[i] == '}') popped = true;
                    break;
                case '[': if (s[i] == ']') popped = true;
                    break;
            }
            
            if (popped) {
                check.pop();
                continue;
            }
            else check.push(s[i]);
        }

        return check.size() == 0;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << std::boolalpha << obj.isValid(s) << endl;
    return 0;
}