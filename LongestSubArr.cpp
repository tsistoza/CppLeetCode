// LeetCode 1493
#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

static vector<int> nums { 1, 1, 0, 1 };
static vector<int> nums1 { 0, 1, 1, 1, 0, 1, 1, 0, 1 };
static vector<int> nums2 { 1, 1, 1 };

namespace Solution {
    class Program {
        public:
            int longestSubarray(vector<int>& nums);
    };
    int Program::longestSubarray(vector<int>& nums) {
        int max = 0;
        int countZeros = 0;
        vector<int> subarray;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) countZeros++;
            subarray.push_back(i);
            for (int j=i+1; j<nums.size(); j++) {
                if (nums[j] == 0) countZeros++;
                if (countZeros > 1) break;
                subarray.push_back(j);
            }
            max = (max < (int) subarray.size()) ? subarray.size() : max;
            if (max == nums.size()) return max-1;
            subarray.clear();
            countZeros = 0;
        }
        return max-1;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.longestSubarray(nums)  << endl;
    cout << obj.longestSubarray(nums1) << endl;
    cout << obj.longestSubarray(nums2) << endl;
    return 0;
}