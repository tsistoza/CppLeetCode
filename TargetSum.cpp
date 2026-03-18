// LeetCode 494
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::cout, std::endl, std::vector, std::max, std::abs;

static vector<int> nums { 12,25,42,49,41,15,22,34,28,31 };
static int target = 35;

namespace Solution {
    class Program {
        public:
            int findTargetSumWays(vector<int>& nums, int target);
    };

    int Program::findTargetSumWays(vector<int>& nums, int target) {
        int maxSum=0;
        for (int i : nums)
            maxSum += i;

        vector<vector<int>> dp(nums.size(), vector<int>(maxSum*2+1, 0));
        for (int index=0; index<nums.size(); index++) {
            for (int targetIndex=0; targetIndex<dp[0].size(); targetIndex++) {
                int currTarget = targetIndex - maxSum;
                if (index == 0) {
                    dp[index][targetIndex] = (abs(currTarget) == nums[index]) ? 1 : 0;
                    continue;
                }

                int prevTargetNeg = currTarget + nums[index]; 
                int prevTargetPos = currTarget - nums[index];

                int prevIndexNeg = prevTargetNeg + maxSum;
                int prevIndexPos = prevTargetPos + maxSum;

                #ifdef DEBUG
                cout << "Current Target = " << currTarget << endl;
                cout << "Looking for - " << prevTargetNeg << ", it is located at index=" << prevIndexNeg << endl;
                cout << "Looking for + " << prevTargetPos << ", it is located at index=" << prevIndexPos << endl;
                #endif

                if ((prevIndexNeg < 0 || prevIndexNeg >= maxSum*2) && (prevIndexPos < 0 || prevIndexPos >= maxSum*2))
                    continue;
                
                if (prevIndexNeg < 0 || prevIndexNeg >= maxSum*2)
                    dp[index][targetIndex] = max(dp[index][targetIndex], dp[index-1][prevIndexPos]);
                else if (prevIndexPos < 0 || prevIndexPos >= maxSum*2)
                    dp[index][targetIndex] = max(dp[index][targetIndex], dp[index-1][prevIndexNeg]);
                else
                    dp[index][targetIndex] = max(dp[index][targetIndex], dp[index-1][prevIndexNeg]+dp[index-1][prevIndexPos]);
                
                #ifdef DEBUG
                cout << "dp[" << index << "][" << targetIndex << "] = " << dp[index][targetIndex] << "\n\n" << endl;
                #endif
            }
        }

        return dp[nums.size()-1][target+maxSum];
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.findTargetSumWays(nums, target) << endl;
    return 0;
}