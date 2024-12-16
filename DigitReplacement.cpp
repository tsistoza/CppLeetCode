// LeetCode 3300
#include <iostream>
#include <vector>
#include <string>

using std::cout, std::endl;
using std::vector, std::string;
using std::stoi, std::to_string;

static vector<int> nums { 10, 12, 13, 14 };
static vector<int> nums1 { 1, 2, 3, 4 };
static vector<int> nums2 { 999, 19, 199 };

int minElement(vector<int>& nums) {
    int min = INT_MAX;
    for (int i : nums) {
        int sum=0;
        string num = to_string(i);
        for (char c : num) {
            string s(1, c);
            sum += stoi(s);
        }
        min = (min < sum) ? min : sum;
    }
    return min;
}

int main() {
    cout << minElement(nums) << endl;
    cout << minElement(nums1) << endl;
    cout << minElement(nums2) << endl;
    return 0;
}