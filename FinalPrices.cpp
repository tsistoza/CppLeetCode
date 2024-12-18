// LeetCode 1475
#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

static vector<int> prices { 8, 4, 6, 2, 3 };

namespace Solution {
    class Program {
        public:
            vector<int> finalPrices(vector<int>& prices);
    };

    vector<int> Program::finalPrices(vector<int>& prices) {
        vector<int> result;
        for (int i=0; i<prices.size(); i++) {
            int index=i+1;
            while(index < prices.size()) {
                if (prices[index] < prices[i] && i < prices.size()-1) {
                    result.push_back(prices[i] - prices[index]);
                    break;
                }
                index++;
            }
            if (index >= prices.size()) result.push_back(prices[i]);
        }
        return result;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    for (int i : obj.finalPrices(prices))
        cout << i << " ";
    cout << endl;
    return 0;
}