#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl;
using std::vector, std::sort;

static vector<vector<int>> envelopes = { {5, 4}, {6, 4}, {6, 7}, {2, 3} };

struct {
    bool operator() (vector<int>& list1, vector<int>& list2) const { return list1[0] < list2[0]; }
} compare;


namespace Solution {
    class Program {
        public:
            int maxEnvelopes(vector<vector<int>>& envelopes);
    };

    int Program::maxEnvelopes(vector<vector<int>>& envelopes) {
        int size = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> dp(envelopes.size(), 1);

        for(int i=0; i<dp.size(); i++)
            for(int j=0; j<i; j++)
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j]+1;
        return dp.back();
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.maxEnvelopes(envelopes);
    return 0;
}