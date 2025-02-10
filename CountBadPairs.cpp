// LeetCode 2364
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static vector<int> nums { 4, 1, 3, 3 };
static vector<int> nums1 { 1, 2, 3, 4, 5 };

namespace Solution {
    class Program {
        public:
            long long countBadPairs(vector<int>& nums);
    };

    long long Program::countBadPairs(vector<int>& nums) {
        long long count = 0;
        for (int i=0; i<nums.size(); i++)
            for (int j=i+1; j<nums.size(); j++)
                if (j - i != nums[j] - nums[i]) count++;

        return count;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.countBadPairs(nums) << endl;
    cout << obj.countBadPairs(nums1) << endl;
    return 0;
}