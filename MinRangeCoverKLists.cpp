// LeetCode 632
#include <iostream>
#include <vector>
#include <utility>

using std::cout, std::endl, std::vector;
using std::pair, std::max, std::min;

static vector<vector<int>> nums { { 4, 10, 15, 24, 26 }, { 0, 9, 12, 20 }, { 5, 18, 22, 30 } };
static vector<vector<int>> nums1 { { 1, 2, 3 }, { 1, 2, 3 }, { 1, 2, 3 } };

namespace Solution {
    class Program {
        private:
            pair<int,int> findMinRange(pair<int,int> i, pair<int,int> j);
            int findMax (vector<vector<int>>& nums, vector<int>& ptrs);
            pair<int,int> findMinIndex(vector<int>& ptrs, vector<vector<int>>& nums);
        public:
            pair<int,int> smallestRange(vector<vector<int>>& nums);
    };

    pair<int,int> Program::findMinRange(pair<int,int> i, pair<int,int> j) {
        int differenceI = i.second - i.first;
        int differenceJ = j.second - j.first;
        if (differenceI < differenceJ) return i;
        if (differenceI == differenceJ) {
            if (i.first < j.first) return i;
            else return j;
        } 
        return j;
    }

    int Program::findMax(vector<vector<int>>& nums, vector<int>& ptrs) {
        int maxNum = INT_MIN;
        for (int i=0; i<ptrs.size(); i++)
            maxNum = max(maxNum, nums[i][ptrs[i]]);
        return maxNum;
    }

    pair<int,int> Program::findMinIndex(vector<int>& ptrs, vector<vector<int>>& nums) {
        pair<int,int> minIndex;
        int min = INT_MAX;

        for (int i=0; i<ptrs.size(); i++) {
            if (nums[i][ptrs[i]] < min) {
                minIndex = { i, ptrs[i] };
                min = nums[i][ptrs[i]];
            }
        }
        return minIndex;
    }

    pair<int,int> Program::smallestRange(vector<vector<int>>& nums) {
        pair<int,int> range;
        
        vector<int> ptrs;
        for (int i=0; i<nums.size(); i++)
            ptrs.push_back(0);

        int maxNum = findMax(nums, ptrs);
        pair<int, int> kIndexMin = findMinIndex(ptrs, nums);
        range = { nums[kIndexMin.first][kIndexMin.second], maxNum };
        while (true) {
            ptrs[kIndexMin.first]++;
            if (ptrs[kIndexMin.first] > nums[kIndexMin.first].size()-1) break;
            
            maxNum = findMax(nums, ptrs);
            kIndexMin = findMinIndex(ptrs, nums);
            range = findMinRange(range, {nums[kIndexMin.first][kIndexMin.second], maxNum} );

        }
        return range;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    pair<int,int> ans = obj.smallestRange(nums);
    cout << ans.first << " " << ans.second << endl;
    ans = obj.smallestRange(nums1);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}