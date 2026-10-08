// LeetCode 1358
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::string, std::vector, std::min;

static string s = "caccabab";

namespace Solution {
    class Program {
        public:
            int numberOfSubstrings(string s);
    };

    int Program::numberOfSubstrings(string s) {
        int sum = 0;
        int left = 0, right = 0;
        int ptrA=0, ptrB=0, ptrC=0;
        vector<int> indexesA;
        vector<int> indexesB;
        vector<int> indexesC;

        while (right <= s.size()) {
            // Find indexes A, B, C --> Push to list
            if (ptrA == indexesA.size() || ptrB == indexesB.size() || ptrC == indexesC.size()) { 
                if (right >= s.size()) break;
                switch (s[right]) {
                    case 'a': indexesA.push_back(right);
                        break;
                    case 'b': indexesB.push_back(right);
                        break;
                    case 'c': indexesC.push_back(right);
                        break;
                }
                right++;
                continue;
            }
            
            // From left to (right - 1) we already have a string that contains ABC
            // Start From min index from either A, B, C
            left = min(indexesA[ptrA], min(indexesB[ptrB], indexesC[ptrC]));
            //cout << "indexA = " << indexesA[ptrA] << ", indexB = " << indexesB[ptrB] << ", indexC = " << indexesC[ptrC] << endl;

            sum += s.size() - right + 1;

            // Reset min index, if ptr is greater than size of list, we dont have an index for that character
            if (left == indexesA[ptrA]) ptrA++;
            else if (left == indexesB[ptrB]) ptrB++;
            else ptrC++;
            //cout << "left = " << left << ", right = " << right << ", sum = " << sum << endl;
        }

        return sum;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.numberOfSubstrings(s) << endl;
    return 0;
}