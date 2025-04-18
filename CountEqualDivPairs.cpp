// LeetCode 2176
#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout, std::endl, std::vector;
using std::unordered_map;

static vector<int> nums { 3,1,2,2,2,1,3 };
static int k=2;

namespace Solution {
    class Program {
        private:
        public:
            int countPairs(vector<int>& nums, int k);
    };

    int Program::countPairs(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, vector<int>> dict;
        for (int i=0; i<nums.size(); i++) {
            dict[nums[i]].push_back(i);

            if (dict[nums[i]].size() < 2) continue;

            vector<int>::reverse_iterator itr=dict[nums[i]].rbegin();
            int index = *(itr++);
            for (; itr!=dict[nums[i]].rend(); itr++)
                if ((index * *(itr) % k) == 0) count++;
        }
        return count;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.countPairs(nums, k) << endl;
}