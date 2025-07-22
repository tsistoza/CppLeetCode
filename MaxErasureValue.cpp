// LeetCode 1695
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::cout, std::endl, std::vector;
using std::unordered_map, std::max;

static vector<int> nums { 5,2,1,2,5,2,1,2,5 };

namespace Solution {
    class Program {
        public:
            int maximumUniqueSubarray(vector<int>& nums);
    };

    int Program::maximumUniqueSubarray(vector<int>& nums) {
        int maxErasureVal = 0;
        unordered_map<int,int> dict;
        for (int i=0, window=0, erasureVal=0; i<nums.size();) {
            dict[nums[i+window]]++;
            if (dict[nums[i+window]] > 1 || i+window>=nums.size()) {
                window=0;
                i++;
                erasureVal=0;
                dict.clear();
                continue;
            }
            erasureVal += nums[i+window];
            window++;
            maxErasureVal = max(erasureVal, maxErasureVal);
        }

        return maxErasureVal;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.maximumUniqueSubarray(nums) << endl;
    return 0;
}