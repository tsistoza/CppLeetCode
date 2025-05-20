// LeetCode 153
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static vector<int> nums { 11,13,15,17 };

namespace Solution {
    class Program {
        public:
            int findMin(vector<int>& nums);
    };

    int Program::findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;

        while (left<right) {
            int mid = left + (right-left) / 2;
            if (nums[left] < nums[right]) {
                right = (nums[mid] > nums[left]) ? mid-1 : right;
                right = (nums[mid] <= nums[left]) ? mid : right;
                continue;
            }

            if (nums[left] > nums[right]) {
                left = (nums[mid] > nums[right]) ? mid+1 : left;
                left = (nums[mid] <= nums[right]) ? mid : left;
                continue;
            }
        }

        return nums[left];
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.findMin(nums) << endl;
    return 0;
}