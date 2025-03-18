// LeetCode 268
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static vector<int> nums { 3, 0, 1 };

namespace Solution {
    class Program {
        public:
            int missingNumber(vector<int>& nums);
    };

    int Program::missingNumber(vector<int>& nums) {
        int sum = 0;
        for (int i=1; i<=nums.size(); i++)
            sum += i;
        
        int numSum = 0;
        for (int i=0; i<=nums.size(); i++)
            numSum += nums[i];

        return sum - numSum;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.missingNumber(nums) << endl;
    return 0;
}