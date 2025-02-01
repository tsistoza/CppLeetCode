// LeetCode 3151
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static vector<int> nums { 1 };
static vector<int> nums1 { 2, 1, 4 };
static vector<int> nums2 { 4, 3, 1, 6 };

namespace Solution {
    class Program {
        public:
            bool isArraySpecial(vector<int>& nums);
    };

    bool Program::isArraySpecial(vector<int>& nums) {
        if (nums.size() == 1) return true;

        for (int i=0; i<nums.size()-1; i++) {
            if (nums[i] % 2 && nums[i+1] % 2) return false;
            if (!(nums[i] % 2) && !(nums[i+1] % 2)) return false;
        }

        return true;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.isArraySpecial(nums) << endl;
    cout << obj.isArraySpecial(nums1) << endl;
    cout << obj.isArraySpecial(nums2) << endl;
    return 0;
}