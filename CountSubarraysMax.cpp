// LeetCode 2962
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::cout, std::endl, std::vector;
using std::unordered_map, std::min, std::sort;

static vector<int> nums { 1, 4, 2, 1 };
static int k = 2;

namespace Solution {
    class Program {
        public:
            long long countSubarrays(vector<int>& nums, int k);
    };

    long long Program::countSubarrays(vector<int>& nums, int k) {
        long long size = nums.size();
        long long count = size*(size+1) /2;
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int maxElem = sorted[nums.size()-1];
        sorted.clear();

        for (int left=0,right=0,numMax=0; right<nums.size();) {
            numMax += (maxElem == nums[right]) ? 1 : 0;
            if (numMax >= k) {
                while (nums[left] != maxElem) left++;
                left++;
                numMax--;
            }

            count -= (right-left)+1;
            right++;
        }
        return count;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.countSubarrays(nums, k) << endl;
}