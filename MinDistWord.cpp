// LeetCode 1320
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using std::cout, std::endl;
using std::string, std::vector;
using std::pair, std::abs;
using std::max;

static string word = "CAKE";
static string word1 = "HAPPY";

namespace Solution {
    class Program {
        private:
            int cost(int from, int to);
        public:
           int minimumDistance(string word);
    };

    int Program::cost(int from, int to) {
        return abs((from/6) - (to/6)) + abs((from%6) - (to%6));
    }

    

    int Program::minimumDistance(string word) {
        vector<int> dp(26);
        int res=0,save=0,n=word.size();

        for (int i=0; i<n-1; i++) {
            int b = word[i] - 'A';
            int c = word[i+1] - 'A';

            for (int j=0; j<26; j++)
                dp[b] = max(dp[b], dp[j] + cost(b, c) - cost(j, c));

            save = max(save, dp[b]);
            res += cost(b, c);
        }
        return res - save;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.minimumDistance(word) << endl;
    return 0;
}