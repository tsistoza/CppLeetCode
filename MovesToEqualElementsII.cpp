// LeetCode 462
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using std::cout, std::endl, std::vector;

static vector<int> nums { 1, 10, 2, 9 };

namespace Solution {
    class Program {
        public:
            int minMoves2(vector<int>& nums);
    };

    int Program::minMoves2(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        std::sort(nums.begin(), nums.end());
        int median = 0;
        if (n % 2 == 0) median = (nums[n/2] + nums[(n/2)-1]) / 2;
        else median = nums[n/2];

        int minMoves = 0;
        for (int i=0; i<nums.size(); i++) minMoves += abs(nums[i] - median);
        return minMoves;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.minMoves2(nums) << endl;
    return 0;
}