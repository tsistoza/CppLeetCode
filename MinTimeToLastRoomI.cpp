// LeetCode 3341
#include <iostream>
#include <vector>
#include <queue>

using std::cout, std::endl, std::vector;
using std::priority_queue;

static vector<vector<int>> moveTime { { 0, 1 }, { 1, 2 } };

namespace Solution {
    class Compare {
        public:
            bool operator() (vector<int>& t1, vector<int>& t2) const { return t1[0] > t2[0]; }
    };
    class Program {
        public:
            int minTimeToReach(vector<vector<int>>& moveTime);
    };

    int Program::minTimeToReach(vector<vector<int>>& moveTime) {
        int time = INT_MAX;
        priority_queue<vector<int>, vector<vector<int>>, Compare> heap;
        heap.push(vector<int> { 0, 0, 0 }); // Tuple -> (time, x, y)

        while (!heap.empty()) {
            vector<int> curr = heap.top();
            heap.pop();
            int currTime = curr[0], x = curr[1], y = curr[2];

            if (x == moveTime.size()-1 && y == moveTime[0].size()-1) { // all we care about is the minTime to this node so just break
                time = (time < currTime) ? time : currTime;
                break;
            }
            
            vector<int> dirX { -1, 0, 1, 0 };
            vector<int> dirY { 0, -1, 0, 1 };
            for (int i=0; i<4; i++) { // Get the adjacent rooms
                int newX = x + dirX[i];
                int newY = y + dirY[i];
                int newTime = currTime;
                if (newX < 0 || newY < 0 || newX >= moveTime.size() || newY >= moveTime[0].size()) continue;

                if (newTime < moveTime[newX][newY]) newTime = moveTime[newX][newY]+1;
                else newTime = currTime+1;
                
                heap.push(vector<int> {newTime, newX, newY});
            }
        }
        return time;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.minTimeToReach(moveTime) << endl;
    return 0;
}