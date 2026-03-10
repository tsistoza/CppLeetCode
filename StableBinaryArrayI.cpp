// LeetCode 3129
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector, std::min;

static int zero = 1;
static int one = 1;
static int limit = 2;

namespace Solution {
    class Program {
        public:
            int numberOfStableArrays(int zero, int one, int limit);
    };

    int Program::numberOfStableArrays(int zero, int one, int limit) {
        long long dp[200][200][2] = { 0 };
        
        int maxZeros = min(zero, limit);
        for (int i=0; i<=maxZeros; i++)
            dp[i][0][0] = 1;
        int maxOnes = min(one, limit);
        for (int j=0; j<=maxOnes; j++)
            dp[0][j][1] = 1;
        long long mod = 1e9 + 7;

        for (int i=1; i<=zero; i++) {
            for (int j=1; j<=one; j++) {
                if (i <= limit)
                    dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
                else
                    dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1] - dp[i-limit-1][j][1];
                
                if (j <= limit)
                    dp[i][j][1] = dp[i][j-1][1] + dp[i][j-1][0];
                else
                    dp[i][j][1] = dp[i][j-1][1] + dp[i][j-1][0] - dp[i][j-limit-1][0];
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % mod;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.numberOfStableArrays(zero, one, limit) << endl;
    return 0;
}