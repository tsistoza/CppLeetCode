// LeetCode 81
#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

static vector<int> nums { 2, 5, 6, 0, 0, 1, 2 };
static int target = 0;
static vector<int> nums1 { 2, 5, 6, 0, 0, 1, 2 };
static int target1 = 3;

namespace Solution {
    class Program {
        public:
            bool search(vector<int>& nums, int target);
    };

    bool Program::search(vector<int>& nums, int target) {
        for (int i=0,j=nums.size()-1; (i<j); i++,j--)
            if (nums[i] == target || nums[j] == target) return true;
        return false;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.search(nums, target) << endl;
    cout << obj.search(nums1, target1) << endl;
    return 0;
}