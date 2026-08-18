// LeetCode 3471
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::cout, std::endl, std::vector, std::unordered_map, std::max;

static vector<int> nums { 0, 0 };
static int k = 1;

namespace Solution {
    class Program {
        public:
            int largestInteger(vector<int>& nums, int k);
    };

    int Program::largestInteger(vector<int>& nums, int k) {
        // It can either be the front, or the back, or neither
        // we just want to keep track of the front and back counts
        int back = nums.size() - 1;
        int start = 0, end = start + k - 1;
        unordered_map<int, int> dict;
        dict.insert({ nums[0], 0 });
        dict.insert({ nums[back], 0 });
        for (int i=start; i<end; i++) 
            if (dict.contains(nums[i])) dict[nums[i]]++;
        
        while (end < nums.size()) {
            if (dict[nums[0]] > 1 && dict[nums[back]] > 1) return -1;
            if (dict.contains(nums[end]))
                dict[nums[end]]++;
            
            start++;
            end++;
        }


        int largestMissingInteger = -1;
        if (dict[nums[0]] == 1) largestMissingInteger = nums[0];
        if (dict[nums[back]] == 1) largestMissingInteger = max(largestMissingInteger, nums[back]);
        return largestMissingInteger;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.largestInteger(nums, k) << endl;
    return 0;
}