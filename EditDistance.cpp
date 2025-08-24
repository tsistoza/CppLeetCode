// LeetCode 72
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::string;
using std::vector, std::min;

static string word1 = "intention";
static string word2 = "execution";

namespace Solution {
    class Program {
        public:
            int minDistance(string word1, string word2);
    };

    int Program::minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));


        for (int i=0; i<dp.size(); i++)
            dp[i][0] = i;

        for (int j=0; j<dp[0].size(); j++)
            dp[0][j] = j;
        
        for (int i=1; i<dp.size(); i++) {
            for (int j=1; j<dp[i].size(); j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                    continue;
                }

                int low = min(1 + dp[i-1][j-1], 1 + dp[i-1][j]);
                dp[i][j] = min(low, 1+dp[i][j-1]);
            }
        }

        return dp[m][n];
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.minDistance(word1, word2) << endl;
    return 0;
}