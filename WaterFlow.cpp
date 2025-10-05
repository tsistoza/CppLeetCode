// LeetCode 417
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>
#define DEBUG false

// Compile with std: C++20

using std::cout, std::endl, std::vector;
using std::queue, std::unordered_set, std::hash;

static vector<vector<int>> heights { {1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4} };

namespace Solution {
    class VectorHasher {
        public:
            size_t operator()(const vector<int>& vec) const {
                size_t hashVal = vec.size();
                for (int i : vec) 
                    hashVal ^= hash<int>{}(i) + 0x9e3779b9 + (hashVal<< 6) + (hashVal >> 2);
                return hashVal;
            }
    };

    class Program {
        private:
            void dfs(vector<vector<int>>& heights, unordered_set<vector<int>, VectorHasher>& pac, 
                     unordered_set<vector<int>, VectorHasher>& atl, unordered_set<vector<int>, VectorHasher> vis,
                     vector<int> index, vector<int> origin);
        public:
            vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights);
            static void prettyPrint(vector<vector<int>> results);
    };

    void Program::prettyPrint(vector<vector<int>> results) {
        cout << "results length:" << results.size() << endl;
        cout << "{ ";
        for (int i=0; i<results.size(); i++) {
            cout << "{ ";
            for(int j=0; j<results[i].size(); j++) {
                cout << results[i][j] << " ";
            }
            cout << "} ";
        }
        cout << "}" << endl;
        return;
    }

    void Program::dfs(vector<vector<int>>& heights, unordered_set<vector<int>, VectorHasher>& pac, 
                      unordered_set<vector<int>, VectorHasher>& atl, unordered_set<vector<int>, VectorHasher> vis,
                      vector<int> index, vector<int> origin) {
        
        if (vis.contains(index)) return;
        else vis.insert(index);

        vector<int> dirX { -1, 0, 1, 0 };
        vector<int> dirY { 0, -1, 0, 1 };

#if DEBUG
        if (origin[0] == 1 && origin[1] == 4) {
            cout << index[0] << " " << index[1] << endl;
        }
#endif

        for (int i=0; i<4; i++) {
            int x = index[0]+dirX[i];
            int y = index[1]+dirY[i];

            if (x < 0 || y < 0) {
                pac.insert(origin);
                continue;
            }
            if (x >= heights.size() || y >= heights[0].size()) {
                atl.insert(origin);
                continue;
            }

            if (heights[index[0]][index[1]] < heights[x][y]) continue;

            vector<int> newIndex { x, y };
            if (pac.contains(newIndex)) pac.insert(origin);
            if (atl.contains(newIndex)) atl.insert(origin);
            if (pac.contains(newIndex) && atl.contains(newIndex)) continue;
            dfs(heights, pac, atl, vis, newIndex, origin);
        }
        return;
    }

    vector<vector<int>> Program::pacificAtlantic(vector<vector<int>>& heights) {
        unordered_set<vector<int>, VectorHasher> pac;
        unordered_set<vector<int>, VectorHasher> atl;

        // Corners bottomleft, topright
        pac.insert(vector<int> { (int)heights.size()-1, 0 });
        pac.insert(vector<int> { 0, (int)heights.size()-1 });
        atl.insert(vector<int> { (int)heights.size()-1, 0 });
        atl.insert(vector<int> { 0, (int)heights.size()-1 });

        for (int i=0; i<heights.size(); i++) {
            for(int j=0; j<heights[i].size(); j++) {
                vector<int> idx { i, j };
                dfs(heights, pac, atl, unordered_set<vector<int>, VectorHasher>(), idx, idx);
            }
        }

        vector<vector<int>> results;
        for (vector<int> vec : pac)
            if (atl.contains(vec))
                results.push_back(vec);
        return results;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    Program::prettyPrint(obj.pacificAtlantic(heights));
    return 0;
}