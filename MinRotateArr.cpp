// LeetCode 153
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static vector<int> nums { 3,4,5,1,2 };

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
                right = (nums[mid] > nums[left]) ? mid-1 : mid;
                continue;
            }

            if (nums[left] > nums[right]) {
                left = (nums[mid] > nums[right]) ? mid+1 : mid;
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