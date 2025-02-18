// LeetCode 90
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <functional>

using std::cout, std::endl, std::vector;
using std::unordered_set;

static vector<int> nums { 1, 2, 2 };

namespace Solution {
    class Program {
        private:
            bool vecContains(vector<int> subset, vector<vector<int>>& results);
            void generatePowerSet(int index, vector<vector<int>>& results, vector<int> subset, vector<int>& nums);
        public:
            vector<vector<int>> subsetWithDup(vector<int>& nums);
    };

    bool Program::vecContains(vector<int> subset, vector<vector<int>>& results) {
        if (subset.empty()) return false;
        
        for (int i=0; i<results.size(); i++) {
            if (results[i].size() != subset.size()) continue;
            int k=0;
            for (int j=0; j<results[i].size(); j++) {
                if (subset[k] == results[i][j]) k++;
                else break;
            }
            if (k==subset.size()) return true;
        }
        return false;
    }

    void Program::generatePowerSet(int index, vector<vector<int>>& results, vector<int> subset, vector<int>& nums) {
        if (vecContains(subset, results)) return;
        results.push_back(subset);
        if (index >= nums.size()) return;

        vector<int> temp(subset);
        temp.push_back(nums[index]);
        generatePowerSet(index+1, results, temp, nums);

        if (!subset.empty()) {
            vector<int> temp1(subset);
            temp1.pop_back();
            temp1.push_back(nums[index]);
            generatePowerSet(index+1, results, temp1, nums);
        }

        return;
    }

    vector<vector<int>> Program::subsetWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        generatePowerSet(0, results, vector<int> (), nums);
        return results;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    
    for (vector<int> vec : obj.subsetWithDup(nums)) {
        cout << "{ ";
        for (int i : vec)
            cout << i << " ";
        cout << "} ";
    }
    cout << endl;
    return 0;
}