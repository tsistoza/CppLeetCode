// LeetCode 1391
#include <iostream>
#include <vector>
#include <functional>
#include <unordered_set>
#include <utility>

using std::cout, std::endl, std::vector, std::boolalpha, std::unordered_set, std::hash;

static vector<vector<int>> grid { { 1, 1, 2 } };

// Boost library hash
static inline void hash_combine(std::size_t& seed, const int& v) {
    hash<int> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

namespace Solution {
    struct pair_hash {
        std::size_t operator()(const std::pair<int, int>& p) const {
            std::size_t seed = 0;
            hash_combine(seed, p.first);
            hash_combine(seed, p.second);
            return seed;
        }
    };
    class Util {
        private:
            Util() {}

            static vector<vector<int>> dir1;
            static vector<vector<int>> dir2;
            static vector<vector<int>> dir3;
            static vector<vector<int>> dir4;
            static vector<vector<int>> dir5;
            static vector<vector<int>> dir6;
        
        public:
            static vector<vector<int>> GetDirection(int number);
            static bool isConnected(int currNumber, int nextNumber, vector<int> direction);
    };
    class Program {
        private:
            void dfs(unordered_set<std::pair<int,int>, pair_hash>& vis, vector<vector<int>>& grid, bool* result, int row, int col);
            
        public:
            bool hasValidPath(vector<vector<int>>& grid);
    };

    bool Program::hasValidPath(vector<vector<int>>& grid) {
        bool result = false;
        unordered_set<std::pair<int,int>, pair_hash> vis;
        dfs(vis, grid, &result, 0, 0);
        return result;
    }

    void Program::dfs(unordered_set<std::pair<int,int>, pair_hash>& vis, vector<vector<int>>& grid, bool* result, int row, int col) {
        if (*result) return;
        if (vis.contains(std::pair<int, int> (row, col))) return;
        vis.insert(std::pair<int, int> (row, col));
        if (row == grid.size()-1 && col == grid[0].size()-1) {
            *result = true;
            return;
        }

        for (vector<int> v : Util::GetDirection(grid[row][col])) {
            int newRow = row + v[0];
            int newCol = col + v[1];

            if (newRow >= grid.size() || newCol >= grid[0].size() || newRow < 0 || newCol < 0) continue;
            if (vis.contains(std::pair<int, int>(newRow, newCol))) continue;
            if (!Util::isConnected(grid[row][col], grid[newRow][newCol], v)) continue;
            dfs(vis, grid, result, newRow, newCol);
        }
        return;
    }

    vector<vector<int>> Util::dir1 = { { 0, -1 }, { 0, 1 } };
    vector<vector<int>> Util::dir2 = { { -1, 0 }, { 1, 0 } };
    vector<vector<int>> Util::dir3 = { { 0, -1 }, { 1, 0 } };
    vector<vector<int>> Util::dir4 = { { 0, 1 }, { 1, 0 } };
    vector<vector<int>> Util::dir5 = { { 0, -1 }, { -1, 0 } };
    vector<vector<int>> Util::dir6 = { { 0, 1 }, { -1, 0 } };

    vector<vector<int>> Util::GetDirection(int number) {
        switch(number) {
            case 1: return dir1;
                break;
            case 2: return dir2;
                break;
            case 3: return dir3;
                break;
            case 4: return dir4;
                break;
            case 5: return dir5;
                break;
            case 6: return dir6;
                break;
            default:
                break;
        }

        return vector<vector<int>> { { 0, 0 } };
    }

    bool Util::isConnected(int currNumber, int nextNumber, vector<int> direction) {
        for (vector<int> dir : GetDirection(nextNumber)) // Streets connected if dir negative = the next street direction
            if (-dir[0] == direction[0] || -dir[1] == direction[1]) return true;
        return false;
    }

    
}

int main() {
    using namespace Solution;
    Program obj;
    cout << boolalpha << obj.hasValidPath(grid) << endl;
    return 0;
}