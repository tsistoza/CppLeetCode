// LeetCode 3396
#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout, std::endl, std::vector, std::unordered_map;

static vector<int> nums { 6, 7, 8, 9 };

namespace Solution {
    class Program {
        private:
            bool isDistinct(unordered_map<int,int>& dict);
            int operation(unordered_map<int,int>& dict, vector<int>& nums);
        public:
            int minimumOperations(vector<int>& nums);
    };

    bool Program::isDistinct(unordered_map<int,int>& dict) {
        for (unordered_map<int,int>::iterator it=dict.begin(); it!=dict.end(); it++)
            if (it->second > 1) return false;
        return true;
    }

    int Program::operation(unordered_map<int,int>& dict, vector<int>& nums) {
        int i=3;
        while (i > 0) {
            dict[*(nums.begin())]--;
            if (dict[*(nums.begin())] == 0) dict.erase(*(nums.begin()));
            nums.erase(nums.begin());
            i--;
        }
        return 1;
    }

    int Program::minimumOperations(vector<int>& nums) {
        unordered_map<int, int> dict;
        for (int i : nums) dict[i]++;

        int minOperations = 0;
        while (!isDistinct(dict))
            minOperations += operation(dict, nums);

        return minOperations;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.minimumOperations(nums) << endl;
}
