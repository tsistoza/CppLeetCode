#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl;
using std::vector, std::sort;

static vector<vector<int>> pairs = { {10, 11}, {8, 9}, {1, 2}, {2, 3}, {3, 4} };


struct {
    bool operator() (vector<int>pair1, vector<int>pair2) const { return pair1[0] < pair2[0]; }
} compare;

namespace Solution{
    class Program{
        public:
            int findLongestChain(vector<vector<int>>& pairs);
    };

    int Program::findLongestChain(vector<vector<int>>& pairs) {
        vector<int> dp(pairs.size(), 1);
        sort(pairs.begin(), pairs.end(), compare);

        for (int i=0; i<pairs.size(); i++){
            for (int j=0; j<i; j++){
                if (pairs[j][1] < pairs[i][0] && dp[i] < dp[j]+1)
                    dp[i] = dp[j] + 1;
            }
        }
        return dp.back();
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.findLongestChain(pairs);
    return 0;
}