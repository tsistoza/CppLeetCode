// LeetCode 2952
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl;
using std::sort, std::vector;

static vector<int> coins { 1, 4, 10 };
static int target = 19;
static vector<int> coins1 { 1, 4, 10, 5, 7, 19 };
static int target1 = 19;

namespace Solution {
    class Program {
        public:
            int minimumAddedCoins(vector<int>& coins, int target);
    };

    int Program::minimumAddedCoins(vector<int>& coins, int target) {
        int numCoins = 0;
        int currMax = 0;
        int index = 0;
        sort(coins.begin(), coins.end());

        while (currMax < target) {
            if (coins[index] <= currMax + 1){
                currMax += coins[index];
                index++;
            } else {
                currMax = (currMax*2) + 1;
                numCoins++;
            }
        }
        return numCoins;
    }
}

int main() {
    Solution::Program obj;
    cout << obj.minimumAddedCoins(coins, target) << endl;
    cout << obj.minimumAddedCoins(coins1, target1) << endl;
    return 0;
}