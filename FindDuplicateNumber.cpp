// LeetCode 287
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static vector<int> nums { 3, 3, 3, 3, 3 };

namespace Solution {
    class Program {
        public:
            int findDuplicate(vector<int>& nums);
    };

    // Tortoise and Hare Algorithm, since we know that the range of numbers is [1, n], the list actually works like a linked list.
    // And, we know there is some duplicate in the list, this will act as an cycle in the linked list.
    int Program::findDuplicate(vector<int>& nums) {
        int turtle = 0, hare = 0;

        while (true) {
            turtle = nums[turtle];
            hare = nums[nums[hare]];

            if (turtle == hare) break;
        }

        int target = 0;
        while (true) {
            target = nums[target];
            turtle = nums[turtle];

            if (target == turtle) break;
        }

        return target;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.findDuplicate(nums) << endl;
}