// LeetCode 3375
#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using std::cout, std::endl, std::vector, std::map;
using std::unordered_set;

static vector<int> nums { 9, 7, 5, 3 };
static int k = 1;

namespace Solution {
    class Compare {
        public:
            bool operator() (int n1, int n2) const { return n1 > n2; }
    };
    class Program{
        private:
            int operation(map<int, unordered_set<int>, Compare>& dict, vector<int>& nums, int h);
        public:
            int minOperations(vector<int>& nums, int k);
    };

    int Program::operation(map<int, unordered_set<int>, Compare>& dict, vector<int>& nums, int h) {
        map<int,unordered_set<int>>::iterator it = dict.begin();
        for (unordered_set<int>::iterator it2=it->second.begin(); it2!=it->second.end(); it2++) {
            nums[*it2] = h;
            dict[h].insert(*it2);
        }
        dict.erase(it);
        return 1;
    }

    int Program::minOperations(vector<int>& nums, int k) {
        map<int,unordered_set<int>, Compare> dict;
        for (int i=0; i<nums.size(); i++) dict[nums[i]].insert(i);
        
        
        int minOperations = 0;
        while(dict.size() > 1) {
            map<int, unordered_set<int>, Compare>::iterator it = dict.begin();
            it++;
            minOperations += operation(dict, nums, it->first);
        }

        auto it = dict.begin();
        if (it->first == k) return minOperations;
        if (it->first > k) return minOperations+1;
        return -1;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.minOperations(nums, k) << endl;
}