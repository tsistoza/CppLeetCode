// LeetCode 3337
// Part 1: https://github.com/tsistoza/CSharpLeetCodes/blob/main/TotalCharsAfterTransformI/TotalCharsAfterTransformI.cs
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using std::cout, std::endl, std::vector;
using std::string, std::accumulate;

static string s = "azbk";
static int t = 1;
static vector<int> nums { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 };

namespace Solution {
    class Program {
        public:
            int lengthAfterTransformations(string s, int t, vector<int>& nums);
    };

    int Program::lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int mod = 100000007;
        vector<vector<int>> offsets(26, vector<int>());
        vector<int> dp(26, 0);
        for (char c : s)
            dp[c - 'a']++;
        for (int i=0; i<26; i++) {
            for (int offset=1; offset<=nums[i]; offset++) {
                int character = i + offset;
                if (character > 25) character-=26;
                offsets[character].push_back(i);
            }
        }
        

        for (int i=0; i<t; i++) {
            vector<int> newDp(26, 0);
            for (int j=0; j<26; j++) {
                int count = 0;
                for (int character : offsets[j])
                    count += dp[character];
                newDp[j] = count % mod;
            }
            dp = newDp;
        }

        return (accumulate(dp.begin(), dp.end(), 0) % mod);
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.lengthAfterTransformations(s, t, nums) << endl;
    return 0;
}