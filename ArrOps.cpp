// LeetCode 2460
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static vector<int> nums { 1, 2, 2, 1, 1, 0 };
static vector<int> nums1 { 0, 1 };

static void prettyPrint(vector<int> arr) {
    for (int i : arr) cout << i << " ";
    cout << endl;
    return;
}

namespace Solution {
    class Program {
        public:
            vector<int> applyOperations(vector<int>& nums);
    };

    vector<int> Program::applyOperations(vector<int>& nums) {
        vector<int> result;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i-1] != nums[i]) continue;
            nums[i-1] *= 2;
            nums[i] = 0;
        }

        int countZero = 0;
        for (vector<int>::iterator it = nums.begin(); it!=nums.end(); it++) {
            if (*it == 0) {
                countZero++;
                continue;
            }
            result.push_back(*it);
        }

        while (countZero > 0) {
            result.push_back(0);
            countZero--;
        }

        return result;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    prettyPrint(obj.applyOperations(nums));
    prettyPrint(obj.applyOperations(nums1));
    return 0;
}