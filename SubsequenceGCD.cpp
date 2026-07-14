// LeetCode 3336
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static vector<int> nums { 1, 1, 1, 1 };

namespace Solution {
    class Program{
        private:
            int gcd(int num1, int num2);
        public:
            int subsequencePairCount(vector<int>& nums);
    };

    int Program::gcd(int num1, int num2) {
        // Euclids Algorithm, num1 < num2
        if (num1 == 0 && num2 == 0) return 1;
        if (num1 == num2) return num1;
        if (num1 == 0) return num2;

        int divisor = num1;
        int dividend = num2;
        int remainder = dividend % divisor;
        while (remainder > 0) {
            dividend = divisor;
            divisor = remainder;
            remainder = dividend % divisor;
        }

        return divisor;
    }

    int Program::subsequencePairCount(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int m = INT_MIN, n = nums.size();
        for (int num : nums) 
            if (m < num) m = num;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, 0)));
        dp[0][0][0] = 1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<=m; j++) {
                int newGcd1 = 0;

                if (j > nums[i]) newGcd1 = gcd(nums[i], j);
                else newGcd1 = gcd(j, nums[i]);

                for (int k=0; k<=m; k++) {

                    if (dp[i][j][k] == 0) continue;

                    int newGcd2 = 0;
                    if (k > nums[i]) newGcd2 = gcd(nums[i], k);
                    else newGcd2 = gcd(k, nums[i]);

                    //cout << "i = " << i << ", j = " << j << ", k = " << k << endl;
                    //cout << "j' = " << newGcd1 << ", k' = " << newGcd2 << endl;
                    dp[i+1][j][k] = (dp[i+1][j][k] + dp[i][j][k]) % mod;
                    dp[i+1][newGcd1][k] = (dp[i+1][newGcd1][k] + dp[i][j][k]) % mod;
                    dp[i+1][j][newGcd2] = (dp[i+1][j][newGcd2] + dp[i][j][k]) % mod;
                }
            }
        }

        int ans = 0;
        for (int j=1; j<=m; j++)
            ans = (ans + dp[n][j][j]) % mod;

        return ans;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.subsequencePairCount(nums) << endl;
    return 0;
}