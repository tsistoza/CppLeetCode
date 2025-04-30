// LeetCode 2302
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static vector<int> nums { 2, 1, 4, 3, 5 };
static int k = 10;

namespace Solution {
    class Program {
        public:
            long long countSubarrays(vector<int>& nums, int k);
    };

    long long Program::countSubarrays(vector<int>& nums, int k) {
        long long result = 0;
        
        int sum=0;
        for (int left=0,right=0; right<nums.size(); ) {
            if (nums[right] < k)
                result++;
            sum+=nums[right];

            if (sum * (right-left+1) >= k) {
                while (left < right) {
                    sum-=nums[left++];
                    if (sum * (right-left+1) < k) result += (right-left);
                }
                right++;
                continue;
            }

            result += (right-left);
            right++;
        }
        return result;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.countSubarrays(nums, k) << endl;
}