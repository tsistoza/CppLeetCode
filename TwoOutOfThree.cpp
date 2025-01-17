// LeetCode 2032
#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout, std::endl;
using std::vector, std::unordered_map;

static vector<int> nums1 { 1, 1, 3, 2 };
static vector<int> nums2 { 2, 3 };
static vector<int> nums3 { 3 };
static vector<int> nums1a { 3, 1 };
static vector<int> nums2a { 2, 3 };
static vector<int> nums3a { 1, 2 };
static vector<int> nums1b { 1, 2, 2 };
static vector<int> nums2b { 4, 3, 3 };
static vector<int> nums3b { 5 };

namespace Solution {
    class Program {
        private:
            void countNums(vector<int>& nums, unordered_map<int,int>& count);
            void duplicate(unordered_map<int, int>& count, unordered_map<int,int> temp);
        public:
            vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3);
    };

    void Program::duplicate(unordered_map<int,int>& count, unordered_map<int,int> temp) {
        for (unordered_map<int,int>::iterator it=temp.begin(); it!=temp.end(); it++)
            if (count.contains(it->first)) count[it->first]++; 
        return;
    }

    void Program::countNums(vector<int>& nums, unordered_map<int,int>& count) {
        unordered_map<int,int> temp;
        for (int i : nums) {
            if (temp.contains(i)) continue;
            temp[i]++;
        }

        for (unordered_map<int,int>::iterator it=temp.begin(); it!=temp.end(); it++) 
            count[it->first]++;
        return;
    }

    vector<int> Program::twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> count;
        vector<int> result;
        countNums(nums1, count);
        countNums(nums2, count);
        countNums(nums3, count);

        for (unordered_map<int,int>::iterator it=count.begin(); it!=count.end(); it++)
            if (it->second >= 2) result.push_back(it->first);

        return result;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    for (int i : obj.twoOutOfThree(nums1, nums2, nums3))
        cout << i << " ";
    cout << endl;

    for (int i : obj.twoOutOfThree(nums1a, nums2a, nums3a))
        cout << i << " ";
    cout << endl;

    for (int i : obj.twoOutOfThree(nums1b, nums2b, nums3b))
        cout << i << " ";
    cout << endl;
    return 0;
}