// LeetCode 2257
#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

static const int m = 4;
static const int n = 6;
static vector<vector<int>> guards { {0, 0}, {1, 1}, {2, 3} };
static vector<vector<int>> walls { {0, 1}, {2, 2}, {1, 4} };

static const int m1 = 3;
static const int n1 = 3;
static vector<vector<int>> guards1 { {1, 1} };
static vector<vector<int>> walls1 { {0, 1}, {1, 0}, {2, 1}, {1, 2} };

namespace Solution {
    class Program {
        public:
            int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls);
            int checkCardinalityVertical(vector<vector<int>>& grid, int posX, int posY, int m);
            int checkCardinalityHorizontal(vector<vector<int>>& grid, int posX, int posY, int n);
    };

    int Program::countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int unguardedCells = (m*n) - guards.size() - walls.size();
        vector<vector<int>> grid ( m ,vector<int>(n, 0) );
        
        // Create the grid with 1 being the guard, and 2 being a wall
        for (int i=0; i<walls.size(); i++)
            grid[walls[i][0]][walls[i][1]] = 2;
        for (int i=0; i<guards.size(); i++)
            grid[guards[i][0]][guards[i][1]] = 1;
        
        // Guard Visions
        for (vector<int> guard : guards) {
            unguardedCells -= checkCardinalityVertical(grid, guard[0], guard[1], m);
            unguardedCells -= checkCardinalityHorizontal(grid, guard[0], guard[1], n);
        }
        return unguardedCells;
    }

    // returns the cells that are being watched by the guard (Vertical)
    int Program::checkCardinalityVertical(vector<vector<int>>& grid, int posX, int posY, int m) {
        int cells=0;
        bool walled = false;
        for (int north=posX-1; north>=0; --north) {
            if (grid[north][posX] == 3) continue;
            if (grid[north][posY] == 1 || grid[north][posY] == 2) walled = true;
            if (walled) break;
            cells++;
            grid[north][posX] = 3; // Set to 3, if guard is watching this cell already
        }
        walled = false;
        for (int south=posX+1; south<m; ++south) {
            if (grid[south][posX] == 3) continue;
            if (grid[south][posY] == 1 || grid[south][posY] == 2) walled = true;
            if (walled) break;
            cells++;
            grid[south][posY] = 3;
        }
        return cells;
    }

    // Same function above except moving horizontally
    int Program::checkCardinalityHorizontal(vector<vector<int>>& grid, int posX, int posY, int n) {
        int cells=0;
        bool walled = false;
        for (int west=posY-1; west>=0; --west) {
            if (grid[posX][west] == 3) continue;
            if (grid[posX][west] == 1 || grid[posX][west] == 2) walled = true;
            if (walled) break;
            cells++;
            grid[posX][west] = 3;
        }
        walled = false;
        for (int east=posY+1; east<n; ++east) {
            if (grid[posX][east] == 3) continue;
            if (grid[posX][east] == 1 || grid[posX][east] == 2) walled = true;
            if (walled) break;
            cells++;
            grid[posX][east] = 3;
        }
        return cells;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.countUnguarded(m, n, guards, walls) << endl;
    cout << obj.countUnguarded(m1, n1, guards1, walls1) << endl;
    return 0;
}