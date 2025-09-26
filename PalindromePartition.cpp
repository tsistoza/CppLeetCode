// LeetCode 131
#include <iostream>
#include <vector>
#include <string>

using std::cout, std::endl, std::vector, std::string;

static string s = "abaca";

namespace Solution {
    class Program {
        private:
            bool isPalindrome(string substr);
            void backtrack(vector<vector<string>>& results, string s, vector<string> subtition, int index);
        public:
            vector<vector<string>> partition(string s);
            static inline void prettyPrint(vector<vector<string>> results) {
                cout << "{ ";
                for (vector<string> result : results) {
                    cout << "{ ";
                    for (string s : result)
                        cout << s << " ";
                    cout << "} ";
                }
                cout << "} " << endl;
                return;
            }
    };

    bool Program::isPalindrome(string substr) {
        if (substr.size() == 1) return true;
        int left, right;
        if ((substr.size() % 2) == 0) {
            left = 0;
            right = substr.size()-1;

            while (left < right) 
                if (substr[left++] != substr[right--]) return false;
        } else {
            int mid = (substr.size()-1) / 2;
            left = mid - 1;
            right = mid + 1;

            while (left >= 0 && right < substr.size()) 
                if (substr[left--] != substr[right++]) return false;
        }

        return true;
    }

    void Program::backtrack(vector<vector<string>>& results, string s, vector<string> subtition, int index) {
        if (index >= s.size()) {
            if (isPalindrome(subtition[subtition.size()-1]))
                results.push_back(subtition);
            return;
        }

        string newStr;
        for (int i=index; i<s.size(); i++) {
            vector<string> newSubtition(subtition);
            newStr += s[i];
            if (!isPalindrome(newStr)) continue;
            if (subtition.size() == 0)
                backtrack(results, s, vector<string> { newStr }, i+1);
            else {
                newSubtition.push_back(newStr);
                backtrack(results, s, newSubtition, i+1);
            }
        }
        return;
    }

    vector<vector<string>> Program::partition(string s) {
        vector<vector<string>> results;
        backtrack(results, s, vector<string> (), 0);
        return results;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    Program::prettyPrint(obj.partition(s));
    return 0;
}