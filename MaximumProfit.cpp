// LeetCode 1235
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl;
using std::sort, std::vector;

static vector<int> startTime { 1, 2, 3, 3 };
static vector<int> endTime { 3, 4, 5, 6 };
static vector<int> profit { 50, 10, 40, 70 };

static vector<int> startTime1 { 1, 2, 3, 4, 6 };
static vector<int> endTime1 { 3, 5, 10, 6, 9 };
static vector<int> profit1 { 20, 20, 100, 70, 60 };

namespace Solution {
    class Program {
        private:
            void dfs(int index, int sum, int& maxSum, vector<int>& startTime, vector<int>& endTime, vector<int>& profit);
        public:
            int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit);
    };
    
    void Program::dfs(int index, int sum, int& maxSum, vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        maxSum = (maxSum < sum) ? sum : maxSum;
        for (int i=index+1; i<startTime.size(); i++) {
            int tempSum = sum;
            if (endTime[index] > startTime[i]) continue;
            tempSum += profit[i];
            dfs(i, tempSum, maxSum, startTime, endTime, profit);
        }
        return;
    }
    

    int Program::jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int max = 0;
        for (int i=0; i<startTime.size(); i++)
            dfs(i, profit[i], max, startTime, endTime, profit);
        return max;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.jobScheduling(startTime, endTime, profit) << endl;
    cout << obj.jobScheduling(startTime1, endTime1, profit1) << endl;
    return 0;
}