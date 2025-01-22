// LeetCode 1765
#include <iostream>
#include <vector>
#include <utility>

using std::cout, std::endl, std::vector;
using std::pair;

static vector<vector<int>> isWater = { { 0, 1 }, { 0, 0 } };
static vector<vector<int>> isWater1 = { { 0, 0, 1 }, { 1, 0, 0 }, { 0, 0, 0 } };

namespace Solution {
    class Program {
        private:
            bool neighborCheck(pair<int,int> index, vector<vector<int>>& grid, int currHeight);
            void setZero(vector<vector<int>>& result);
        public:
            void prettyPrintArr(vector<vector<int>> & result);
            vector<vector<int>> highestPeak(vector<vector<int>>& isWater);
    };

    void Program::prettyPrintArr(vector<vector<int>>& arr) {
        for (vector<int> vec : arr) {
            for (int i : vec) {
                cout << i << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    bool Program::neighborCheck(pair<int,int> index, vector<vector<int>>& grid, int currHeight) {
        if (grid[index.first][index.second] == 0) return false;
        vector<int> dirRow { -1, 0, 1, 0 };
        vector<int> dirCol { 0, -1, 0, 1 };
        
        for (int i=0; i<4; i++) {
            int newRow = index.first + dirRow[i];
            int newCol = index.second + dirCol[i];

            if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size())
                if (grid[newRow][newCol] < currHeight) return false;
        }
        return true;
    }


    void Program::setZero(vector<vector<int>>& result) {
        for (int i=0; i<result.size(); i++)
            for (int j=0; j<result[i].size(); j++)
                if (result[i][j] == 0) result[i][j] = 1;
                else result[i][j] = 0;
        return;
    }

    vector<vector<int>> Program::highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> result(isWater);
        setZero(result); // set zero cells to one, and one cells to zero
        vector<pair<int,int>> heightAdd;
        
        for (int i=0; i<result.size(); i++)
            for (int j=0; j<result[i].size(); j++)
                if(neighborCheck({i, j}, result, 1)) heightAdd.push_back({i, j}); // Get All Indexes that are possible to increase its height

        int currHeight = 2;
        while (!heightAdd.empty()) { // if vector is empty its impossible to increaes the height any more
            for (pair<int,int> index : heightAdd)
                result[index.first][index.second]++; // increase height

            vector<pair<int,int>>::iterator it = heightAdd.begin();
            for (; it!=heightAdd.end(); ) {
                if(!neighborCheck(*it, result, currHeight)) { // Check indexes again if its still possible, else remove them
                    vector<pair<int,int>>::iterator temp = it;
                    it--;
                    heightAdd.erase(temp);
                }
                it++;
            }
        }

        prettyPrintArr(result);
        return result;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    obj.highestPeak(isWater);
    cout << endl;
    obj.highestPeak(isWater1);
    return 0;
}