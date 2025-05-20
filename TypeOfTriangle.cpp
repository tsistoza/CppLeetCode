// LeetCode 3024
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cstdlib>

using std::cout, std::endl, std::vector;
using std::string, std::unordered_set, std::abs;

static vector<int> nums { 3, 2, 1 };

namespace Solution {
    class Program {
        public:
            string triangleType(vector<int>& nums);
    };

    string Program::triangleType(vector<int>& nums) {
        unordered_set<int> dupe;
        for (int i : nums) dupe.insert(i);

        if (dupe.size() == 1) return "equilateral";
        if (dupe.size() == 2) return "isosceles";

        return (nums[2] > nums[0]-nums[1] && nums[2] < nums[0] + nums[1]) ? "scalene" : "none";
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.triangleType(nums) << endl;
    return 0;
}