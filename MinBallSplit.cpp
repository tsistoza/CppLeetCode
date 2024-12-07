// LeetCode 1760
#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

static vector<int> nums { 9 };
static int maxOperations = 2;
static vector<int> nums1 { 2, 4, 8, 2 };
static int maxOperations1 = 4;
static vector<int> nums2 = { 1 };
static int maxOperations2 = 1;
static vector<int> nums3 = { 7, 10 };
static int maxOperations3 = 2;

namespace Solution {
    class Program {
        private:
            vector<int>::iterator findMax(vector<int>& nums);
        public:
            int minimumSize(vector<int>& nums, int maxOperations);
    };

    // Idea:, there is one specific pattern that you should look at for, and that is if there is one bag, we will call this the special case. (nums.size()==1)
    // Since we know the number of bags, (maxOperations+1), we can actually find the minimum possible penalty.
    // To do that, take the num of balls divided by numBags. Then check if there is a remainder, if so, then add 1 to answer.
    int Program::minimumSize(vector<int>& nums, int maxOperations) {
        if (nums.size() == 1) {
            int numBags = 1 + maxOperations;
            if (nums[0] < numBags) numBags = nums[0];
            int ans = ((int)nums[0]/numBags);
            if ((nums[0] % numBags) > 1) return ans+1;
            return ans;
        }

        // Very simple, find the Max in the set, split them evenly, repeat for however many operations
        for (int i=0; i<maxOperations; i++) {
            vector<int>::iterator max = findMax(nums);
            if (*max == 1) return 1;
            int numBalls = *max;
            nums.erase(max);
            int newBag = (int) numBalls / 2;
            nums.push_back(newBag);
            if (numBalls % 2) nums.push_back(newBag+1);
            else nums.push_back(newBag);
        }
        return *(findMax(nums));
    }

    vector<int>::iterator Program::findMax(vector<int>& nums) {
        vector<int>::iterator max=nums.begin();
        for (vector<int>::iterator it=nums.begin()+1; it!=nums.end(); it++)
            max = (*max < *it) ? it : max;
        return max;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.minimumSize(nums,maxOperations) << endl;
    cout << obj.minimumSize(nums1,maxOperations1) << endl;
    cout << obj.minimumSize(nums2,maxOperations2) << endl;
    cout << obj.minimumSize(nums3,maxOperations3) << endl;
    return 0;
}