// LeetCode 73
#include <iostream>
#include <vector>
#include <utility>

using std::cout, std::endl;
using std::vector, std::pair;

static vector<vector<int>> matrix { {1, 1, 1}, {1, 0, 1}, {1, 1, 1} };
static vector<vector<int>> matrix1 { {0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5} };

namespace Solution {
    class Program {
        private:
            void prettyPrint(vector<vector<int>>& matrix);
        public:
            void setZeroes(vector<vector<int>>& matrix);
    };

    void Program::setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> table;
        for (int i=0; i<matrix.size(); i++)
            for (int j=0; j<matrix[0].size(); j++)
                if(matrix[i][j] == 0) table.push_back(pair<int,int> {i, j});

        for (auto it = table.begin(); it!=table.end(); it++) {
            int row = it->first;
            int col = it->second;
            for (int newCol=0; newCol<matrix[0].size(); newCol++)
                matrix[row][newCol] = 0;
            for (int newRow=0; newRow<matrix.size(); newRow++)
                matrix[newRow][col] = 0;
        }
        prettyPrint(matrix);
        return;
    }

    void Program::prettyPrint(vector<vector<int>>& matrix) {
        cout << "{";
        for (vector<vector<int>>::iterator it=matrix.begin(); it!=matrix.end(); it++){
            cout << " { ";
            for (vector<int>::iterator it2=it->begin(); it2!=it->end(); it2++)
                cout << *it2 << " ";
            cout << "},";
        }
        cout << " }" << endl;
        return;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    obj.setZeroes(matrix);
    cout << endl;
    obj.setZeroes(matrix1);
    return 0;
}