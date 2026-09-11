// LeetCode 3471
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using std::cout, std::endl, std::vector, std::unordered_map, std::max, std::map;

static vector<int> nums { 3, 9, 7, 2, 1, 7 };
static int k = 4;

namespace Solution {
    class Program {
        public:
            int largestInteger(vector<int>& nums, int k);
    };

    int Program::largestInteger(vector<int>& nums, int k) {
        // It can either be the front, or the back, or neither
        // we just want to keep track of the front and back counts
        int largestMissingInteger = -1;
        if (nums.size() == k) {
            for (int i=0; i<nums.size(); i++)
                largestMissingInteger = max(largestMissingInteger, nums[i]);
            return largestMissingInteger;
        }

        int back = nums.size() - 1;
        int start = 0;

        if (k == 1) {
            map<int, int> order;
            for (int i=0; i<=back; i++)
                order[nums[i]]++;
            for (map<int,int>::reverse_iterator itr = order.rbegin(); itr != order.rend(); itr++)
                if (itr->second == 1) return itr->first;
            return largestMissingInteger;
        }
        
        unordered_map<int, int> dict;
        dict[nums[0]]++;
        dict[nums[back]]++;

        for (int i=start+1; i<back; i++) {
            if (dict.contains(nums[i])) dict[nums[i]]++;
            if (dict[nums[0]] > 1 && dict[nums[back]] > 1) return -1;
        }

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