// LeetCode 2593
#include <iostream>
#include <vector>
#include <deque>

using std::cout, std::endl;
using std::vector, std::deque;

static vector<int> nums { 2, 1, 3, 4, 5, 2 };
static vector<int> nums1 { 2, 3, 5, 1, 3, 2 };

namespace Solution {
    class Program {
        public:
            long long findScore(vector<int>& nums);
    };
    long long Program::findScore(vector<int>& nums) {
        int score=0;
        deque<int> q;
        for (int i : nums) {
            if (!q.empty() && i>=q.front()) {
                bool skip = false;
                while (!q.empty()) {
                    int add = q.back();
                    q.pop_back();
                    if (!skip) score += add;
                    skip = !skip;
                }
                continue;
            }
            q.push_back(i);
        }

        bool skip = false;
        while (!q.empty()) {
            int add = q.back();
            q.pop_back();
            if(!skip) score += add;
            skip = !skip;
        }
        return score;
    }
}

int main () {
    using namespace Solution;
    Program obj;
    cout << obj.findScore(nums) << endl;
    cout << obj.findScore(nums1) << endl;
    return 0;
}