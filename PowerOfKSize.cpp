// LeetCode 3254
// compile with -std=c++20
#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout, std::endl;
using std::vector, std::unordered_map;

static vector<int> nums = { 1, 2, 3, 4, 3, 2, 5 };
static int k = 3;

namespace Solution {
    class Program {
        public:
            vector<int> resultsArray(vector<int>& nums, int k);
            void getAllSubArrays(vector<int>& nums, vector<vector<int>>& allSubarrays, int k);
    };

    vector<int> Program::resultsArray(vector<int>& nums, int k) {
        vector<int> result;
        vector<vector<int>> allSubarrays;
        vector<int> subarray;
        this->getAllSubArrays(nums, allSubarrays, k);

        for(auto it=allSubarrays.begin(); it!=allSubarrays.end(); it++) {
            int ans;
            unordered_map<int,int> map;
            for (vector<int>::iterator it2=it->begin(); it2!=it->end(); it2++) {
                if (it2 == it->begin()) {
                    ans = *it2;
                    map.insert({*it2, 1});
                    continue;
                }
                if(*(it2-1) > *it2 || map.contains(*it2)) { // If not power array append -1 to result
                    result.push_back(-1);
                    break;
                }
                if (it2 == it->end()-1) result.push_back(*it2); // If power array append the last value to result
            }
            map.clear();
        }
        return result;
    }

    void Program::getAllSubArrays(vector<int>& nums, vector<vector<int>>& allSubarrays, int k) {
        vector<int> subarray;

        for (int i=0; i<nums.size(); i++) {
            for (int j=i; j<nums.size(); j++) {
                for (int l=i; l<=j; l++) subarray.push_back(nums[l]);
                if (subarray.size() == k) allSubarrays.push_back(vector<int> (subarray));
                subarray.clear();
            }
        }
    }
}

int main() {
    using namespace Solution;
    Program obj;
    for (int i : obj.resultsArray(nums, k))
        cout << i << " ";
    cout << endl;
    return 0;
}