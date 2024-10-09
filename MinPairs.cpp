#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using std::cout,std::cin,std::vector;
using std::endl;
using std::max_element;

static int p = 1;
vector<int> nums = {4, 2, 1, 2};


/// @brief Essentially find the min pair difference, remove those two indexes of the list, and then find it again

namespace solution {
    class MinPairs {
        public:
            int minimizeMax(vector<int>& nums, int p);
            int findMinPairDifference(vector<int> &nums);
    };

    int MinPairs::minimizeMax(vector<int>& nums, int p) {
            vector<int> set;
            for (int i=0 ; i<p ; i++)
                set.push_back(findMinPairDifference(nums));
            double max = *max_element(set.begin(), set.end());
            return max;
    }

    int MinPairs::findMinPairDifference(vector<int>& nums) {
        int pair1, pair2;
        int difference = abs(nums[0]-nums[1]);
        for (int i=0; i<nums.size(); i++) {
            for (int j=i+1; j<nums.size(); j++) {
                if (abs(nums[i]-nums[j]) < difference && nums[i] != -1 && nums[j] != -1) {
                    pair1 = i;
                    pair2 = j;
                    difference = abs(nums[i]-nums[j]);
                }
            }
        }
        vector<int> minPair = {pair1, pair2};
        nums[pair1] = -1;
        nums[pair2] = -1;
        return difference;
    }
}

int main (){
    solution::MinPairs object;
    cout << "Minimizing the maximum difference of pairs with: p = " << p
        << " Answer: " << object.minimizeMax(nums, p);
    return 0;
}