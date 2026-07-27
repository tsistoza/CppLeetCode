// LeetCode 1464
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static vector<int> nums { 3,4,5,2 };

namespace Solution {
    class Program {
        public:
            int maxProduct(vector<int>& nums);
    };

    int Program::maxProduct(vector<int>& nums) {
        int prod1 = 0, prod2 = 0;
        for (int i : nums) {
            if (prod1 < i) {
                prod2 = prod1;
                prod1 = i;
                continue;
            }

            if (prod2 < i)
                prod2 = i;
        }

        //cout << prod1 << " " << prod2 << endl;
        return (prod1 - 1) * (prod2 - 1);
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.maxProduct(nums) << endl;
    return 0;
}