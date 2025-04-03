// LeetCode 2873
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector;
using std::max;

static vector<int> nums { 1, 2, 3 };

namespace Solution {
    class Program {
        private:
            void getSubsets(long long* ans, vector<int>& nums, vector<int> subset, int index);
        public:
            long long maximumTripletValue(vector<int>& nums);
    };

    void Program::getSubsets(long long* ans, vector<int>& nums, vector<int> subset, int index) {
        if (subset.size() == 3) {
            long long curr = (nums[subset[0]] - nums[subset[1]]) * nums[subset[2]];
            *ans = max(*ans, curr);
            return;
        }

        if (subset.size() == 0) {
            for (int i=index; i<nums.size()-3; i++)
                getSubsets(ans, nums, vector<int> {i}, i+1);
        }
        
        for (int i=index; i<nums.size(); i++) {
            vector<int> newSubset(subset);
            newSubset.push_back(i);
            getSubsets(ans, nums, newSubset, i+1);
        }
        
        return;
    }

    // 2874 is more optimized version of this
    // https://github.com/tsistoza/CppLeetCode/blob/main/ValueOfTripletII.cpp
    long long Program::maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        long long* ansPtr = &ans;

        getSubsets(ansPtr, nums, vector<int> (), 0);

        if (ans < 0) return 0;
        return ans;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.maximumTripletValue(nums) << endl;
}