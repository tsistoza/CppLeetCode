// LeetCode 862
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl;
using std::vector, std::sort;

static vector<int> nums = { 1 };
static int k = 1;
static vector<int> nums1 = { 1, 2 };
static int k1 = 4;
static vector<int> nums2 = { 2, -1, 2 };
static int k2 = 3;

namespace Solution {
    class Compare {
        public:
            bool operator()(vector<int> n1, vector<int> n2) const { return n1.size() < n2.size(); }
    };

    class Program {
        public:
            int shortestSubarray(vector<int>& nums, int k);
    };

    int Program::shortestSubarray(vector<int>& nums, int k) {
        vector<int> subarray;
        vector<vector<int>> allSubarrays;

        // Find all Subarrays with at sum = k
        for (int i=0; i<nums.size(); i++) {
            for (int j=i; j<nums.size(); j++) {
                int sum=0;
                for (int l=i; l<=j; l++) {
                    sum += nums[l];
                    subarray.push_back(nums[l]);
                    if (sum == k) allSubarrays.push_back(vector<int> (subarray));
                }
                subarray.clear();
            }
        }

        if (allSubarrays.size() == 0) return -1;

        // Sort subarrays by size
        Compare obj;
        sort(allSubarrays.begin(), allSubarrays.end(), obj);

        return allSubarrays.front().size();
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.shortestSubarray(nums, k) << endl;
    cout << obj.shortestSubarray(nums1, k1) << endl;
    cout << obj.shortestSubarray(nums2, k2) << endl;
    return 0;
}