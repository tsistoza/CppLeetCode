// LeetCode 909
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using std::cout, std::endl, std::vector;
using std::pair, std::unordered_map, std::deque;
using std::unordered_set;

static vector<vector<int>> board { { -1, -1, -1, -1, -1, -1 },
                                   { -1, -1, -1, -1, -1, -1 },
                                   { -1, -1, -1, -1, -1, -1 },
                                   { -1, 35, -1, -1, 13, -1 },
                                   { -1, -1, -1, -1, -1, -1 },
                                   { -1, 15, -1, -1, -1, -1 } };
static vector<vector<int>> board1 { { -1, -1 }, { -1, 3 } };

class Tuple {
    public:
        int square;
        int diceRolls;
        unordered_set<int> vis;

        Tuple(int _square, int _diceRolls, unordered_set<int> _vis) : square(_square), diceRolls(_diceRolls), vis(_vis) {}
        Tuple() {}
};

namespace Solution {
    class Program {
        private:
            void bfs(vector<vector<int>>& board, unordered_map<int, pair<int,int>>& squareToIndex, int* ptr);
        public:
            int snakesAndLadders(vector<vector<int>>& board);
    };

    void Program::bfs(vector<vector<int>>& board, unordered_map<int, pair<int,int>>& squareToIndex, int* ptr) {
        deque<Tuple> bfsQ;
        bfsQ.push_front(Tuple(1, 0, unordered_set<int>()));
        
        while(!bfsQ.empty()) {
            Tuple curr = bfsQ.front();
            bfsQ.pop_front();
            curr.vis.insert(curr.square);
            if (curr.square == board.size()*board.size() && *ptr > curr.diceRolls) {
                *ptr = curr.diceRolls;
                continue;
            }

            // Choose a dice roll
            bool priority = false;
            for (int i=6; i>0; i--) {
                if (curr.square + i > board.size()*board.size()) continue;
                
                pair<int,int> newIndex = squareToIndex[curr.square + i];
                if (curr.vis.contains(board[newIndex.first][newIndex.second])) continue;

                if (board[newIndex.first][newIndex.second] == -1 && !priority) {
                    bfsQ.push_back(Tuple(curr.square+i, curr.diceRolls+1, unordered_set<int>(curr.vis)));
                    priority = !priority;
                }

                if (board[newIndex.first][newIndex.second] != -1)
                    bfsQ.push_front(Tuple(board[newIndex.first][newIndex.second], curr.diceRolls+1, unordered_set<int>(curr.vis)));
            }
        }
        return;
    }

    int Program::snakesAndLadders(vector<vector<int>>& board) {
        unordered_map<int, pair<int,int>> squareToIndex;
        
        bool zag = false;
        int square = board.size()*board.size();
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board.size() && !zag; j++)
                squareToIndex[square--] = { i, j };

            for (int j=board.size()-1; j>=0 && zag; j--)
                squareToIndex[square--] = { i, j };

            zag = !zag;
        }

        int count = INT_MAX;
        int* ptr = &count;
        bfs(board, squareToIndex, ptr);
        return count;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.snakesAndLadders(board) << endl;
    cout << obj.snakesAndLadders(board1) << endl;
    return 0;
}