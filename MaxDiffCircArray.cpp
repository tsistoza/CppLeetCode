// LeetCode 3423
#include <iostream>
#include <vector>
#include <cmath>

using std::cout, std::endl, std::vector;
using std::abs;

static vector<int> nums { -5, -10, -5 };

namespace Solution {
    class Program {
        public:
            int maxAdjacentDistance(vector<int>& nums);
    };

    int Program::maxAdjacentDistance(vector<int>& nums) {
        int difference = INT_MIN;
        int newDiff;
        nums.push_back(nums[0]);
        for (int i=0; i<nums.size()-1; i++) {
            int newDiff = abs(nums[i]-nums[i+1]);
            if (newDiff > difference) difference = newDiff;
        }
        return difference;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.maxAdjacentDistance(nums) << endl;
    return 0;
}
