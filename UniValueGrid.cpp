// LeetCode 2033
#include <iostream>
#include <vector>
#include <algorithm>


using std::cout, std::endl, std::vector;
using std::sort, std::abs;

static vector<vector<int>> grid { { 7, 10 }, { 13, 16 } };
static int x = 3;

namespace Solution {
    class Program {
        public:
            int minOperations(vector<vector<int>>& grid, int x);
    };

    int Program::minOperations(vector<vector<int>>& grid, int x) {
        if (grid.size() == 1 && grid[0].size() == 1) return 0;

        vector<int> nums;
        for (int i=0; i<grid.size(); i++)
            for (int j=0; j<grid[i].size(); j++)
                nums.push_back(grid[i][j]);
        
        sort(nums.begin(), nums.end());
        int median;
        if (nums.size() % 2) median = nums[nums.size()/2];
        else median = (nums[nums.size()/2] + nums[(nums.size()/2)-1]) / 2;

        int ops = 0;
        median -= abs(nums[0] - median) % x;
        for (int i=0; i<nums.size(); i++) {
            if (abs(nums[i] - median) % x > 0) return -1;
            ops += abs(nums[i]-median)/x;
        }

        return ops;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.minOperations(grid,x) << endl;
}