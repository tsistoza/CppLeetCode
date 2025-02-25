// LeetCode 962
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector;
using std::max;

static vector<int> nums { 6, 0, 8, 2, 1, 5 };
static vector<int> nums1 { 9, 8, 1, 0, 1, 9, 4, 0, 4, 1 };

namespace Solution {
    class Program {
        public:
            int maxWidthRamp(vector<int>& nums);
    };

    int Program::maxWidthRamp(vector<int>& nums) {
        int width = INT_MIN;
        for (int i=0; i<nums.size(); i++) {
            for (int j=i+1; j<nums.size(); j++) {
                if (nums[i] > nums[j]) continue;
                width = max(width, j - i);
            }
        }
        return width;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.maxWidthRamp(nums) << endl;
    cout << obj.maxWidthRamp(nums1) << endl;
    return 0;
}