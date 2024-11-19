// LeetCode 2461
// Compile with -std=c++20
#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout, std::endl;
using std::vector, std::unordered_map;

static vector<int> nums { 1, 5, 4, 2, 9, 9, 9 };
static int k = 3;
static vector<int> nums1 { 4, 4, 4 };
static int k1 = 3;

namespace Solution {
    class Program {
        private:
            void GetAllSubarrays(vector<int>& nums, vector<vector<int>>& allSubarrays, int k);
        public:
            long long maximumSubarraySum(vector<int>& nums, int k);
        
    };
    
    void Program::GetAllSubarrays(vector<int>& nums, vector<vector<int>>& allSubarrays, int k) {
        vector<int> subarray;
        unordered_map<int, int> map; // map used to check if subarray is distinct

        // ith element will always be the first element of each subarray
        for (int i=0; i<nums.size(); i++) {
            for (int j=i; j<nums.size(); j++) { // jth element will tell us the size of the subarray
                int dupe;
                for (int l=i; l<=j; l++) { // lth element are the elements in the subarray aside from the first
                    if (map.contains(nums[l])) {
                        dupe = nums[l];
                        map[nums[l]]++;
                        break;
                    }
                    else map.insert({nums[l], 1});
                    subarray.push_back(nums[l]);
                }
                if (subarray.size() > k || map[dupe] > 1) break;
                if (subarray.size() == k) allSubarrays.push_back(vector<int> (subarray));
                subarray.clear();
                map.clear();
            }
            subarray.clear();
            map.clear();
        }
        return;
    }


    long long Program::maximumSubarraySum(vector<int>& nums, int k) {
        vector<vector<int>> allSubarrays;
        this->GetAllSubarrays(nums, allSubarrays, k);
        long long sum=0;
        for(vector<int> subarray : allSubarrays) {
            long long tempSum = 0;
            for(int i : subarray) tempSum += i;
            sum = (sum < tempSum) ? tempSum : sum;
        }
        return sum;
    }
}

int main () {
    using namespace Solution;
    Program obj;
    cout << obj.maximumSubarraySum(nums, k) << endl;
    cout << obj.maximumSubarraySum(nums1, k1) << endl;
    return 0;
}