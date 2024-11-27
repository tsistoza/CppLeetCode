// LeetCode 11
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl;
using std::vector, std::sort;

static vector<int> height { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
static vector<int> height1 { 1, 1 };

namespace Solution {
    class Program {
        public:
            int maxArea(vector<int>& height);
    };
    int Program::maxArea(vector<int>& height) {
        vector<int> dp;
        for (int i=0; i<height.size(); i++) {
            for (int j=0 ; j<i; j++) {
                int minHeight = (height[j] < height[i]) ? height[j] : height[i];
                dp.push_back(minHeight * (i-j));
            }
        }
        sort(dp.begin(), dp.end());
        return dp.back();
    }
}

int main () {
    using namespace Solution;
    Program obj;
    cout << obj.maxArea(height) << endl;
    cout << obj.maxArea(height1) << endl;
    return 0;
}

