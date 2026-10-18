// LeetCode 3699
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static int n = 8;
static int l = 5;
static int r = 67;

namespace Solution {
    class Program {
        private:
            static void prettyPrint(vector<vector<int>>& sum);
            int sum(vector<vector<vector<int>>>& dp, int length, bool dir, int lastVal, int low, int high);
        public:
            int zigZagArrays(int n, int l, int r);
    };


    void Program::prettyPrint(vector<vector<int>>& sum) {
        cout << "{ ";
        for (int i=0; i<sum[0].size(); i++) {
            cout << sum[0][i] << " ";
        }
        cout << "}" << endl;

        cout << " { ";
        for (int i=0; i<sum[0].size(); i++) {
            cout << sum[1][i] << " ";
        }
        cout << "}" << endl;
    }

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
        int mod = 1e9 + 7;
        vector<vector<int>> prevDp(2, vector<int>(r+1, 0)); // dp[i][j] - j is the last number of the array, and i is either a zig or zag
                                                            // and where dp[i][j] = sum of zigzag arrays ending with j.
        vector<vector<int>> prevSum(2, vector<int>(r+1-l, 0));
        for (int j=l; j<=r; j++) { // Init Dp
            prevDp[0][j] = ((r - j) % mod);
            prevDp[1][j] = ((j - l) % mod);

            if (j == l) {
                prevSum[0][j-l] = (prevDp[0][j] % mod);
                prevSum[1][j-l] = (prevDp[1][j] % mod);
            } else {
                prevSum[0][j-l] += (((prevSum[0][j-l-1] % mod) + (prevDp[0][j] % mod)) % mod);
                prevSum[1][j-l] += (((prevSum[1][j-l-1] % mod) + (prevDp[1][j] % mod)) % mod);
            }
        }

        prettyPrint(prevSum);

        for (int i=3; i<=n; i++) {
            vector<vector<int>> currSum(2, vector<int>(r+1-l, 0));
            for (int j=l; j<=r; j++) {
                if (j > l)  {
                    prevDp[1][j] = (prevSum[0][j-l-1] % mod);
                    cout << "prevSum[0][" << j-l-1 << "] = " << prevSum[0][j-l-1] << endl;
                }
                if (j < r) {
                    int high = r-l;
                    int low = j-l+1;
                    if (low == 0) prevDp[0][j] = prevSum[1][high] % mod;
                    else {
                        int upper = prevSum[1][high] % mod;
                        int lower = prevSum[1][low-1] % mod;
                        if (upper < lower) prevDp[0][j] = (upper - lower + mod) % mod;
                        else prevDp[0][j] = (upper - lower) % mod;
                    }
                }

                if (j == l) {
                    currSum[0][0] = (prevDp[0][j] % mod);
                    currSum[1][0] = (prevDp[1][j] % mod);
                } else {
                    currSum[0][j-l] = (((currSum[0][j-l-1] % mod) + (prevDp[0][j] % mod)) % mod);
                    currSum[1][j-l] = (((currSum[1][j-l-1] % mod) + (prevDp[1][j] % mod)) % mod);
                }

                cout << "length = " << i << " dp[" << 0 << "][" << j << "] = " << prevDp[0][j] << endl;
                cout << "length = " << i << " dp[" << 1 << "][" << j << "] = " << prevDp[1][j] << endl;
            }

            //std::copy(nextDp.begin(), nextDp.end(), prevDp.begin());
            std::copy(currSum.begin(), currSum.end(), prevSum.begin());
            prettyPrint(prevSum);
        }

        return (((prevSum[0][r-l] % mod) + (prevSum[1][r-l] % mod) % mod)) % mod;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.zigZagArrays(n, l, r) << endl;
    return 0;
}