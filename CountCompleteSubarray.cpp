// LeetCode 2799
#include <iostream>
#include <vector>
#include <unordered_set>

using std::cout, std::endl, std::vector;
using std::unordered_set;

static vector<int> nums { 42 };

namespace Solution {
    class Program {
        private:
            bool isDistinct(int distinct, int& windowSize, vector<int>& nums, int index);
        public:
            int countCompleteSubarrays(vector<int>& nums);
    };

    bool Program::isDistinct(int distinct, int& windowSize, vector<int>& nums, int index) {
        unordered_set<int> set;
        for (int i=index; i<nums.size(); i++) {
            if (!set.contains(nums[i])) set.insert(nums[i]);
            if (set.size() == distinct) {
                windowSize = i-index+1;
                return true;
            }
        }
        return false;
    }

    int Program::countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> distinct;
        for (int i : nums) 
            if (!distinct.contains(i))
                distinct.insert(i);

        int count = 0;
        for (int i=0; i<nums.size(); i++) {
            int windowSize = distinct.size();
            if (isDistinct(distinct.size(), windowSize, nums, i))
                count += nums.size() - i - windowSize + 1;
        }
        return count;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.countCompleteSubarrays(nums) << endl;
}