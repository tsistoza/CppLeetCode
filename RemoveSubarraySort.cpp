// LeetCode 1574
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static vector<int> arr { 1, 2, 3, 10, 4, 2, 3, 5 };
static vector<int> arr1 { 5, 4, 3, 2, 1 };
static vector<int> arr2 { 1, 2, 3 };

namespace Solution {
    class Program {
        public:
            int findLengthofShortestSubarray(vector<int>& arr);
    };

    int Program::findLengthofShortestSubarray(vector<int>& arr) {
        int left=0, right=arr.size()-1;
        for (; left<right; left++,right--)
            if (arr[left] > arr[right]) break;

        if (left > right) return 0;
        return right - left;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.findLengthofShortestSubarray(arr) << endl;
    cout << obj.findLengthofShortestSubarray(arr1) << endl;
    cout << obj.findLengthofShortestSubarray(arr2) << endl;
    return 0;
}