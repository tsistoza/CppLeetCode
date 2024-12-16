// LeetCode 1608
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl;
using std::vector;

static vector<int> nums { 3, 5 };
static vector<int> nums1 { 0, 4, 3, 0, 4 };

int specialArray(vector<int>& nums) {
    for (int i=1; i<=nums.size(); i++) {
        int count=0;
        for (vector<int>::iterator it=nums.begin(); it!=nums.end(); it++) {
            if (*it >= i) count++;
            if (count > i) break;
        }
        if (count == i) return i;
    }
    return -1;
}

int main() {
    cout << specialArray(nums) << endl;
    cout << specialArray(nums1) << endl;
    return 0;
} 