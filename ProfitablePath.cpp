// LeetCode 2467
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using std::cout, std::endl, std::vector;
using std::unordered_set, std::unordered_map, std::max;

static vector<vector<int>> edges { {0, 1}, {1, 2}, {1, 3}, {3, 4} };
static int bob = 3;
static vector<int> amount { -2, 4, 2, -4, 6 };

namespace Solution {
    class Program {
        private:
            void getBobPath(unordered_map<int, vector<int>>& adjList, vector<int>& finalPath, vector<int> path, unordered_set<int> vis);
            void findAlicePath(unordered_map<int, vector<int>>& adjList, vector<int>& amt, vector<int>& bobsPath, int currNode, unordered_set<int> vis, unordered_set<int> bob, int& sum, int currSum, int pathNum);
        public:
            int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount);
    };

    void Program::getBobPath(unordered_map<int, vector<int>>& adjList, vector<int>& finalPath, vector<int> path, unordered_set<int> vis) {
        if (path.back() == 0) {
            finalPath = path;
            return;
        }

        int currNode = path.back();
        for (int i=0; i<adjList[currNode].size(); i++) {
            if (vis.contains(adjList[currNode][i])) continue;
            unordered_set newVis(vis);
            vector<int> newPath(path);
            newVis.insert(adjList[currNode][i]);
            newPath.push_back(adjList[currNode][i]);
            getBobPath(adjList, finalPath, newPath, newVis);
        }

        return;
    }

    void Program::findAlicePath(unordered_map<int, vector<int>>& adjList, vector<int>& amt, vector<int>& bobsPath, int currNode, unordered_set<int> vis, unordered_set<int> bob, int& sum, int currSum, int pathNum) {
        
        int leafNode = 0;
        if (pathNum < bobsPath.size())
            bob.insert(bobsPath[pathNum]);
        for (int i=0; i<adjList[currNode].size(); i++) {
            if (vis.contains(adjList[currNode][i])) {
                leafNode++;
                continue;
            }
            unordered_set<int> newVis(vis);
            newVis.insert(adjList[currNode][i]);
            int newSum = currSum+amt[adjList[currNode][i]];
            
            if (bob.contains(adjList[currNode][i])) {
                newSum = currSum;
                if (bobsPath[pathNum] == adjList[currNode][i])
                    newSum = currSum + (amt[adjList[currNode][i]] / 2);
            }

            findAlicePath(adjList, amt, bobsPath, adjList[currNode][i], newVis, bob, sum, newSum, pathNum+1);
        }

        if (leafNode == adjList[currNode].size()) sum = max(sum, currSum);
        return;
    }

    int Program::mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        unordered_map<int, vector<int>> adjList;
        for (int i=0; i<edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }

        int sum = INT_MIN;
        vector<int> bobsPath;
        getBobPath(adjList, bobsPath, vector<int> { bob }, unordered_set<int> { bob });
        findAlicePath(adjList, amount, bobsPath, 0, unordered_set<int> { 0 }, unordered_set<int> { bobsPath[0] }, sum, amount[0], 1);
        return sum;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.mostProfitablePath(edges, bob, amount) << endl;
}