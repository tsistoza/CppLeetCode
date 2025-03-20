// LeetCode 130
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
#include <queue>

using std::cout, std::endl, std::vector;
using std::pair, std::unordered_set, std::queue;

static vector<vector<char>> board { { 'X', 'X', 'X', 'X' }, 
                                    { 'X', 'O', 'O', 'X' },
                                    { 'X', 'X', 'O', 'X' },
                                    { 'X', 'O', 'X', 'X' } };

namespace Solution {
    class PairHash {
        public:
            size_t operator() (const pair<int, int>& p) const {
                return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
            }
    };
    class Program {
        private:
            void flipRegion(vector<pair<int,int>>& region, vector<vector<char>>& board);
            void findRegion(vector<pair<int,int>>& region, unordered_set<pair<int,int>, PairHash>& vis, vector<vector<char>>& board);
        public:
            static void prettyPrint(vector<vector<char>>& board);
            void solve(vector<vector<char>>& board);
    };

    void Program::prettyPrint(vector<vector<char>>& board) {
        cout << "{ ";
        for (int i=0; i<board.size(); i++) {
            cout << " { ";
            for (int j=0; j<board[i].size(); j++)
                cout << board[i][j] << ", ";
            cout << "}" << endl;
        }
        cout << " }" << endl;
        return;
    }

    void Program::flipRegion(vector<pair<int,int>>& region, vector<vector<char>>& board) {
        for (int i=0; i<region.size(); i++)
            board[region[i].first][region[i].second] = 'X';
        return;
    }

    void Program::findRegion(vector<pair<int,int>>& region, unordered_set<pair<int,int>, PairHash>& vis, vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        q.push(region.back());
        vector<int> dirX { -1, 0, 1, 0 };
        vector<int> dirY { 0, -1, 0, 1 };

        // Get Neighbors
        while(!q.empty()) {
            pair<int,int> curr = q.front();
            q.pop();
            for (int i=0; i<4; i++) {
                pair<int,int> neighbor = { curr.first+dirX[i], curr.second+dirY[i] };
                if (vis.contains(neighbor) || board[neighbor.first][neighbor.second] == 'X') continue;
                if ((neighbor.first == 0 || neighbor.second == 0) && board[neighbor.first][neighbor.second] == 'O') {
                    while(!q.empty()) q.pop();
                    region.clear();
                    break;
                }
                vis.insert({neighbor});
                region.push_back(neighbor);
                q.push(neighbor);
            }
        }

        return;
    }

    void Program::solve(vector<vector<char>>& board) {
        unordered_set<pair<int,int>, PairHash> vis;
        vector<pair<int,int>> region;
        for (int i=1; i<board.size()-1; i++) {
            for (int j=1; j<board[i].size()-1; j++) {
                if (board[i][j] == 'X') continue;
                if (vis.contains({i, j})) continue;
                region.push_back({ i, j });
                vis.insert({ i, j });
                findRegion(region, vis, board);
                flipRegion(region, board);
                region.clear();
            }
        }
        return;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    obj.solve(board);
    Program::prettyPrint(board);
}