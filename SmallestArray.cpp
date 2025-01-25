// LeetCode 2948
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using std::cout, std::endl, std::vector;
using std::sort, std::unordered_map, std::unordered_set;

static vector<int> nums = { 1, 5, 3, 9, 8 };
static int limit = 2;
static vector<int> nums1 = { 1, 7, 6, 18, 2, 1 };
static int limit1 = 3;
static vector<int> nums2 = { 1, 7, 28, 19, 10 };
static int limit2 = 3;

namespace Solution {
    class Program {
        public:
            vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit);
    };

    vector<int> Program::lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sorted(nums);
        unordered_set<int> doNotTouch;
        unordered_map<int, vector<int>> places;
        sort(sorted.begin(), sorted.end());

        // init dict
        for (int i=0; i<nums.size(); i++)
            places[nums[i]].push_back(i);

        // we will be using the sorted array to find the smallest at the current position
        int numsPtr = 0, sortedPtr = 0;
        while (numsPtr < nums.size()) {

            // if sortedPtr reaches end, this is the smallest number possible at this position
            if (sortedPtr >= nums.size()) {
                sortedPtr = 0;
                doNotTouch.insert(numsPtr);
                numsPtr++;
            }

            // This is the smallest number at this position, do not touch this again
            if (numsPtr == sortedPtr && nums[numsPtr] == sorted[sortedPtr]) {
                doNotTouch.insert(numsPtr);
                sortedPtr++;
                numsPtr++;
                continue;
            }

            bool flag = false;
            if (abs(nums[numsPtr]-sorted[sortedPtr]) <= limit) { // check if able to swap
                for (int i : places[sorted[sortedPtr]]) {
                    if (doNotTouch.contains(i)) continue;        // if index being swapped have been moved already do not swap
                    int temp = nums[numsPtr];                    // otherwise proceed the swap
                    nums[numsPtr] = nums[i];
                    nums[i] = temp;
                    doNotTouch.insert(numsPtr);                  // do not touch this position again, as its the smallest number
                    flag = true;
                    break;
                }
            }
            
            if (!flag) {
                sortedPtr++;
                continue;
            }

            doNotTouch.insert(numsPtr);
            numsPtr++;
            sortedPtr = 0;
        } 
        return nums;
    }
}

int main() {
    using namespace Solution;
    Program obj;

    for (int i : obj.lexicographicallySmallestArray(nums, limit))
        cout << i << " ";
    cout << endl;

    for (int i : obj.lexicographicallySmallestArray(nums1, limit1))
        cout << i << " ";
    cout << endl;

    for (int i : obj.lexicographicallySmallestArray(nums2, limit2))
        cout << i << " ";
    cout << endl;
    return 0;
}