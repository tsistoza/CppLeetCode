// LeetCode 1790
#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

static string s1 = "bank";
static string s2 = "kanb";
static string s1a = "attack";
static string s2a = "defend";
static string s1b = "kelb";
static string s2b = "kelb";

namespace Solution {
    class Program {
        public:
            bool areAlmostEqual(string s1, string s2);
    };

    bool Program::areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        
        int differ = 0;
        for (int i=0; i<s1.size(); i++)
            if (s1[i] != s2[i]) differ++;
    
        if (differ == 2 || differ == 0) return true;
        return false;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.areAlmostEqual(s1,s2) << endl;
    cout << obj.areAlmostEqual(s1a,s2a) << endl;
    cout << obj.areAlmostEqual(s1b,s2b) << endl;
    return 0;
}