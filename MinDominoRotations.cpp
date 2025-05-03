// LeetCode 1007
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>

using std::cout, std::endl, std::vector, std::pair;
using std::sort, std::unordered_set;

static vector<int> tops { 3, 5, 1, 2, 3 };
static vector<int> bottoms { 3, 6, 3, 3, 4};

namespace Solution {
    class Compare {
        public:
            bool operator() (pair<int,int>& p1, pair<int,int>& p2) const { return p1.second > p2.second; }
    };
    class Program {
        public:
            int minDominoRotations(vector<int>& tops, vector<int>& bottoms);
    };

    int Program::minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<pair<int,int>> dict;
        vector<unordered_set<int>> pos;
        for (int i=0; i<12; i++) {
            dict.push_back({i+1, 0});
            pos.push_back(unordered_set<int>());
        }

        for (int i=0; i<tops.size(); i++) {
            dict[tops[i]-1].second++;
            dict[bottoms[i]+5].second++;
            pos[tops[i]-1].insert(i);
            pos[bottoms[i]+5].insert(i);
        }

        Compare cmp;
        sort(dict.begin(), dict.end(), cmp);

        for (int i=0; i<12; i++) {
            int idx = dict[i].first-1;

            int count = tops.size() - dict[i].second;
            if (idx > 5) {
                for (auto it=pos[idx-6].begin(); it!=pos[idx-5].end() && count > 0; it++)
                    if (!pos[idx].contains(*it)) count--;
            }

            if (idx <= 5) {
                for (auto it=pos[idx+6].begin(); it!=pos[idx+5].end() && count > 0; it++) {
                    if (!pos[idx].contains(*it)) count--;
                }
            }

            if (count <= 0) return tops.size()-dict[i].second;
        }
        return -1;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.minDominoRotations(tops, bottoms) << endl;
    return 0;
}