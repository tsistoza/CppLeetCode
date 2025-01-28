// LeetCode 2658
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_set>

using std::cout, std::endl, std::vector;
using std::queue, std::pair, std::unordered_set;
using std::hash, std::size_t;

static vector<vector<int>> grid { { 0, 2, 1, 0 }, { 4, 0, 0, 3 }, { 1, 0, 0, 4 }, { 0, 3, 2, 0 } };
static vector<vector<int>> grid1 { { 1, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 1 } };


namespace Solution {
    class PairHash {
        public:
            size_t operator() (const pair<int,int> &p) const {
                size_t h1 = std::hash<int>{}(p.first);
                size_t h2 = std::hash<int>{}(p.second);
                return h1^h2;
            }
    };
    class Program {
        private:
            int findFish(pair<int,int> current, vector<vector<int>>& grid);
            void dfs(pair<int,int> current,vector<vector<int>>& grid, unordered_set<pair<int,int>, PairHash>& vis);
            vector<pair<int,int>> getStartingPoints(vector<vector<int>>& grid);
        public:
            int findMaxFish(vector<vector<int>>& grid);
    };

    int Program::findFish(pair<int,int> current, vector<vector<int>>& grid) {
        int fish = 0;
        unordered_set<pair<int,int>, PairHash> vis;
        queue<pair<int,int>> bfsQ;
        bfsQ.push(current);

        while(!bfsQ.empty()) {
            fish += grid[bfsQ.front().first][bfsQ.front().second];
            vis.insert(bfsQ.front());
            bfsQ.pop();

            // Get Neighbors
            vector<int> dirRow { -1, 0, 1, 0 };
            vector<int> dirCol { 0, -1, 0, 1 };
            for (int i=0; i<4; i++) {
                int newRow = current.first + dirRow[i];
                int newCol = current.second + dirCol[i];

                if (newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size()) continue;
                if (vis.contains({newRow, newCol})) continue;
                if (grid[newRow][newCol] == 0) continue;
                bfsQ.push({newRow,newCol});
            }
        }
        return fish;
    }

    void Program::dfs(pair<int,int> current, vector<vector<int>>& grid, unordered_set<pair<int,int>, PairHash>& vis) {
        if (vis.contains(current)) return;
        vis.insert( {current} );

        vector<int> dirRow { -1, 0, 1, 0 };
        vector<int> dirCol { 0, -1, 0, 1 };
        for (int i=0; i<4; i++) {
            int newRow = current.first + dirRow[i];
            int newCol = current.second + dirCol[i];

            if (newRow < 0 || newRow >= grid.size() || newCol < 0 || newCol >= grid[0].size()) continue;
            if (vis.contains({newRow, newCol})) continue;
            if (grid[newRow][newCol] == 0) continue;
            dfs({ newRow, newCol }, grid, vis);
        }
        return;
    }

    vector<pair<int,int>> Program::getStartingPoints(vector<vector<int>>& grid) {
        vector<pair<int,int>> startPts;
        unordered_set<pair<int,int>, PairHash> vis;
        for (int i=0; i<grid.size(); i++)
            for (int j=0; j<grid[i].size(); j++)
                if (grid[i][j] > 0 && !vis.contains({ i, j })) {
                    dfs({ i, j }, grid, vis);
                    startPts.push_back({i, j});
                }
        return startPts;
    }


    int Program::findMaxFish(vector<vector<int>>& grid) {
        int maxFish = INT_MIN;
        vector<pair<int,int>> startPts = getStartingPoints(grid);
        for (pair<int,int> p : startPts) {
            int fishCaught = findFish(p, grid);
            maxFish = (maxFish < fishCaught) ? fishCaught : maxFish;
        }
        return maxFish;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.findMaxFish(grid) << endl;
    cout << obj.findMaxFish(grid1) << endl;
    return 0;
}   