// Leetcode 898
// Note when compiling make sure to use standard C++20
#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout, std::endl;
using std::vector, std::unordered_map;

static vector<int> nums1 = { 0 };
static vector<int> nums2 = { 1, 1, 2 };
static vector<int> nums3 = { 1, 2, 4 };

namespace Solution {
    class Program {
        public:
            int subArrayBitwiseORs(vector<int>& nums);
            void findAllSubArrays(vector<int>& nums, vector<vector<int>>& allSubArrays);
    };

    int Program::subArrayBitwiseORs(vector<int>& nums) {
        vector<vector<int>> allSubArrays;
        vector<int> subarray;
        this->findAllSubArrays(nums, allSubArrays);

        // Store the values into a map (subarrayvalue, count) where count is the number of times that value occurred
        unordered_map<int, int> subArrayValues;

        for(auto it=allSubArrays.begin(); it!=allSubArrays.end(); it++) {
            int bitOrSubArray=0;
            for (vector<int>::iterator it2=it->begin(); it2!=it->end(); it2++)
                bitOrSubArray |= *it2;
            if (subArrayValues.contains(bitOrSubArray)) subArrayValues[bitOrSubArray]++; // check if map contains value, if so, then increment count
            else subArrayValues.insert({bitOrSubArray, 1});                                // else insert unique value into map
        }
        return subArrayValues.size();
    }
    void Program::findAllSubArrays(vector<int>& nums, vector<vector<int>>& allSubArrays) 
    {
        vector<int> subarray;
        for (int i=0; i<nums.size(); i++) {
            for (int j=i; j<nums.size(); j++){
                for (int k=i; k<=j; k++) subarray.push_back(nums[k]);
                allSubArrays.push_back(vector<int> (subarray));
                subarray.clear();
            }
        }
        return;
    }

}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.subArrayBitwiseORs(nums1) << endl;
    cout << obj.subArrayBitwiseORs(nums2) << endl;
    cout << obj.subArrayBitwiseORs(nums3) << endl;
    return 0;
}