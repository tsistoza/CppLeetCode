//LeetCode 2601
#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

static vector<int> nums = { 4, 9, 6, 10 };
static vector<int> nums2 = { 6, 8, 11, 12 };
static vector<int> nums3 = { 5, 8, 3 };

namespace Solution {
    class Program {
        public:
            bool primeSubOperation(vector<int>& nums);
            int  pickOptimalPrime(int min, int max);
            bool isPrime(int num);
            bool isIncreasing(vector<int>& nums);
            void printArray(vector<int>& nums);
    };

    bool Program::primeSubOperation(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) { // Iterate through the array and make sure nums[i] is as small as possible
            int p;
            if (isIncreasing(nums)) return true; // Checks if array is strictly increasing if so then just return true
            if (i==0) {
                p = pickOptimalPrime(0, nums[i]);
                nums[i] = nums[i] - p;
                continue;
            }
            p = pickOptimalPrime(nums[i-1], nums[i]);
            nums[i] = nums[i] - p;
        }
        return isIncreasing(nums);
    }

    int Program::pickOptimalPrime(int min, int max) {
        for(int i=max-1; i>0; i--) {
            if (max-i > min && isPrime(i)) return i;
        }
        return 0;
    }

    bool Program::isPrime(int num) {
        if (num <= 1) return false;
        for (int i=2; i<=num/2; ++i)
            if (num%i==0) return false;
        return true;
    }

    bool Program::isIncreasing(vector<int>& nums) {
        for(vector<int>::iterator it=nums.begin()+1; it!=nums.end(); it++)
            if (*(it-1) >= *it) return false;
        return true;
    }


    void Program::printArray(vector<int>& nums) {
        cout << "Array: ";
        for (vector<int>::iterator it=nums.begin(); it!=nums.end(); it++)
            cout << *it << " ";
        cout << endl;
        return;
    }

}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.primeSubOperation(nums) << endl;
    cout << obj.primeSubOperation(nums2) << endl;
    cout << obj.primeSubOperation(nums3) << endl;
    return 0;
}