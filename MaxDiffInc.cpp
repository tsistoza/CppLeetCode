// LeetCode 2016
#include <iostream>
#include <vector>
#include <map>

using std::cout, std::endl, std::vector, std::multimap;

static vector<int> nums { 1, 5, 2, 10 };

namespace Solution {
    class Program{
        public:
            int maximumDifference(vector<int>& nums);
    };

    int Program::maximumDifference(vector<int>& nums) {
        multimap<int,int> idxDict;
        for (int i=0; i<nums.size(); i++)
            idxDict.insert({ nums[i], i });

        for (multimap<int,int>::reverse_iterator itr=idxDict.rbegin(); itr!=idxDict.rend(); itr++) {
            for (multimap<int,int>::iterator it=idxDict.begin(); it != idxDict.end(); it++) {
                if (itr->first == it->first && itr->second == it->second) continue;
                if (itr->first < it->first) continue;
                if (itr->second < it->second) continue;
                return itr->first - it->first;
            }
        }

        return -1;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.maximumDifference(nums) << endl;
    return 0;
}