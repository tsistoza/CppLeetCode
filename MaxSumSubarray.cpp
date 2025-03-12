// LeetCode 1749
#include <iostream>
#include <vector>
#include <cmath>

using std::cout, std::endl, std::vector;
using std::abs, std::max;

static vector<int> nums { 2, -5, 1, -4, 3, -2 };

namespace Solution {
    class Program {
        public:
            int maxAbsoluteSum(vector<int>& nums);
    };

    int Program::maxAbsoluteSum(vector<int>& nums) {
        int sum = INT_MIN;

        for (int i=0; i<nums.size(); i++) {
            int currSum = 0;
            for (int j=i+1; j<nums.size(); j++) {
                currSum += nums[j];
                sum = max(sum, abs(currSum));
            }
        }
        return sum;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.maxAbsoluteSum(nums) << endl;
    return 0;
}