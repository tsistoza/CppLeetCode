// LeetCode 3689
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector, std::max, std::min;

static vector<int> nums { 4, 2, 5, 1 };
static int k = 3;

namespace Solution {
    class Program {
        public:
            long long maxTotalValue(vector<int>& nums, int k);
    };

    long long Program::maxTotalValue(vector<int>& nums, int k) {
        int maxElement = INT_MIN;
        int minElement = INT_MAX;
        for (int i : nums) {
            maxElement = max(i, maxElement);
            minElement = min(i, minElement);
        }


        return (maxElement - minElement) * k;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.maxTotalValue(nums, k) << endl;
    return 0;
}