// LeetCode 2419
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl;
using std::vector, std::sort;

static vector<int> nums { 1, 2, 3, 3, 2, 2 };
static vector<int> nums1 { 1, 2, 3, 4 };

namespace Solution {
    class Compare {
        private:
            int bitwise(vector<int> subarray);
        public:
            bool operator()(vector<int>& a, vector<int>& b);
    };
    class Program {
        private:
            void getAllSubarrays(vector<int> subarray, vector<vector<int>>& subarrays, vector<int>& nums, int index);
        public:
            int longestSubarray(vector<int>& nums);
    };

    bool Compare::operator()(vector<int>& a, vector<int>& b) {
        if (bitwise(a) < bitwise(b)) return true;
        else if (bitwise(a) > bitwise(b)) return false;

        if (a.size() < b.size()) return true;
        else return false;
    }

    int Compare::bitwise(vector<int> subarray) {
        int count = *(subarray.begin());
        for (vector<int>::iterator it = subarray.begin(); it != subarray.end(); it++)
            count &= (*it);
        return count;
    }

    void Program::getAllSubarrays(vector<int> subarray, vector<vector<int>>& subarrays, vector<int>& nums, int index) {
        if (subarray.size() > 0)
            subarrays.push_back(vector<int> (subarray));
        if (index > nums.size()-1) return;
        
        // Add last
        vector<int> temp1(subarray);
        temp1.push_back(nums[index]);
        getAllSubarrays(vector<int> (temp1), subarrays, nums, index+1);

        if (subarray.size() == 0) return;

        // Remove last
        vector<int> temp(subarray);
        temp.pop_back();
        temp.push_back(nums[index]);
        getAllSubarrays(vector<int> (temp), subarrays, nums, index+1);
        return;
    }

    int Program::longestSubarray(vector<int>& nums) {
        vector<vector<int>> subarrays;
        getAllSubarrays(vector<int>(), subarrays, nums, 0);
        Compare cmp;
        sort(subarrays.begin(), subarrays.end(), cmp);
        return subarrays.back().size();
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.longestSubarray(nums) << endl;
    cout << obj.longestSubarray(nums1) << endl;
    return 0;
}