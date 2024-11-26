// LeetCode 773
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <utility>
#include <queue>

using std::cout, std::endl, std::string;
using std::unordered_map, std::vector;
using std::to_string, std::pair, std::make_pair;
using std::queue;

static vector<vector<int>> board 
{
    { 1, 2, 3 },
    { 4, 0, 5 }
};

static vector<vector<int>> board1 
{
    { 4, 1, 2 },
    { 5, 0, 3 }
};

static vector<vector<int>> board2 
{
    { 1, 2, 3 },
    { 5, 0, 3 }
};

enum Direction { NORTH=-1, SOUTH=1, EAST=2, WEST=-2, STOP=0 };

namespace Solution {
    class Program {
        public:
            int slidingPuzzle(vector<vector<int>>& board);
            void BFS(queue<vector<vector<int>>>& bfsQ, vector<vector<int>>& currentBoard, pair<int,int> zeroPos, unordered_map<string, int>& visited);
            void Swap (vector<vector<int>>& currentBoard, vector<vector<int>>& tempBoard, pair<int,int> zeroPos, Direction dir);
            string Stringify(vector<vector<int>>& currentBoard);
    };

    int Program::slidingPuzzle(vector<vector<int>>& board) {
        pair<int, int> zeroPos;
        unordered_map<string, int> visited; // map will store as visited[currentstate] = parentState
        vector<vector<int>> currentBoard (board);
        queue< vector<vector<int>> > bfsQ;
        string target = "123450";
        string start = "";
        for(int i=0 ; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                if (board[i][j] == 0) zeroPos = make_pair(i, j);
                string start = "";
            }
        }
        bfsQ.push(currentBoard);
        visited[this->Stringify(currentBoard)] = 0;
        if (start == target) return 0;

        int moves = 0;
        while (!bfsQ.empty()) {
            currentBoard = bfsQ.front();
            if (this->Stringify(bfsQ.front()) == target) break;

            // Find Zero Position
            for(int i=0 ; i<currentBoard.size(); i++)
                for (int j=0; j<currentBoard[i].size(); j++)
                    if (currentBoard[i][j] == 0) zeroPos = make_pair(i, j);
            
            // BFS Search
            BFS(bfsQ, currentBoard, zeroPos, visited);
            bfsQ.pop();
        }
        if (!visited.contains(target)) return -1;
        return visited[target];
    }

    string Program::Stringify(vector<vector<int>>& board) {
        string s = "";
        for(int i=0 ; i<board.size(); i++)
            for (int j=0; j<board[i].size(); j++)
                s += to_string(board[i][j]);
        return s;
    }

    void Program::BFS(queue< vector<vector<int>> >& bfsQ, vector<vector<int>>& currentBoard, pair<int,int> zeroPos, unordered_map<string, int>& visited)
    {
        vector<vector<int>> tempBoard (currentBoard);
        string s;
        if (zeroPos.first-1 >= 0) {
            this->Swap(currentBoard, tempBoard, zeroPos, NORTH);
            s = this->Stringify(tempBoard);
            if (!visited.contains(s)) {
                bfsQ.push(vector<vector<int>> (tempBoard));
                visited[s] = visited[this->Stringify(currentBoard)]+1;
            }
        }
        if (zeroPos.first+1 < currentBoard.size()) {
            this->Swap(currentBoard, tempBoard, zeroPos, SOUTH);
            s = this->Stringify(tempBoard);
            if (!visited.contains(s)) {
                bfsQ.push(vector<vector<int>> (tempBoard));
                visited[s] = visited[this->Stringify(currentBoard)]+1;
            }
        }
        if (zeroPos.second-1 >= 0) {
            this->Swap(currentBoard, tempBoard, zeroPos, WEST);
            s = this->Stringify(tempBoard);
            if (!visited.contains(s)) {
                bfsQ.push(vector<vector<int>> (tempBoard));
                visited[s] = visited[this->Stringify(currentBoard)]+1;
            }
        }
        if (zeroPos.second+1 < currentBoard[0].size()) {
            this->Swap(currentBoard, tempBoard, zeroPos, EAST);
            s = this->Stringify(tempBoard);
            if (!visited.contains(s)) {
                bfsQ.push(vector<vector<int>> (tempBoard));
                visited[s] = visited[this->Stringify(currentBoard)]+1;
            }
        }
        return;
    }

    void Program::Swap(vector<vector<int>>& currentBoard, vector<vector<int>>& tempBoard, pair<int,int> zeroPos, Direction dir) {
        // dir = 1, -1 swap down or up
        // dir = 2, -2 swap left or right
        vector<vector<int>> copy (currentBoard);
        if (dir == STOP) return;
        pair<int,int> newPos (zeroPos);
        if (dir == NORTH || dir == SOUTH) newPos.first += dir;
        if (dir == WEST || dir == EAST) newPos.second += (dir/2);

        // Swap
        int swap = copy[newPos.first][newPos.second];
        copy[zeroPos.first][zeroPos.second] = swap;
        copy[newPos.first][newPos.second] = 0;
        tempBoard = copy;
        return;
    }
}

int main () {
    using namespace Solution;
    Program obj;
    cout << obj.slidingPuzzle(board) << endl;
    cout << obj.slidingPuzzle(board1) << endl;
    cout << obj.slidingPuzzle(board2) << endl;
    return 0;
}