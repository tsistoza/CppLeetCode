// LeetCode 704
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static vector<int> nums { -1, 0, 3, 5, 9, 12 };
static int target = 2;

namespace Solution {
    class Program {
        public:
            int search(vector<int>& nums, int target);
    };
    
    int Program::search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while (low <= high) {
            int middle = low + (high-low)/2;
            if (target == nums[middle]) return middle;
            if (target < nums[middle]) high = middle - 1;
            if (target > nums[middle]) low = middle + 1;
        }

        return -1;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.search(nums, target) << endl;
}