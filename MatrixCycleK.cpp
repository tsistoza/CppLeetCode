// LeetCode 2946
#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

static vector<vector<int>> mat { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
static int k = 4;
static vector<vector<int>> mat1 { {1, 2, 1, 2}, {5, 5, 5, 5}, {6, 3, 6, 3} };
static int k1 = 2;
static vector<vector<int>> mat2 { {2, 2}, {2, 2} };
static int k2 = 3;

static bool areSimlar(vector<vector<int>>&mat, int k);
static void prettyPrint(vector<vector<int>>& matrix);

static bool areSimilar(vector<vector<int>>& mat, int k) {
    vector<vector<int>> modifiedMat(mat);
    prettyPrint(mat);
    while (k > 0) {
        for (int i=0; i<mat.size(); i++) {
            if (i%2) { // Cycle Right
                vector<int> temp(modifiedMat[i]);
                modifiedMat[i].clear();
                modifiedMat[i].push_back(temp.back());
                temp.pop_back();
                for(int j : temp) modifiedMat[i].push_back(j);
            } else { // Cycle Left
                vector<int> temp(modifiedMat[i]);
                modifiedMat[i].clear();
                for (auto it=temp.begin()+1; it!=temp.end(); it++)
                    modifiedMat[i].push_back(*it);
                modifiedMat[i].push_back(temp.front());
            }
        }
        k--;
    }
    prettyPrint(modifiedMat);
    return modifiedMat == mat;
}

static void prettyPrint(vector<vector<int>>& matrix) {
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

int main() {
    cout << areSimilar(mat, k) << endl;
    cout << areSimilar(mat1, k1) << endl;
    cout << areSimilar(mat2, k2) << endl;
    return 0;
}