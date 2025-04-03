// LeetCode 2874
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector;
using std::max;

static vector<int> nums { 1, 2, 3 };

namespace Solution {
    class Program {
        public:
            long long maximumTripletValue(vector<int>& nums);
    };

    long long Program::maximumTripletValue(vector<int>& nums) {
        long long maxElement = LLONG_MIN;
        long long maxDifference = LLONG_MIN;
        long long maxTripletValue = LLONG_MIN;

        for (int j=0; j<nums.size(); j++) {
            maxTripletValue = max(maxTripletValue, maxDifference * nums[j]);
            maxElement = max(maxElement, (long long) nums[j]);
            maxDifference = max(maxDifference, maxElement - nums[j]);
        }

        if (maxTripletValue < 0) return 0;
        return maxTripletValue;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.maximumTripletValue(nums) << endl;
}