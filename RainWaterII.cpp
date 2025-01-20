// LeetCode 407
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using std::cout, std::endl;
using std::vector, std::max;
using std::priority_queue, std::pair;
using std::greater;

static vector<vector<int>> heightMap { { 1, 4, 3, 1, 3, 2 }, { 3, 2, 1, 3, 2, 4 }, { 2, 3, 3, 2, 3, 1 } };

namespace Solution {
    class Program {
        public:
            int trapRainWater(vector<vector<int>>& heightMap);
    };


    int Program::trapRainWater(vector<vector<int>>& heightMap) {
        int totalWater = 0;
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>> > queue;
        vector<vector<int>> visited(n, vector<int> (m, 0));

        for (int i=0; i<m; i++) {
            visited[i][0] = 1; // Left Boundary
            visited[i][n-1] = 1; // Right Boundary
            queue.push({heightMap[i][0], {i, 0}});
            queue.push({heightMap[i][n-1], {i, n-1}});
        }

        for (int i=0; i<n; i++) {
            visited[0][i] = 1; // Top Boundary
            visited[m-1][i] = 1; // Bottom Boundary
            queue.push({heightMap[0][i], {0, i}});
            queue.push({heightMap[m-1][i], {0, i}});
        }

        // Process the queue 
        while (!queue.empty()) {
            int currHeight = queue.top().first;
            int currRow = queue.top().second.first;
            int currCol = queue.top().second.second;
            queue.pop();

            vector<int> dirX { -1, 0, 1, 0 };
            vector<int> dirY { 0, -1, 0, 1 };
            for (int i=0; i<dirX.size(); i++) {
                int neighborRow = currRow + dirX[i];
                int neighborCol = currCol + dirY[i];
                
                if (neighborRow >= 0 && neighborRow < heightMap.size() && neighborCol >= 0 && neighborCol < heightMap[0].size() && visited[neighborRow][neighborCol] != 1) {
                    cout << currRow << " " <<  currCol << endl;
                    cout << "visited = " << visited[neighborRow][neighborCol] << endl;
                    totalWater += max(0, currHeight-heightMap[neighborRow][neighborCol]);
                    queue.push({max(currHeight, heightMap[neighborRow][neighborCol]), {neighborRow, neighborCol}});
                    visited[neighborRow][neighborCol] = 1;
                }
            }
        }
        return totalWater;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.trapRainWater(heightMap) << endl;
    return 0;
}