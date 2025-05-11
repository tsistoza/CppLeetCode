// LeetCode 2918
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector;
using std::max;

static vector<int> nums1 { 3, 2, 0, 1, 0 };
static vector<int> nums2 { 6, 1 };

namespace Solution {
    class Program {
        public:
            long minSum(vector<int>& nums1, vector<int>& nums2);
    };

    long Program::minSum(vector<int>& nums1, vector<int>& nums2) {
        int countZero1 = 0, sum1 = 0;
        int countZero2 = 0, sum2 = 0;

        for (int i : nums1) {
            if (i == 0) {
                countZero1++; 
                sum1++;
                continue;
            }
            sum1 += i;
        }

        for (int i : nums2) {
            if (i == 0) {
                countZero2++;
                sum2++;
                continue;
            }
            sum2 += i;
        }

        if (countZero1 > 0 && countZero2 > 0) return max(sum1, sum2);
        if (countZero1 > 0 && countZero2 == 0) return (sum1 < sum2) ? sum2 : -1;
        if (countZero1 == 0 && countZero2 > 0) return (sum1 > sum2) ? sum1 : -1;
        return (sum1 == sum2) ? sum1 : -1;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.minSum(nums1, nums2) << endl;
    return 0;
}