#include <iostream>
#include <vector>

using std::cout, std::cin, std::endl;
using std::vector;


static vector<vector<int>> rectangles = {{5, 8}, {3, 9}, {5, 12}, {16, 5}};

/*
You are given an array rectangles where rectangles[i] = [li, wi] represents the ith rectangle of length li and width wi.

You can cut the ith rectangle to form a square with a side length of k if both k <= li and k <= wi. For example, if you have a rectangle [4,6], you can cut it to get a square with a side length of at most 4.

Let maxLen be the side length of the largest square you can obtain from any of the given rectangles.

Return the number of rectangles that can make a square with a side length of maxLen.
*/

class Solution {
    public:
        int biggestSquareLength;
        
        void findMaxLength(vector<vector<int>>& rectangles);
        int countGoodRectangles(vector<vector<int>>& rectangles);

        Solution () {
            this->biggestSquareLength = 0;
        }
};

void Solution::findMaxLength(vector<vector<int>>& rectangles){
    int maxLengthOfSquare=1000;
    int biggestSquareLength=0;
    for (vector<vector<int>>::iterator it=rectangles.begin(); it != rectangles.end(); it++) { // iterate over the vector
        for(vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++) { // iterate over the rectangles
            (maxLengthOfSquare > *it2) ? maxLengthOfSquare = *it2 : maxLengthOfSquare-=0;
        }
        (biggestSquareLength > maxLengthOfSquare) ? biggestSquareLength-=0 : biggestSquareLength = maxLengthOfSquare;
    }

    this->biggestSquareLength = biggestSquareLength;
    return;
}

int Solution::countGoodRectangles(vector<vector<int>>& rectangles) {
    bool isSquare = false;
    int numSquares=0;
    for(vector<vector<int>>::iterator it=rectangles.begin(); it != rectangles.end(); it++) {
        for(vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++) {
            if (*it2 < this->biggestSquareLength) {
                isSquare = false;
                break;
            } else {
                isSquare = true;
            }
        }
        if (isSquare) numSquares++;
    }
    return numSquares;
}

int main() {
    Solution object;
    object.findMaxLength(rectangles);
    cout << object.countGoodRectangles(rectangles);
    return 0;
}