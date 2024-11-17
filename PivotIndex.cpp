// LeetCode 724
#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

static vector<int> nums = { 1, 7, 3, 6, 5, 6 };
static vector<int> nums1 = { 1, 2, 3 };
static vector<int> nums2 = { 2, 1, -1 };

namespace Solution {
    class Program {
        public:
            int pivotIndex(vector<int>& nums);
    };

    int Program::pivotIndex(vector<int>& nums) {
        vector<int> leftSum(nums.size(), 0);
        vector<int> rightSum(nums.size(), 0);
        int sum=0;
        for (int i=1 ; i<nums.size(); i++)
            sum += nums[i];
        rightSum[0] = sum;

        for (int i=0; i<nums.size(); i++) {
            if (i < nums.size()-1) {
                leftSum[i+1] = leftSum[i] + nums[i];
                rightSum[i+1] = rightSum[i] - nums[i+1];
            }
            if (leftSum[i] == rightSum[i]) return i;
        }
        return -1;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.pivotIndex(nums) << endl;
    cout << obj.pivotIndex(nums1) << endl;
    cout << obj.pivotIndex(nums2) << endl;
    return 0;
}