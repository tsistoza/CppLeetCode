// LeetCode 2243
#include <iostream>
#include <string>
#include <charconv>

using std::cout, std::endl, std::string;

static string s = "11111222223";
static int k = 3;

namespace Solution {
    class Program{
        public:
            string digitSum(string s, int k);
    };

    string Program::digitSum(string s, int k) {
        int n = s.size();
        while (s.size() > k) {
            cout << "string s = " << s << endl;
            string newString;
            int sum = 0;
            for (int i=0; i<s.size(); i++) {
                sum += ((int)s[i])-48;
                if (((i+1) % k == 0) || i == s.size()-1) {
                    newString += std::to_string(sum);
                    sum = 0;
                }
            }
            s = std::move(newString);
        }

        return s;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.digitSum(s, k) << endl;
    return 0;
}