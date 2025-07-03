// LeetCode 594
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector;
using std::min, std::max, std::sort;

static vector<int> nums { 1, 1, 1, 1 };

namespace Solution {
    class Program {
        public:
            int findLHS(vector<int>& nums);
    };

    int Program::findLHS(vector<int>& nums) {
        int length = 0, start=0;
        sort(nums.begin(), nums.end());
        for (int i=0, nextPos=0; i<nums.size();) { // O(n) were just using two ptrs, i and start
            if (nums[i] - nums[start] == 1) {
                length = max(length, i-start+1);
                nextPos = ((nums[i] - nums[i-1]) == 1) ? i : nextPos;
            }
            if (nums[i] - nums[start] > 1)
                start = nextPos;
            i++;
        }
        return length;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.findLHS(nums) << endl;
    return 0;
}