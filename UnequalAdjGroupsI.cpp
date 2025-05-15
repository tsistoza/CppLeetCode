// LeetCode 2900
#include <iostream>
#include <vector>
#include <string>

using std::cout, std::endl, std::vector;
using std::string;

static vector<string> words { "a", "b", "c", "d" };
static vector<int> groups { 1, 0, 1, 1 };

namespace Solution {
    class Program {
        public:
            static void prettyPrint(vector<string> max);
            vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups);
    };

    void Program::prettyPrint(vector<string> max) {
        cout << "{ ";
        for (string s : max)
            cout << s << ", ";
        cout << "}" << endl;
        return;
    }

    vector<string> Program::getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> max;
        vector<vector<string>> dp(words.size(), vector<string>());

        int idx0 = (groups[0] == 0) ? 0 : -1;
        int idx1 = (groups[0] == 1) ? 0 : -1;
        dp[0].push_back(words[0]);
        if (words.size() == 1) return dp[0];

        for (int i=1; i<words.size(); i++) {
            if (groups[i] == 0 && groups[i-1] != groups[i]) idx0 = i;
            if (groups[i] == 1 && groups[i-1] != groups[i]) idx1 = i;
            if (i == 0) dp[i].push_back(words[i]);
            if (idx0 == -1 || idx1 == -1) {
                dp[i] = (idx0 != -1) ? dp[idx0] : dp[idx1];
                continue;
            }

            dp[i] = (groups[i] == 0) ? dp[idx1] : dp[idx0];
            //cout << "Building List: idx0 = " << idx0 << ", idx1 = " << idx1 << endl;
            //Program::prettyPrint(dp[i]);
            //cout << "dp[" << i << "].size()=" << dp[i].size() << endl;
            dp[i].push_back(words[i]);
            max = (dp[i].size() > max.size()) ? dp[i] : max;
        }
        return max;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    Program::prettyPrint(obj.getLongestSubsequence(words, groups));
    return 0;
}