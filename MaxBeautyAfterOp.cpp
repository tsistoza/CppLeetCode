// LeetCode 2779
#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>


using std::cout, std::endl;
using std::vector, std::unordered_map;
using std::iota;

static vector<int> nums { 4, 6, 1, 2 };
static int k = 2;
static vector<int> nums1 { 1, 1, 1, 1 };
static int k1 = 10;

namespace Solution {
    class Program {
        public:
            int maximumBeauty(vector<int>& nums, int k);
    };
    int Program::maximumBeauty(vector<int>& nums, int k) {
        int maxBeauty = 1;
        vector<int> range(((nums[0] - (nums[0]-k)) * 2) + 1);
        unordered_map<int, int> line;
        for (vector<int>::iterator it=nums.begin(); it!=nums.end(); it++)
            for(int j=*it-k; j<=*it+k; j++) line[j]++;
        if (line[nums[0]] == nums.size()) return nums.size();

        for (unordered_map<int,int>::iterator it = line.begin(); it!= line.end(); it++)
            maxBeauty = (maxBeauty < it->second) ? it->second : maxBeauty;
        return maxBeauty;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.maximumBeauty(nums, k) << endl;
    cout << obj.maximumBeauty(nums1, k1) << endl;
    return 0;
}