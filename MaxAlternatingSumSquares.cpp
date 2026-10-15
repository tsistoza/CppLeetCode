// LeetCode 3727
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::cout, std::endl, std::vector, std::sort, std::abs;

static vector<int> nums { 1,-1,2,-2,3,-3 };

namespace Solution {
    class Compare {
        public:
            bool operator()(const int& a, const int& b) const {
                return abs(a) < abs(b);
            }
    };
    class Program {
        private:
            void prettyPrint(vector<int>& nums);
        public:
            long long maxAlternatingSum(vector<int>& nums);
    };

    void Program::prettyPrint(vector<int>& nums) {
        cout << "{ ";
        for (int i : nums) cout << i << " ";
        cout << "}" << endl;
    }

    long long Program::maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), Compare());
        //prettyPrint(nums);
        int left = 0, right = nums.size() - 1;
        long long sum = 0;
        bool alternate = false;
        while (left <= right) {
            if (alternate)
                sum -= (nums[left] * nums[left++]);

            if (!alternate)
                sum += (nums[right] * nums[right--]);

            alternate = !alternate;
        }

        return sum;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.maxAlternatingSum(nums) << endl;
    return 0;
}