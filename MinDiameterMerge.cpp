// LeetCode 3203
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define MAX_NODES 200005

using std::cout, std::endl;
using std::vector, std::pair;
using std::max, std::min;

static vector<vector<int>> edges1 { {0, 1}, {0, 2}, {0, 3} };
static vector<vector<int>> edges2 { {0, 1} };
int depth[MAX_NODES];
vector<int> adjList[MAX_NODES];

namespace Solution {
    class Program{
        private:
            pair<int, int> processTree(vector<vector<int>>& edges);
            int calculateTreeDiameter();
            void dfs(int currentNode, int parentNode, int& farthestNode);

        public:
            int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2);
    };

    int Program::minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        pair<int, int> dia1 = processTree(edges1);
        pair<int, int> dia2 = processTree(edges2);
        
        int minDiameter = max(dia1.first+dia1.second, dia2.first+dia2.second);
        minDiameter = min(minDiameter, max(dia1.first, dia1.second) + max(dia2.first, dia2.second) + 1);
        return minDiameter+1;
    }

    pair<int, int> Program::processTree(vector<vector<int>>& edges) {
        int arrSize = edges.size()+1;
        for (int i=1; i<=arrSize; i++)
            adjList[i].clear();
        for (vector<int> edge : edges) {
            int node1 = edge[0] + 1;
            int node2 = edge[1] + 1;
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }
        int diam = calculateTreeDiameter();
        return { diam/2, diam-diam/2 };
    }

    int Program::calculateTreeDiameter() {
        // We perform double dfs to find the tree diameter
        // Performing one dfs gives us the diameter at that starting node 1
        // Performing the second dfs gives us the diameter from the farthestNodeA, to the farthestNodeB (this is the diameter)
        int farthestNodeA = -1;
        dfs(1, 0, farthestNodeA);
        int farthestNodeB = -1;
        dfs(farthestNodeA, 0, farthestNodeB);
        return depth[farthestNodeB]-1;
    }

    void Program::dfs(int currentNode, int parentNode, int& farthestNode) {
        depth[currentNode] = depth[parentNode]+1;
        if (farthestNode == -1 || depth[currentNode] > depth[farthestNode])
            farthestNode = currentNode;
        
        for (int i : adjList[currentNode])
            if (i != parentNode) dfs(i, currentNode, farthestNode);
        return;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.minimumDiameterAfterMerge(edges1, edges2) << endl;
    return 0;
}