// LeetCode 983
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;
using std::min, std::max;

static vector<int> days { 1, 4, 6, 7, 8, 20 };
static vector<int> costs { 2, 7, 15 };
static vector<int> days1 { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31 };

namespace Solution {
    class Program{
        private:
            int minCostOnDayN(vector<int>& dp, vector<int>& days, vector<int>& costs, int day);
        public:
            int mincostTickets(vector<int>& days, vector<int>& costs);
    };

    int Program::minCostOnDayN(vector<int>& dp, vector<int>& days, vector<int>& costs, int day) {
        int curr = dp[day-1] + costs[0];
        curr = min(curr, dp[max(0, day-7)] + costs[1]);
        curr = min(curr, dp[max(0, day-30)] + costs[2]);
        return curr;
    }

    int Program::mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.back()+1, 0);

        vector<int>::iterator it = days.begin();
        for (int i=1; i<days.back()+1; i++) {
            if (*it == i) {
                dp[i] = minCostOnDayN(dp, days, costs, i);
                it++;
                continue;
            }
            dp[i] = dp[i-1];
        }
        return dp.back();
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.mincostTickets(days, costs) << endl;
    cout << obj.mincostTickets(days1, costs) << endl;
    return 0;
}