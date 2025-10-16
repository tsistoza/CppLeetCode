// LeetCode 312
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using std::cout, std::endl, std::vector;
using std::max;

static vector<int> nums { 3, 1, 5, 8 };

namespace Solution {
    class Program {
        private:
            int dp[500][500];
            int splitArr(vector<int>& modArr, int arrSize, int index1, int index2);
        public:
            int maxCoins(vector<int>& nums);
    };

    int Program::splitArr(vector<int>& modArr, int arrSize, int index1, int index2) {
        if (index1 > index2) return 0;
        if (index1 == index2) {
            int num = modArr[index1];
            if (index1-1 >= 0) num *= modArr[index1-1];
            if (index1+1 < arrSize) num *= modArr[index1+1];
            return num;
        }
        if (dp[index1][index2] != -1) return dp[index1][index2];
        int ans=INT_MIN;
        for (int i=index1; i<=index2; i++) {
            int currAns = modArr[i];
            if (index1 - 1 >= 0) currAns *= modArr[index1-1];
            if (index2 + 1 < arrSize) currAns *= modArr[index2+1];

            currAns += (splitArr(modArr, arrSize, index1, i-1) + splitArr(modArr, arrSize, i+1, index2));

            ans = max(ans, currAns);
        }
        
        dp[index1][index2] = ans;
        return dp[index1][index2];
    }

    int Program::maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int maxCurrency = INT_MIN;
        
        vector<int> modArr { 1 };
        for (int val : nums)
            modArr.push_back(val);
        modArr.push_back(1);

        return splitArr(modArr, modArr.size(), 1, nums.size());
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.maxCoins(nums) << endl;
    return 0;
}