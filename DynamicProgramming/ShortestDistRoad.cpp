// LeetCode 3243
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using std::cout, std::endl;
using std::vector, std::unordered_map;
using std::string, std::sort;

static vector<vector<int>> queries { {2, 4}, {0, 2}, {0, 4} };
static int n = 5;
static vector<vector<int>> queries1 { {0, 3}, {0, 2} };
static int n1 = 4;
static vector<vector<int>> queries2 { {10, 12}, {6, 12} };
static int n2 = 15;


namespace Solution {
    class Compare {
        public:
            bool operator()(vector<int> path1, vector<int> path2) const { return path1.size() < path2.size(); }
    };

    class Program {
        public:
            vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries);
            void BFS(vector<vector<int>>& paths, vector<int> path, int state, unordered_map<int, vector<int>>& adjList);
    };

    vector<int> Program::shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // Make a adjacency list starting from 4, this helps us transition between cities
        // if n=5, adjlist[4] = {3}, adjList[3] = {2} ...
        vector<int> result;
        vector<vector<int>> paths;
        unordered_map<int, vector<int>> reverseAdjList;
        for (int i=n-1; i>0; i--) reverseAdjList[i] = vector<int> {i-1}; // Populate adjList

        // We are going to use BFS to find all paths
        // Ex: BFS -> 4 -> 43 -> 432 -> 4321 -> 43210
        for (vector<int> query : queries) {
            reverseAdjList[query[1]].push_back(query[0]);
            this->BFS(paths, vector<int>(), n-1, reverseAdjList);
            Compare cmp;
            sort(paths.begin(), paths.end(), cmp);
            result.push_back(paths[0].size()-1);
            paths.clear();
        }

        return result;
    }

    void Program::BFS(vector<vector<int>>& paths, vector<int> path, int state, unordered_map<int,vector<int>>& adjList) {
        path.push_back(state);
        if (state == 0) { // reached city 0, path from n-1 to 0 is made
            paths.push_back(vector<int> (path));
            return;
        }
        for (int i : adjList[state])
            this->BFS(paths, path, i, adjList);
        return;
    }

}

int main() {
    using namespace Solution;
    Program obj;
    for (int i : obj.shortestDistanceAfterQueries(n, queries)) cout << i << " ";
    cout << endl;
    for (int i : obj.shortestDistanceAfterQueries(n1, queries1)) cout << i << " ";
    cout << endl;
    for (int i : obj.shortestDistanceAfterQueries(n2, queries2)) cout << i << " ";
    cout << endl;
    return 0;
}