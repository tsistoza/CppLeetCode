// LeetCode 2089
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector;

static vector<int> nums { 100, 1, 100 };
static int target = 100;

namespace Solution {
    class Program {
        private:
            static void prettyPrint(vector<int>& result);
        public:
            vector<int> targetIndices(vector<int>& nums, int target);
    };

    void Program::prettyPrint(vector<int>& result) {
        cout << "{ ";
        for (int i : result) cout << i << " ";
        cout << "}\n" << endl;
        return;
    }

    vector<int> Program::targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());

        int low = 0;
        int high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) high = mid - 1;
            else low = mid + 1;
        }

        if (low == n-1 && nums[low] != target) return vector<int>();
        if (nums[low] != target && nums[low+1] != target) return vector<int>();
        if (nums[low] < target) low++;

        int ptr1 = low, ptr2 = low;
        while (nums[ptr1] == target && ptr1 > 0) ptr1--;
        while (nums[ptr2] == target && ptr2 < n-1) ptr2++;


        if (nums[ptr1] != target) ptr1++;
        if (nums[ptr2] != target) ptr2--;
        
        vector<int> result(ptr2 - ptr1 + 1, 0);
        for (int i=0; i<result.size(); i++, ptr1++) result[i] = ptr1;

        return result;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    obj.targetIndices(nums, target);
}