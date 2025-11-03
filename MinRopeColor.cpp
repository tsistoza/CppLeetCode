// LeetCode 1578
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout, std::endl, std::vector, std::string;
using std::min;

static string colors = "aaaa";
static vector<int> neededTime { 1, 2, 3, 4 };

namespace Solution {
    class Program {
        public:
            int minCost(string colors, vector<int>& neededTime);
    };

    int Program::minCost(string colors, vector<int>& neededTime) {
        vector<int> dp(colors.size(), 0);
        char lastColor=colors[0];
        
        for (int i=1; i<colors.size(); i++) {
            dp[i] = (lastColor == colors[i]) ? dp[i-1] + min(neededTime[i-1], neededTime[i]) : dp[i-1];
            lastColor=colors[i];
        }

        return dp[colors.size()-1];
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.minCost(colors, neededTime) << endl;
    return 0;
}