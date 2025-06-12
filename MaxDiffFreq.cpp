// LeetCode 3442
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cmath>

using std::cout, std::endl, std::string;
using std::unordered_map, std::vector, std::abs;

static string s = "aaaaabbc";

namespace Solution {
    class Program {
        public:
            int maxDifference(string s);
    };
    int Program::maxDifference(string s) {
        unordered_map<char, int> dict;
        for (char c : s) dict[c]++;
        
        vector<char> even;
        vector<char> odd;
        for (unordered_map<char,int>::iterator it=dict.begin(); it!=dict.end(); it++) {
            if (it->second % 2) odd.push_back(it->first);
            else even.push_back(it->first);
        }

        int difference = INT_MIN;
        for (int i=0; i<even.size(); i++) {
            for (int j=0; j<odd.size(); j++) {
                int currDiff = abs(dict[even[i]] - dict[odd[j]]);
                if (currDiff > difference) difference = currDiff;
            }
        }
        return difference;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.maxDifference(s) << endl;
    return 0;
}