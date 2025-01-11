// LeetCode 45
#include <iostream>
#include <vector>

using std::cout,std::endl;
using std::vector;

static vector<int> nums { 2, 3, 1, 1, 4 };
static vector<int> nums1 { 2, 3, 0, 1, 4 };

namespace Solution {
    class Program {
        private:
            void dfs(int jumps, int index, vector<int>& nums, vector<int>& dp);
        public:
            int jump(vector<int>& nums);
    };

    void Program::dfs(int jumps, int index, vector<int>& nums, vector<int>& dp) {
        if (index >= nums.size()) return;
        dp[index] = (dp[index] > jumps) ? jumps : dp[index];
        for (int i=1; i<=nums[index]; i++) {
            if (index+i > nums.size()-1) break;
            dfs(jumps+1, index+i, nums, dp);
        }
        return;
    }

    int Program::jump(vector<int>& nums) {
        vector<int> dp(INT_MAX, nums.size());
        dp[0] = 0;
        dfs(0, 0, nums, dp);
        return dp[nums.size()-1];
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.jump(nums) << endl;
    cout << obj.jump(nums1) << endl;
    return 0;
}