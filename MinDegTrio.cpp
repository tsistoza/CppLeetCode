// Leetcode 1761
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using std::cout, std::endl;
using std::vector, std::pair, std::make_pair;
using std::sort;

static vector<vector<int>> edges = { {1, 2}, {1, 3}, {3, 2}, {4, 1}, {5, 2}, {3, 6} };
static int n1 = 6;
static vector<vector<int>> edges2 = { {1, 3}, {4, 1}, {4, 3}, {2, 5}, {5, 6}, {6, 7}, {7, 5}, {2, 6} };
static int n2 = 7;

struct Trio {
    pair<int,int> edge1;
    pair<int,int> edge2;
    pair<int,int> edge3;
};

struct {
    bool operator()(int n1, int n2) const {return n1 < n2;}
} compare;

namespace Solution {
    class Program {
        public:
            int minTrioDegree(int n, vector<vector<int>>& edges);
            void createAdjMatrix(vector<vector<int>>& edges, vector<vector<int>>& adjMatrix);
            int findDegree(Trio tree, vector<vector<int>>& edges);
            bool isTrio(Trio tree, vector<vector<int>>& adjMatrix);
            bool vectorContains(int val, vector<int>& edge);
    };

    int Program::minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjMatrix(n+1, vector<int> (n+1, 0));
        this->createAdjMatrix(edges, adjMatrix);
        vector<int> dp(edges.size(), INT_MAX);
        
        for (int i=0; i<edges.size(); i++){
            for (int j=0; j<i; j++) {
                for (int k=0; k<j; k++) {
                    Trio tree;
                    tree.edge1 = make_pair(edges[k][0], edges[k][1]);
                    tree.edge2 = make_pair(edges[j][0], edges[j][1]);
                    tree.edge3 = make_pair(edges[i][0], edges[i][1]);
                    if (!isTrio(tree, adjMatrix)) {
                        dp[i] = INT_MAX;
                        continue;
                    }
                    dp[i] = (dp[i] < findDegree(tree, adjMatrix)) ? dp[i] : findDegree(tree, adjMatrix);
                }
            }
        }
        sort(dp.begin(), dp.end(), compare);
        if (dp[0] == INT_MAX) return -1;
        return dp[0];
    }

    int Program::findDegree(Trio tree, vector<vector<int>>& adjMatrix) {
        int degree=0;
        vector<int> trio;
        int trio1 = tree.edge1.first;
        int trio2 = (tree.edge2.first != trio1) ? tree.edge2.first : tree.edge2.second;
        int trio3 = (tree.edge3.first != trio2 && tree.edge3.first != trio1) ? tree.edge3.first : tree.edge3.second;
        trio.push_back(trio1); trio.push_back(trio2); trio.push_back(trio3);

        for (vector<int>::iterator it=trio.begin(); it!= trio.end(); it++) {
            cout << *it << " ";
            for (int i=1; i<adjMatrix.size(); i++)
                if (adjMatrix[*it][i]) degree++;
        }
        cout << endl;
        return degree;
    }


    void Program::createAdjMatrix(vector<vector<int>>& edges, vector<vector<int>>& adjMatrix) {
        for (int i=0; i<edges.size(); i++) {
            adjMatrix[edges[i][0]][edges[i][1]] = 1;
            adjMatrix[edges[i][1]][edges[i][0]] = 1;
        }
        return;
    }

    bool Program::isTrio(Trio tree, vector<vector<int>>& adjMatrix) {
        if (adjMatrix[tree.edge1.first][tree.edge1.second] && adjMatrix[tree.edge2.first][tree.edge2.second] && adjMatrix[tree.edge3.first][tree.edge3.second])
            return true;
        return false;
    }

    bool Program::vectorContains(int val, vector<int>& edge) {
        for(vector<int>::iterator it=edge.begin(); it!=edge.end(); it++)
            if(*it == val) return true;
        return false;
    }
}

int main() {
    Solution::Program obj;
    cout << obj.minTrioDegree(n1, edges);
    return 0;
}