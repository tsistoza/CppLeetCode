// LeetCode 1577
#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

static vector<int> nums1 { 7, 4 };
static vector<int> nums2 { 5, 2, 8, 9 };
static vector<int> nums1a { 1, 1 };
static vector<int> nums2a { 1, 1, 1 };
static vector<int> nums1b { 7, 7, 8, 3 };
static vector<int> nums2b { 1, 2, 7, 9 };

namespace Solution {
    class Program {
        private:
            void getTriplets(int& count, vector<int>& nums1, vector<int>& nums2);
        public:
            int numTriplets(vector<int>& nums1, vector<int>& nums2);
    };

    void Program::getTriplets(int& count, vector<int>& nums1, vector<int>& nums2) {
        for (int i=0; i<nums1.size(); i++)
            for (int j=0; j<nums2.size(); j++)
                for (int k=j+1; k<nums2.size(); k++)
                    if ((nums1[i]*nums1[i]) == (nums2[j]*nums2[k]))
                        count++;
        return;
    }

    int Program::numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int count = 0;
        getTriplets(count, nums1, nums2);
        getTriplets(count, nums2, nums1);
        return count;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.numTriplets(nums1, nums2) << endl;
    cout << obj.numTriplets(nums1a, nums2a) << endl;
    cout << obj.numTriplets(nums1b, nums2b) << endl;
    return 0;
}