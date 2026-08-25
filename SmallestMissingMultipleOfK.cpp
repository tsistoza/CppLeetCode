// LeetCode 3718
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using std::cout, std::endl, std::vector, std::unordered_set, std::min;

static vector<int> nums { 1, 4, 7, 10, 15 };
static int k = 2;

namespace Solution {
    class Program {
        public:
            int missingMultiple(vector<int>& nums, int k);
    };

    int Program::missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> set;
        int minMultiple = k;

        for (int i : nums) {
            if (set.contains(i)) continue;
            set.insert(i);
            while (set.contains(minMultiple)) minMultiple += k;
        }

        return minMultiple;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.missingMultiple(nums, k) << endl;
    return 0;
}