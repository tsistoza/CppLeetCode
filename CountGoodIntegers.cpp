// LeetCode 3272
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <ios>
#include <unordered_set>

using std::cout, std::endl, std::string, std::vector;
using std::unordered_set, std::stoi, std::ceil;

static int n = 5, k = 6;

namespace Solution {
    class Program {
        private:
            void findPalindromic(string num, vector<string>& palindromes, int digitsLeft, int maxDigits, bool tight, int k);
            void generatePermutations(unordered_set<int>& count, unordered_set<int> idx, string palindrome, string curr);
        public:
            long countGoodIntegers(int n, int k);
    };

    void Program::generatePermutations(unordered_set<int>& count, unordered_set<int> idx, string palindrome, string curr) {
        if (curr.size() == palindrome.size()) {
            int num = stoi(curr);
            if (!count.contains(num))
                count.insert(num);
            return;
        }

        for (int i=0; i<palindrome.size(); i++) {
            unordered_set<int> tmp(idx);
            string newCurr(curr);
            if (curr.size() == 0 && palindrome[i] == '0') continue;
            if (tmp.contains(i)) continue;
            tmp.insert(i);
            newCurr += palindrome[i];
            generatePermutations(count, tmp, palindrome, newCurr);
        }

        return;
    }

    void Program::findPalindromic(string num, vector<string>& palindromes, int digitsLeft, int maxDigits, bool tight, int k) {
        if (digitsLeft == 0) {
            int kPalindromic = stoi(num);
            if ((kPalindromic % k) == 0)
                palindromes.push_back(num);
            return;
        }

        char lb = (tight) ? num[digitsLeft-1] : '0';
        if (num.size() == 0) lb = '1';
        char ub = (tight) ? num[digitsLeft-1] : '9';
        bool newTight = ((int) (ceil((float)maxDigits/2.0)) ) <= num.size()+1;
        for (; lb<=ub; lb++) {
            string newNum(num);
            newNum += lb;
            findPalindromic(newNum, palindromes, digitsLeft-1, maxDigits, newTight, k);
        }

        return;
    }

    long Program::countGoodIntegers(int n, int k) {
        unordered_set<int> count;
        vector<string> palindromes;
        vector<int> possibleSoln;
        findPalindromic("", palindromes, n, n, false, k);
        
        for (string i : palindromes){
            int num = stoi(i);
            if ((num % k) == 0) count.insert(num);
            generatePermutations(count, unordered_set<int>(), i, "");
        }

        return (long) count.size();
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.countGoodIntegers(n, k) << endl;
    return 0;
}