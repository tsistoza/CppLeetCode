// LeetCode 1985
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout, std::endl;
using std::string, std::vector;
using std::stoi, std::sort;

static vector<string> nums = { "3", "6" , "7", "10" };
static int k = 4;
static vector<string> nums1 = { "2","21","12","1" };
static int k1 = 3;

namespace Solution {
    class Compare {
        public:
        bool operator()(string s1, string s2) const { return stoi(s1) < stoi(s2); }
    };
    class Program {
        public:
            string kthLargestNumber(vector<string>& nums, int k);
    };
    
    string Program::kthLargestNumber(vector<string>& nums, int k) {
        Compare cmp;
        sort(nums.begin(), nums.end(), cmp);
        return *(nums.end()-1-(k-1));
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.kthLargestNumber(nums, k) << endl;
    cout << obj.kthLargestNumber(nums1, k1) << endl;
    return 0;
}