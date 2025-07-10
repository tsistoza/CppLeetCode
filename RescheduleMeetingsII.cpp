// LeetCode 3440
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector, std::pair;
using std::sort;

static int eventTime = 10;
static vector<int> startTime { 0, 7, 9 };
static vector<int> endTime { 1, 8, 10 };

namespace Solution {
    class Compare {
        public:
            bool operator() (pair<int,int>& p1, pair<int,int>& p2) const { return (p1.second - p1.first) > (p2.second-p2.first); }
    };
    class Program {
        public:
            pair<vector<int>::iterator, vector<int>::iterator> findOccupied(int size, vector<int>& startTime, vector<int>& endTime, int idx1, int idx2);
            int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime);
    };

    pair<vector<int>::iterator, vector<int>::iterator> Program::findOccupied(int size, vector<int>& startTime, vector<int>& endTime, int idx1, int idx2) {
        for (int i=0; i<startTime.size(); i++) {
            if (endTime[i]-startTime[i] != size) continue;
            if (endTime[i] != idx1 && startTime[i] != idx2) continue;
            return { startTime.begin()+i, endTime.begin()+i }; 
        }
        return { startTime.end(), endTime.end() };
    }

    int Program::maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<pair<int,int>> openSpots;

        // check start
        int start=0, end=startTime[0], idx=0;
        if (end-start > 0) openSpots.push_back({start, end});

        for ( ;idx<startTime.size();) {
            //range
            start = endTime[idx];
            if (idx+1 >= startTime.size()) break;
            end = startTime[idx+1];
            if (end-start > 0) openSpots.push_back({ start, end });
            idx++;
        }

        // check back
        if (endTime[idx] < eventTime) {
            start = endTime[idx];
            end = eventTime;
            openSpots.push_back({ start, end });
        }

        Compare cmp;
        sort(openSpots.begin(), openSpots.end(), cmp);

        if (openSpots.size() == 1) return (openSpots[0].second - openSpots[0].first);

        vector<pair<int,int>>::iterator it = openSpots.begin()+1;
        int k = 0;
        while (openSpots.size() > 1 && k<=0 && it!=openSpots.end()) {
            int size = it->second - it->first;
            pair<vector<int>::iterator, vector<int>::iterator> iters = findOccupied(size, startTime, endTime, openSpots[0].first, openSpots[0].second);
            if (iters.first == startTime.end()) {
                it++;
                continue;
            }

            if (*(iters.first) == openSpots[0].second)
                openSpots[0] = { openSpots[0].first, *(iters.second) };
            if (*(iters.second) == openSpots[0].first)
                openSpots[0] = { *(iters.first), openSpots[0].second };

            it = openSpots.erase(it);
            startTime.erase(iters.first);
            endTime.erase(iters.second);
            k++;
        }

        return (openSpots[0].second - openSpots[0].first);
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.maxFreeTime(eventTime, startTime, endTime) << endl;
    return 0;
}