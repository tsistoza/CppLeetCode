// LeetCode 2845
#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout, std::endl, std::vector;
using std::unordered_map;

static vector<int> nums { 3, 1, 9, 6 };
static int modulo = 3;
static int k = 0;

namespace Solution {
    class Program{
        public:
            long long countInterestingSubarrays(vector<int>& nums, int modulo, int k);
    };

    long long Program::countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long numSubarrays=0;
        long long prefix = 0;
        unordered_map<int,int> prefixMap;
        prefixMap[0]=1;
        for (int i=0; i<nums.size(); i++) {
            prefix += (nums[i] % modulo == k) ? 1 : 0;
            numSubarrays += prefixMap[(prefix+modulo-k)%modulo];
            prefixMap[prefix%modulo]++;
        }
        return numSubarrays;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.countInterestingSubarrays(nums, modulo, k) << endl;
}