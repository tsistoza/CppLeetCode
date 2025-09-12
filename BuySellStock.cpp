// LeetCode 121
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector;
using std::max, std::min;

static vector<int> prices { 2, 4, 1 };

namespace Solution {
    class Program {
        public:
            int maxProfit(vector<int>& prices);
    };

    int Program::maxProfit(vector<int>& prices) {
        int buyPriceMin = prices[0], maxProfit = INT_MIN;
        for (int i=1, currProfit=0; i<prices.size(); i++) {
            currProfit = prices[i] - buyPriceMin;
            buyPriceMin = min(buyPriceMin, prices[i]);
            maxProfit = max(currProfit, maxProfit);
        }

        return (maxProfit <= -1) ? 0 : maxProfit;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.maxProfit(prices) << endl;
    return 0;
}