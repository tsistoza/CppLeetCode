// LeetCode 1930
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using std::cout, std::endl;
using std::string, std::unordered_map;


static string s = "aabca";
static string s1 = "adc";
static string s2 = "bbcbaba";

namespace Solution {
    class Program {
        private:
            bool palindrome3Check(string s);
            void getAllSubseqs(int& count, unordered_map<string, int>& dict, string s, string subseq, int index);
        public:
            int CountPalindromicSubsequence(string s);
    };

    bool Program::palindrome3Check(string s) {
        if (s.size() != 3) return false;
        for (int i=0,j=s.size()-1; (i<s.size() && j>=0); i++,j--)
            if (s[i] != s[j]) return false;
        return true;
    }

    void Program::getAllSubseqs(int& count, unordered_map<string, int>& dict, string s, string subseq, int index) {
        if (palindrome3Check(subseq) && subseq.size() == 3 && !dict.contains(subseq)) {
            count++;
            dict[subseq]++;
            return;
        }

        if (index >= s.size()) return;

        string clone(subseq);
        clone += s[index];
        getAllSubseqs(count, dict, s, clone, index+1);
        
        if (subseq.size() == 0) return;

        string clone1(subseq);
        clone1.erase(clone1.end()-1);
        clone1 += s[index];
        getAllSubseqs(count, dict, s, clone1, index+1);
        return;
    }


    int Program::CountPalindromicSubsequence(string s) {
        int count = 0;
        unordered_map<string, int> dict;
        getAllSubseqs(count, dict, s, "", 0);
        return count;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.CountPalindromicSubsequence(s) << endl;
    cout << obj.CountPalindromicSubsequence(s1) << endl;
    cout << obj.CountPalindromicSubsequence(s2) << endl;
    return 0;
}