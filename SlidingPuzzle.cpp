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

enum Direction { NORTH=-1, SOUTH=1, EAST=2, WEST=-2, STOP=0 };

namespace Solution {
    class Program {
        public:
            int slidingPuzzle(vector<vector<int>>& board);
            void BFS(vector<vector<int>> currentBoard, unordered_map<string, string>& visited, pair<int,int> zeroPos, Direction dir);
            void Swap (vector<vector<int>>& currentBoard, pair<int,int>& zeroPos, Direction dir);
            string Stringify(vector<vector<int>>& currentBoard);
    };

    int Program::slidingPuzzle(vector<vector<int>>& board) {
        pair<int, int> zeroPos;
        unordered_map<string, string> visited; // map will store as visited[currentstate] = parentState
        vector<vector<int>> currentBoard (board);
        
        string target = "123450";
        string start = "";
        for(int i=0 ; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                if (board[i][j] == 0) zeroPos = make_pair(i, j);
                start += to_string(board[i][j]);
            }
        }

        if (start == target) return 0;
        
        BFS(currentBoard, visited, zeroPos, STOP);
        if (!visited.contains(target)) return -1;

        int moves = 0;
        while (start != target) {
            target = visited[target];
            cout << target << endl;
            moves++;
        }
        return moves;
    }

    string Program::Stringify(vector<vector<int>>& board) {
        string s = "";
        for(int i=0 ; i<board.size(); i++)
            for (int j=0; j<board[i].size(); j++)
                s += to_string(board[i][j]);
        return s;
    }

    // Swap zero around, and save this as a state along with the zero position,
    // For each state, you want to swap again in the 4 adjacent cells (north,south,west,east), save this as a state as well
    // And just keep repeating till we find the target state
    void Program::BFS(vector<vector<int>> currentBoard, unordered_map<string, string>& visited, pair<int,int> zeroPos, Direction dir) {
        string target = "123450";
        // If at any point the target is found stop BFS
        if (visited.contains(target)) return;
        
        vector<vector<int>> tempBoard (currentBoard);
        this->Swap(tempBoard, zeroPos, dir);
        string s = "";
        for(int i=0 ; i<tempBoard.size(); i++)
            for (int j=0; j<tempBoard[i].size(); j++)
                s += to_string(tempBoard[i][j]);
        
        if (visited.contains(s)) return;
        visited[s] = this->Stringify(currentBoard);

        // Traverse States
        if (zeroPos.first-1 >= 0) this->BFS(tempBoard, visited, zeroPos, NORTH);
        if (zeroPos.first+1 < tempBoard.size()) this->BFS(tempBoard, visited, zeroPos, SOUTH);
        if (zeroPos.second-1 >= 0) this->BFS(tempBoard, visited, zeroPos, WEST);
        if (zeroPos.second+1 < tempBoard[0].size()) this->BFS(tempBoard, visited, zeroPos, EAST);
        return;
    }

    void Program::Swap(vector<vector<int>>& currentBoard, pair<int,int>& zeroPos, Direction dir) {
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
        currentBoard = copy;
        zeroPos = newPos;
        return;
    }
}

int main () {
    using namespace Solution;
    Program obj;
    cout << obj.slidingPuzzle(board) << endl;
    cout << obj.slidingPuzzle(board1) << endl;
    return 0;
}