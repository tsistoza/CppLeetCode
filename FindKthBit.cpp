// LeetCode 1545
#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

static int n = 3;
static int k = 1;

namespace Solution {
    class Program {
        private:
            string invert(string s);
            string reverse(string s);
        public:
            char findKthBit(int n, int k);
    };

    string Program::invert(string s) {
        string newStr;
        for (int i=0; i<s.size(); i++)
            newStr += (s[i] == '0') ? '1' : '0';
        return newStr;
    }

    string Program::reverse(string s) {
        string newStr;
        for (string::reverse_iterator itr = s.rbegin(); itr!=s.rend(); itr++)
            newStr += (*itr);
        return newStr;
    }

    char Program::findKthBit(int n, int k) {
        string curr = "0", next = "0";
        for (int i=1; i<n; i++) {
            next = curr + "1" + reverse(invert(curr));
            //cout << "curr: " << curr << ", next: " << next << endl;
            curr = next;
        }
        return next[k-1];
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.findKthBit(n, k) << endl;
    return 0;
}