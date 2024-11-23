// LeetCode 1861
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using std::cout, std::endl;
using std::vector, std::pair, std::make_pair;
using std::sort;

static vector<vector<char>> box 
{
    { '#', '.', '#' }
};
static vector<vector<char>> box1 
{
    { '#', '.', '*', '.' },
    { '#', '#', '*', '.' }
};
static vector<vector<char>> box2 
{
    { '#', '#', '*', '.', '*', '.'},
    { '#', '#', '#', '*', '.', '.'},
    { '#', '#', '#', '.', '#', '.'}
};

namespace Solution {
    class Compare {
        public:
            bool operator()(pair<int,int> p1, pair<int,int> p2) const { return p1.first < p2.first; }
    };

    class Program {
        public:
            vector<vector<char>> rotateTheBox(vector<vector<char>>& box);
    };

    vector<vector<char>> Program::rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> newBox (box[0].size(), vector<char> (box.size(), '.'));
        vector<pair<int,int>> stonePos;

        // make rotatedbox
        int rotCol = box.size()-1; // column of the rotated box
        for (vector<char> row : box) {
            int rotRow = 0; // row of the rotated box
            for (char ch : row) {
                if (ch == '#') stonePos.push_back(make_pair(rotRow,rotCol));
                newBox[rotRow][rotCol] = ch;
                rotRow++;
            }
            rotCol--;
        }

        Compare obj;
        sort(stonePos.begin(), stonePos.end(), obj);

        // Gravity 
        // Remember start from the bottom of the row, to account for stones in the same row
        for (auto position=stonePos.rbegin(); position!=stonePos.rend(); position++) { // reverse iterator
            for (int row=position->first+1; row<newBox.size(); row++) {
                if (newBox[row][position->second] == '*' || newBox[row][position->second] == '#') {
                    newBox[position->first][position->second] = '.';
                    newBox[row-1][position->second] = '#';
                    break;
                }
                if (row == newBox.size()-1) {
                    newBox[position->first][position->second] = '.';
                    newBox[row][position->second] = '#';
                }
            }
        }
        return newBox;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    
    //Test Case 1
    for(vector<char> row : obj.rotateTheBox(box)) {
        for (char ch : row)
            cout << ch << " ";
        cout << endl;
    }
    cout << endl;

    //Test Case 2
    for(vector<char> row : obj.rotateTheBox(box1)) {
        for (char ch : row)
            cout << ch << " ";
        cout << endl;
    }
    cout << endl;

    // Test Case 3
    for(vector<char> row : obj.rotateTheBox(box2)) {
        for (char ch : row)
            cout << ch << " ";
        cout << endl;
    }
    cout << endl;
    return 0;
}