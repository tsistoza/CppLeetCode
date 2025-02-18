// LeetCode 46
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static vector<int> nums { 1, 2, 3 };
static vector<int> nums1 { 0, 1 };

namespace Solution {
    class Program {
        private:
            void generatePermutation(int index, vector<int> permutation, vector<vector<int>>& results, vector<int>& nums);
        public:
            vector<vector<int>> permute(vector<int>& nums);
    };

    void Program::generatePermutation(int index, vector<int> permutation, vector<vector<int>>& results, vector<int>& nums) {
        if (index >= nums.size()) {
            results.push_back(permutation);
            return;
        }

        for (int i=index; i<nums.size(); i++) {
            vector<int> temp(permutation);
            int swap = temp[index];
            temp[index] = temp[i];
            temp[i] = swap;
            generatePermutation(index+1, temp, results, nums);
        }
        return;
    }

    vector<vector<int>> Program::permute(vector<int>& nums) {
        vector<vector<int>> results;
        generatePermutation(0, nums, results, nums);
        return results;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    
    for (vector<int> vec : obj.permute(nums)) {
        cout << "{ ";
        for (int i : vec)
            cout << i << " ";
        cout << "} ";
    }
    cout << endl;

    for (vector<int> vec : obj.permute(nums1)) {
        cout << "{ ";
        for (int i : vec)
            cout << i << " ";
        cout << "} ";
    }
    cout << endl;
    return 0;
}

