// LeetCode 435
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector, std::sort;

static vector<vector<int>> intervals { { 1, 2 }, { 1, 2 }, { 1, 2 } };

namespace Solution {
    class Compare {
        public:
            bool operator() (vector<int>& a, vector<int>& b) const {
                return a[1] < b[1];
            }
    };
    class Program {
        public:
            int eraseOverlapIntervals(vector<vector<int>>& intervals);
    };

    int Program::eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return 0;

        Compare cmp;
        sort(intervals.begin(), intervals.end(), cmp);
        
        int prev_end = intervals[0][1];
        int result = 0;
        for (int i=1; i<intervals.size(); i++) {
            if (prev_end > intervals[i][0]) result++;
            else prev_end = intervals[i][1];
        }
        return result;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.eraseOverlapIntervals(intervals) << endl;
    return 0;
}