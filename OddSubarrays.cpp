// LeetCode 1524
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static vector<int> arr { 1, 3, 5 };
static vector<int> arr1 { 2, 4, 6 };
static vector<int> arr2 { 1, 2, 3, 4, 5, 6, 7 };

namespace Solution {
    class Program {
        public:
            int numOfSubarrays(vector<int>& arr);
    };

    int Program::numOfSubarrays(vector<int>& arr) {
        int count = 0;
        for (int i=0; i<arr.size(); i++) {
            int sum = arr[i];
            if (sum % 2) count++;
            for (int j=i+1; j<arr.size(); j++) {
                sum += arr[j];
                if (sum%2) count++;
            }
        }
        return count;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.numOfSubarrays(arr) << endl;
    cout << obj.numOfSubarrays(arr1) << endl;
    cout << obj.numOfSubarrays(arr2) << endl;
    return 0;
}