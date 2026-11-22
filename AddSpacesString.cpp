// LeetCode 2109
#include <iostream>
#include <string>
#include <vector>

using std::cout, std::endl;
using std::string, std::vector;

static string s = "LeetcodeHelpsMeLearn";
static vector<int> spaces { 8, 13, 15 };
static string s1 = "icodeinpython";
static vector<int> spaces1 { 1, 5, 7, 9 };
static string s2 = "spacing";
static vector<int> spaces2 { 0, 1, 2, 3, 4, 5, 6 };


namespace Solution {
    class Program {
        public:
            string addSpaces(string s, vector<int>& spaces);
    };
    string Program::addSpaces(string s, vector<int>& spaces) {
        int startSubStr = 0;
        string currStr;
        for (int i=0; i<spaces.size(); i++) {
            for (int j=startSubStr; j<spaces[i]; j++)
                currStr.push_back(s[j]);
            currStr.push_back(' ');
            startSubStr = spaces[i];
        }

        for (int i=startSubStr; i<s.size(); i++)
            currStr.push_back(s[i]);
        return currStr;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.addSpaces(s, spaces) << endl;
    cout << obj.addSpaces(s1, spaces1) << endl;
    cout << obj.addSpaces(s2, spaces2) << endl;
    return 0;
}