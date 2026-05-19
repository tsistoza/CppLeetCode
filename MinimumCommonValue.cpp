// Leetcode 2540
#include <iostream>
#include <vector>

using std::cout, std::vector, std::endl;

static vector<int> nums1 { 1, 2, 3, 6 };
static vector<int> nums2 { 2, 3, 4, 5 };

namespace Solution {
    class Program {
        public:
            int getCommon(vector<int>& nums1, vector<int>& nums2);
    };

    int Program::getCommon(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size() - 1, size2 = nums2.size() - 1;
        int p1 = 0, p2 = 0;

        if (nums1[size1] < nums2[0] || nums2[size2] < nums1[0]) return -1;

        while (p1 <= size1 && p2 <= size2) {
            if (nums1[p1] == nums2[p2]) return nums1[p1];

            if (nums1[p1] < nums2[p2]) p1++;
            else p2++;
        }

        return -1;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.getCommon(nums1, nums2) << endl;
    return 0;
}