// LeetCode 3314
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static vector<int> nums { 2,3,5,7 };

namespace Solution {
    class Program {
        public:
            static void prettyPrint(vector<int> nums);
            vector<int> minBitwiseArray(vector<int>& nums);
    };

    void Program::prettyPrint(vector<int> nums) {
        cout << endl;
        cout << "{ ";
        for(int i=0; i<nums.size(); i++) {
            (i < nums.size()-1) ? cout << nums[i] << ", " :
                                   cout << nums[i] << " ";
        }
        cout << "} " << endl;
        return;
    }

    vector<int> Program::minBitwiseArray(vector<int>& nums) {
        vector<int> result;
        for (int i=0; i<nums.size(); i++) {
            int shift = nums[i], multiplicand = 1;
            int number = 0;
            while (shift & 1 == 1) {
                number += (shift & 1) * multiplicand;
                shift >>= 1;
                multiplicand *= 2;
            }

            number -= (multiplicand/2);

            while (shift > 0) {
                number += (shift & 1) * multiplicand;
                shift >>=1;
                multiplicand *= 2;
            }

            result.push_back(((number | number + 1) == nums[i]) ? number : -1);
        }
        prettyPrint(result);
        return result;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    obj.minBitwiseArray(nums);
    return 0;
}