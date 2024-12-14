// LeetCode 54
#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

static vector<vector<int>> matrix { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
static vector<vector<int>> matrix1 { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };

namespace Solution {
    class Program {
        public:
            vector<int> spiralOrder(vector<vector<int>>& matrix);
    };
    vector<int> Program::spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        int top=0,left=0;
        int bottom = matrix.size()-1;
        int right = matrix[0].size()-1;

        while (top <= bottom && left <= right) {
            // As you move across the boundaries of the array (outer most cells) increment its respective boundary
            // RIGHT
            for (int i=left; i<=right; i++)
                spiral.push_back(matrix[top][i]);
            top++; 

            if (top > bottom) continue;

            // DOWN
            for (int i=top; i<=bottom; i++)
                spiral.push_back(matrix[i][right]);
            right--;

            if (left > right) continue;

            // LEFT
            for (int i=right; i>=left; i--)
                spiral.push_back(matrix[bottom][i]);
            bottom--;
            
            //UP
            for (int i=bottom; i>=top; i--)
                spiral.push_back(matrix[i][left]);
            left++;
        }
        return spiral;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    for (int i : obj.spiralOrder(matrix))
        cout << i << " ";
    cout << endl;
    for (int i : obj.spiralOrder(matrix1))
        cout << i << " ";
    cout << endl;
    return 0;
}