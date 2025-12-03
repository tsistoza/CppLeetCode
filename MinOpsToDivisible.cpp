// LeetCode 3512
#include <iostream>
#include <vector>
#include <numeric>

using std::cout, std::endl, std::vector;
using std::accumulate;

static vector<int> nums { 3, 2 };
static int k = 6;

namespace Solution {
    class Program {
        public:
            int minOperations(vector<int>& nums, int k);
    };

    int Program::minOperations(vector<int>& nums, int k) {
        return (accumulate(nums.begin(), nums.end(), 0) % k);
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.minOperations(nums, k) << endl;
    return 0;
}