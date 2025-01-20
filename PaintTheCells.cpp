// LeetCode 2661
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::cout, std::endl;
using std::vector, std::unordered_map;
using std::pair;

static vector<int> arr { 1, 3, 4, 2 };
static vector<vector<int>> mat { { 1, 4 }, { 2, 3 } };
static vector<int> arr1 { 2, 8, 7, 4, 1, 3, 5, 6, 9 };
static vector<vector<int>> mat1 { { 3, 2, 5 }, { 1, 4, 6 }, { 8, 7, 9 } };

namespace Solution {
    class Program {
        public:
            int firstCompleteindex(vector<int>& arr, vector<vector<int>>& mat);
    };

    int Program::firstCompleteindex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, int> count;
        unordered_map< int, pair<int,int> > index;
        for (int i=0; i<mat.size(); i++) {
            count[i] = mat.size();
            for (int j=0; j<mat[0].size(); j++) {
                count[i+mat.size()] = mat[0].size();
                index[mat[i][j]] = { i, j+mat.size() };
            }
        }

        for (int i=0; i<arr.size(); i++) {
            int row = index[arr[i]].first;
            int col = index[arr[i]].second; // col = col + mat.size()
            count[row]--;
            count[col]--;
            if (count[row] <= 0 || count[col] <= 0) return i;
        }
        return arr.size()-1;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.firstCompleteindex(arr, mat) << endl;
    cout << obj.firstCompleteindex(arr1, mat1) << endl;
    return 0;
}