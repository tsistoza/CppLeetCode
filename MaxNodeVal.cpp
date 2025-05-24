// LeetCode 3068
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector;
using std::sort, std::reverse;

static vector<int> nums { 1, 2, 1 };
static int k = 3;
static vector<vector<int>> edges { { 0, 1 }, { 0, 2 } };

namespace Solution {
    class Program {
        public:
            long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges);
    };

    long long Program::maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        vector<int> gain(nums.size(), 0);
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
            int newVal = nums[i] ^ k;
            gain[i] = newVal - nums[i];
        }

        sort (gain.begin(), gain.end());
        reverse (gain.begin(), gain.end());
        for (int i=0; i<gain.size()-1; i+=2) {
            if (gain[i] + gain[i+1] <= 0) break;
            sum += gain[i] + gain[i+1];
        }
        
        return sum;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.maximumValueSum(nums, k, edges) << endl;
    return 0;
}