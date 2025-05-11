// LeetCode 1550
#include <iostream>
#include <vector>
#include <ios>

using std::cout, std::endl, std::vector;

static vector<int> arr { 2, 6, 4, 1 };

namespace Solution {
    class Program {
        public:
            bool threeConsecutiveOdds(vector<int>& arr);
    };

    bool Program::threeConsecutiveOdds(vector<int>& arr) {
        for (int i=0; i<arr.size()-2; i++)
            if (arr[i]%2 && arr[i+1]%1 && arr[i+2]%2) return true;
        return false;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << std::boolalpha << obj.threeConsecutiveOdds(arr) << endl;
    return 0;
}