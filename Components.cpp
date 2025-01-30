// LeetCode 2685
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using std::cout, std::endl, std::vector;
using std::unordered_map, std::unordered_set;

static int n = 6;
static vector<vector<int>> edges { { 0, 1 }, { 0, 2 }, { 1, 2 }, { 3, 4 } };
static vector<vector<int>> edges1 { { 0, 1 }, { 0, 2 }, { 1, 2 }, { 3, 4 }, { 3, 5 } };

namespace Solution {
    class Program {
        private:
            int dfs(unordered_map<int, vector<int>>& adjList, unordered_set<int>& vis, int current);
        public:
            int countCompleteComponents(int n, vector<vector<int>>& edges);
    };

    int Program::dfs(unordered_map<int, vector<int>>& adjList, unordered_set<int>& vis, int current) {
        vis.insert(current);
        int numNodes = 1;

        for (int i=0; i<adjList[current].size(); i++) {
            if (vis.contains(adjList[current][i])) continue;
            numNodes += dfs(adjList, vis, adjList[current][i]);
        }

        return numNodes;
    }

    int Program::countCompleteComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        unordered_map<int, vector<int>> adjList;
        unordered_set<int> vis;

        for (int i=0; i<n; i++)
            adjList.insert({i, vector<int>()});

        for (vector<vector<int>>::iterator it=edges.begin(); it!=edges.end(); it++) {
            adjList[(*it)[0]].push_back((*it)[1]);
            adjList[(*it)[1]].push_back((*it)[0]);
        }

        for (int i=0; i<n; i++) {
            if (vis.contains(i)) continue;
            vis.clear();

            int numNodes = dfs(adjList, vis, i);
            count++;
            for (unordered_set<int>::iterator it = vis.begin(); it!=vis.end(); it++)
                if (adjList[*it].size() != numNodes-1) {
                    count--;
                    break;
                }
        }

        return count;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.countCompleteComponents(n, edges) << endl;
    cout << obj.countCompleteComponents(n, edges1) << endl;
    return 0;
}