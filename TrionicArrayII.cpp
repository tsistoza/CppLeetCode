// Leetcode 3640
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector, std::max;

static vector<int> nums { 1,4,2,7 };

namespace Solution {
    class Program {
        public:
            long long maxSumTrionic(vector<int>& nums);
    };

    long long Program::maxSumTrionic(vector<int>& nums) {
        vector<long long> dp1(nums.size(), INT_MIN);
        vector<long long> dp2(nums.size(), INT_MIN);
        vector<long long> dp3(nums.size(), INT_MIN);

        long long maxSum = INT_MIN;
        long long sum = nums[0];
        int mode = 0, prevMode = 0;
        for (int i=1; i<nums.size(); i++) {
            mode = (nums[i-1] > nums[i]) ? 2 : 1;
            if (prevMode != 0 && prevMode != mode) {
                sum = 0;
                prevMode = mode;
            }

            sum += nums[i];
            if (mode == 1) {
                dp1[i] = max(dp1[i-1], sum);
                dp3[i] = max(dp2[i-1], dp3[i-1]) + nums[i];
                maxSum = max(dp3[i], maxSum);
            } 
            else if (mode == 2) 
                dp2[i] = max(dp1[i-1], dp2[i-1]) + nums[i];
            

            //cout << "dp1[" << i << "]=" << dp1[i] << ", dp2[" << i << "]=" << dp2[i] << ", dp3[" << i << "]=" << dp3[i] << endl;
        }
        return maxSum;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.maxSumTrionic(nums) << endl;
    return 0;
}
