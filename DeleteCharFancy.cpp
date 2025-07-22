// LeetCode 1957
#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

static string s = "aab";

namespace Solution {
    class Program {
        public:
            string makeFancyString(string s);
    };

    string Program::makeFancyString(string s) {
        string temp=s;
        int numChar = 0;
        char lastChar = 0;
        for (string::iterator it=temp.begin(); it!=temp.end(); ) {
            if (*it == lastChar) numChar++;
            else {
                lastChar=*it;
                numChar=1;
            }

            if (numChar > 2) it=temp.erase(it);
            else it++;
        }

        return temp;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.makeFancyString(s) << endl;
    return 0;
}