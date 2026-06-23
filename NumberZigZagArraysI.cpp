// LeetCode 3699
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static int n = 3;
static int l = 1;
static int r = 3;

namespace Solution {
    class Program {
        private:
            int sum(vector<vector<vector<int>>>& dp, int length, bool dir, int lastVal, int low, int high);
        public:
            int zigZagArrays(int n, int l, int r);
    };

    int Program::sum(vector<vector<vector<int>>>& dp, int length, bool dir, int lastVal, int low, int high) {
        int sum = 0;
        if (dir) {
            for (int i=lastVal+1; i<=high; i++)
                sum += dp[length][dir][i];
        } else {
            for (int i=lastVal-1; i>=low; i--)
                sum += dp[length][dir][i];
        }
        return sum;
    }

    int Program::zigZagArrays(int n, int l, int r) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(r+1, 0)));
        for (int i=l; i<=r; i++) {
            for (int j=l; j<=r; j++) {
                if (i == j) continue;
                int dir = (i < j) ? 1 : 0;
                dp[2][dir][j]++;
            }
        }

        for (int i=3; i<=n; i++) {
            for (int dir=0; dir<2; dir++) {
                for (int j=l; j<=r ; j++) {
                    dp[i][dir][j] = sum(dp, i-1, !((bool)dir), j, l, r);
                    //cout << "dp[" << i << "][" << dir << "][" << j << "] = " << dp[i][dir][j] << endl;
                }
            }
        }
        return sum(dp, n, false, r+1, l, r) + sum(dp, n, true, l-1, l, r);
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.zigZagArrays(n, l, r) << endl;
    return 0;
}