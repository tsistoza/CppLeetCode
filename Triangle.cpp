// LeetCode 120
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector;
using std::min;

static vector<vector<int>> triangle { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };

namespace Solution {
    class Program {
        public:
            int minimumTotal(vector<vector<int>>& triangle);
    };

    int Program::minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) return triangle[0][0];
        vector<vector<int>> dp { { triangle[0][0] } };
        int sum = INT_MAX;
        
        for (int i=1; i<triangle.size(); i++) {
            vector<int> nextRow;
            for (int j=1; j<triangle[i].size(); j++) {
                int index1 = j, index2 = j-1;

                // Choose the minimum element between two paths
                int minElem = (index2 == -1) ? triangle[i][j] : min(triangle[i][index1], triangle[i][index2]);
                int currSum = dp[i-1][j-1] + minElem;
                nextRow.push_back(currSum);

                // Last element is the extra element for the curr row, since the last row is smaller than the curr row
                // Just add the last path sum, and the curr element.
                if (j==triangle[i].size()-1) nextRow.push_back(dp[i-1][j-1] + triangle[i][j]);

                if (i==triangle.size()-1) sum = min(sum, currSum);
            }
            dp.push_back(nextRow);
        }
        
        return sum;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.minimumTotal(triangle) << endl;
    return 0;
}