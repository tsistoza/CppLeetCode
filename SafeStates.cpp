// LeetCode 802
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using std::cout, std::endl, std::vector;
using std::unordered_map, std::unordered_set;

static vector<vector<int>> graph { { 1, 2 }, { 2, 3 }, { 5 }, { 0 }, { 5 }, {}, {} };
static vector<vector<int>> graph1 { { 1, 2, 3, 4 }, { 1, 2 }, { 3, 4 }, { 0, 4 }, {} };

namespace Solution {
    class Program {
        private:
            int checkIfSafe(unordered_map<int, vector<int>>& adjList, unordered_set<int> vis, int currentNode);
        public:
            vector<int> eventualSafeNodes(vector<vector<int>>& graph);
    };

    int Program::checkIfSafe(unordered_map<int, vector<int>>& adjList, unordered_set<int> vis, int currentNode) {
        int ans = 1;
        if (vis.contains(currentNode)) {
            adjList[currentNode].pop_back();
            adjList[currentNode].push_back(-2);
            return 0;
        }

        if(adjList[currentNode].size()-1 == 0) return 1;
        if(adjList[currentNode].back() == -2) return 0;

        vis.insert(currentNode);
        for (int i=0; i<adjList[currentNode].size()-1; i++)
            ans = ans * checkIfSafe(adjList, vis, adjList[currentNode][i]);

        return ans;
    }

    vector<int> Program::eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> result;
        unordered_map<int, vector<int>> adjList;
        
        // The back of the adjList has three value { -3(unknown), -2(NotASafeNode), -1(SafeNode) }
        for (int i=0; i<graph.size(); i++) {
            if (graph[i].empty()) adjList.insert({ i, vector<int> () });
            for (int j=0; j<graph[i].size(); j++)
                adjList[i].push_back(graph[i][j]);
            adjList[i].push_back(-3);
        }
        
        for (int i=0; i<graph.size(); i++)
            if (checkIfSafe(adjList, unordered_set<int> (), i)) result.push_back(i);
        return result;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    
    for (int i : obj.eventualSafeNodes(graph))
        cout << i << " ";
    cout << endl;

    for (int i : obj.eventualSafeNodes(graph1))
        cout << i << " ";
    cout << endl;
    return 0;
}