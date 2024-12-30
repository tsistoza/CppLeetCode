// LeetCode 423
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::cout, std::endl;
using std::string, std::vector;
using std::unordered_map, std::sort;

static string s = "owoztneoer";
static string s1 = "fviefuro";

namespace Solution {
    class Program {
        private:
            unordered_map<char, int> charToInt;
            unordered_map<char, string> charToStr;
            unordered_map<char, int> charCount;
            void removeChars(string& s, string num);
        public:
            string originalDigits(string s);

            Program() {
                this->charToInt = { {'z', 0}, {'w', 2}, {'u', 4}, {'x', 6},
                                    {'g', 8}, {'o', 1}, {'t', 3}, {'f', 5}, {'s', 7} };
                this->charToStr = { {'z', "zero"}, {'w', "two"}, {'u', "four"}, {'x', "six"},
                                    {'g', "eight"}, {'o', "one"}, {'t', "three"}, {'f', "five"}, {'s', "seven"} };
                this->charCount = { {'z', 0}, {'w', 0}, {'u', 0}, {'x', 0}, {'g', 0},
                                    {'o', 0}, {'t', 0}, {'f', 0}, {'s', 0} };
            }
    };

    void Program::removeChars(string& s, string num) {
        for (int i=0; i<num.size(); i++) {
            for (string::iterator it=s.begin(); it!=s.end(); it++) {
                if (*it == num[i]) {
                    s.erase(it);
                    break;
                }
            }
        }
        return;
    }

    string Program::originalDigits(string s) {
        string ans = "";
        vector<int> digits;
        vector<char> even { 'z', 'w', 'u', 'x', 'g' };
        vector<char> odd { 'o', 't', 'f', 's' };

        for (auto it=even.begin(); it!=even.end(); it++) {
            for (string::iterator it2=s.begin(); it2!=s.end(); it2++) {
                if (*it == *it2) {
                    this->charCount[*it2]++;
                    digits.push_back(this->charToInt[*it2]);
                }
            }
        }

        for (auto it=this->charCount.begin(); it!=charCount.end(); it++) {
            if (it->second == 0) continue;
            while (it->second > 0) {
                removeChars(s, charToStr[it->first]);
                it->second--;
            }
        }

        for (auto it=odd.begin(); it!=odd.end(); it++) {
            for (string::iterator it2=s.begin(); it2!=s.end(); it2++) {
                if (*it == *it2) {
                    this->charCount[*it2]++;
                    digits.push_back(this->charToInt[*it2]);
                }
            }
        }

        for (auto it=this->charCount.begin(); it!=charCount.end(); it++) {
            if (it->second == 0) continue;
            while (it->second > 0) {
                removeChars(s, charToStr[it->first]);
                it->second--;
            }
        }

        if (s.size() == 4) digits.push_back(9);

        sort(digits.begin(), digits.end());
        for (int i=0; i<digits.size(); i++)
            ans.push_back((char)digits[i]+48);
        return ans;
    }
}

int main () {
    using namespace Solution;
    Program obj;
    cout << obj.originalDigits(s) << endl;
    cout << obj.originalDigits(s1) << endl;
    return 0;
}