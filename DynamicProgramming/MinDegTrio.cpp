// Leetcode 1761
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl;
using std::vector;
using std::sort;

static vector<vector<int>> edges = { {1, 2}, {1, 3}, {3, 2}, {4, 1}, {5, 2}, {3, 6} };
static int n1 = 6;
static vector<vector<int>> edges2 = { {1, 3}, {4, 1}, {4, 3}, {2, 5}, {5, 6}, {6, 7}, {7, 5}, {2, 6} };
static int n2 = 7;

struct {
    bool operator()(int n1, int n2) const {return n1 < n2;}
} compare;

namespace Solution {
    class Program {
        public:
            int minTrioDegree(int n, vector<vector<int>>& edges);
            void createAdjMatrix(vector<vector<int>>& edges, vector<vector<int>>& adjMatrix);
            int findDegree(vector<vector<int>>& edges, int i, int j, int k);
            bool isTrio(vector<vector<int>>& adjMatrix, int i, int j, int k);
    };

    int Program::minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjMatrix(n+1, vector<int> (n+1, 0));
        this->createAdjMatrix(edges, adjMatrix);
        vector<int> dp(edges.size(), INT_MAX);
        
        for (int i=0; i<edges.size(); i++)
            for (int j=0; j<i; j++)
                for (int k=0; k<j; k++)
                    if (isTrio(adjMatrix, i, j, k))
                        dp[i] = (dp[i] < findDegree(adjMatrix, i, j, k) ? dp[i] : findDegree(adjMatrix, i, j, k));
        sort(dp.begin(), dp.end(), compare);
        if (dp[0] == INT_MAX) return -1;
        return dp[0];
    }

    int Program::findDegree(vector<vector<int>>& adjMatrix, int i, int j, int k) {
        int degree=0;
        for (int a=0; a<adjMatrix.size(); a++) {
            if (a == i || a == j || a == k) continue;
            if (adjMatrix[i][a]) degree++;
            if (adjMatrix[j][a]) degree++;
            if (adjMatrix[k][a]) degree++;
        }
        return degree;
    }


    void Program::createAdjMatrix(vector<vector<int>>& edges, vector<vector<int>>& adjMatrix) {
        for (int i=0; i<edges.size(); i++) {
            adjMatrix[edges[i][0]][edges[i][1]] = 1;
            adjMatrix[edges[i][1]][edges[i][0]] = 1;
        }
        return;
    }

    bool Program::isTrio(vector<vector<int>>& adjMatrix, int i, int j, int k) {
        if (adjMatrix[i][j] && adjMatrix[i][k] && adjMatrix[j][k])
            return true;
        return false;
    }

}

int main() {
    Solution::Program obj;
    cout << obj.minTrioDegree(n1, edges) << endl;
    cout << obj.minTrioDegree(n2, edges2) << endl;
    return 0;
}