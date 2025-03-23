// LeetCode 198
#include <iostream>
#include <vector>
#include <cmath>

using std::cout, std::endl, std::vector;
using std::max;

static vector<int> nums { 40, 2, 7, 6, 50 };

namespace Solution {
    class Program {
        public:
            int rob(vector<int>& nums);
    };

    int Program::rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);

        for (int i=0; i<nums.size(); i++) {
            if (i == 0 || i == 1) {
                dp[i] = nums[i];
                continue;
            }
            
            if (i == 2) {
                dp[i] = dp[i-2] + nums[i];
                continue;
            }
            dp[i] = max(dp[i-2], dp[i-3]) + nums[i];
        }

        return max(dp.back(), dp[dp.size()-2]);
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.rob(nums) << endl;
}