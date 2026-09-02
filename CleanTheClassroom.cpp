// LeetCode 3568
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <unordered_set>
#include <queue>

using std::cout, std::endl, std::vector, std::string, std::pair, std::unordered_set;

static vector<string> classroom { "LS", "RL" };
static int energy = 2;

namespace Solution {
    class PairHash {
        public:
            std::size_t operator()(const std::pair<int, int>& p) const noexcept {
                auto h1 = std::hash<int>{}(p.first);
                auto h2 = std::hash<int>{}(p.second);
                return h1 ^ (h2 << 1);
            }
    };

    class state {
        public:
            int x;
            int y;
            int energy;
            int litter;
            int steps;
            unordered_set<pair<int,int>, PairHash> set; // This keeps track of the litter that we cleaned up
    };

    class Program {
        private:
            int bfs(vector<vector<vector<int>>>& dp, pair<int,int>& startPos, vector<string>& clasroom, int numLitter, int energy);
        public:
            int minMoves(vector<string>& classroom, int energy);
    };

    int Program::bfs(vector<vector<vector<int>>>& dp, pair<int, int>& startPos, vector<string>& clasroom, int numLitter, int energy) {
        int maxRow = classroom.size() - 1;
        int maxCol = classroom[0].size() - 1;


        std::queue<state> bfsQ;
        bfsQ.push(state { startPos.first, startPos.second, energy, 0, 0, unordered_set<pair<int,int>, PairHash>() });
        vector<int> dx { -1, 0, 1, 0 };
        vector<int> dy { 0, -1, 0, 1 };


        int minSteps = INT_MAX;
        while (!bfsQ.empty()) {
            state st = bfsQ.front();
            bfsQ.pop();

            dp[st.x][st.y][st.litter] = st.energy;
            if (st.litter == numLitter) minSteps = std::min(minSteps, st.steps);
            if (classroom[st.x][st.y] == 'L' && !st.set.contains({ st.x, st.y })) st.set.insert({ st.x, st.y });

            //cout << "Curr State: x = " << st.x << ", y = " << st.y << ", litter = " << st.litter << ", energy = " << st.energy << ", steps = " << st.steps << endl;

            if (st.energy <= 0) continue;
            
            for (int i=0; i<4; i++) {
                int newX = st.x + dx[i];
                int newY = st.y + dy[i];
                
                if (newX < 0 || newX > maxRow || newY < 0 || newY > maxCol) continue;
                if (classroom[newX][newY] == 'X') continue;

                int newLitter = (classroom[newX][newY] == 'L' && !st.set.contains({ newX, newY })) ? st.litter+1 : st.litter;
                int newEnergy = (classroom[newX][newY] == 'R') ? energy : st.energy-1;
                
                if (newEnergy < 0 || newLitter > numLitter) continue;

                if (dp[newX][newY][newLitter] < newEnergy) bfsQ.push(state { newX, newY, newEnergy, newLitter, 
                                                                             st.steps+1, unordered_set<pair<int, int>, PairHash>(st.set) });
            }
        }

        return (minSteps == INT_MAX) ? -1 : minSteps;
    }

    int Program::minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size() - 1;
        int n = classroom[0].size() - 1;
        
        unordered_set<pair<int,int>, PairHash> vis;
        int numLitter = 0;
        pair<int,int> startPos { -1, -1 };

        // Find The Starting Position
        for (int i=0; i<classroom.size(); i++) {
            for (int j=0; j<classroom[i].size(); j++) {
                if (classroom[i][j] == 'S') startPos = { i , j };
                if (classroom[i][j] == 'L') numLitter++;
            }
        }

        vector<vector<vector<int>>> dp(classroom.size(), vector<vector<int>>(classroom[0].size(), vector<int>(numLitter+1, INT_MIN)));
        return bfs(dp, startPos, classroom, numLitter, energy);
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.minMoves(classroom, energy) << endl;
    return 0;
}
