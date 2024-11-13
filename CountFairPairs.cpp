// LeetCode 2563
#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

static vector<int> nums = { 0, 1, 7, 4, 4, 5 };
static int lower = 3;
static int upper = 6;
static vector<int> nums1 = { 1, 7, 9, 2, 5 };
static int lower1 = 11;
static int upper1 = 11;

namespace Solution {
    class Program {
        public:
            long long countFairPairs(vector<int>& nums, int lower, int upper);
    };

    long long Program::countFairPairs(vector<int>& nums, int lower, int upper) {
        long long numFairPairs = 0;
        for (int i=0; i<nums.size(); i++)
            for (int j=i+1 ; j<nums.size(); j++)
                if (nums[i] + nums[j] >= lower && nums[i] + nums[j] <= upper)
                    numFairPairs++;
        return numFairPairs;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.countFairPairs(nums, lower, upper) << endl;
    cout << obj.countFairPairs(nums1, lower1, upper1) << endl;
    return 0;
}