// LeetCode 2924
#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout, std::endl;
using std::vector, std::unordered_map;

static vector<vector<int>> edges { {0, 1}, {1, 2} };
static int n = 3;
static vector<vector<int>> edges1 { {0, 2}, {1, 3}, {1, 2} };
static int n1 = 4;

namespace Solution {
    class Program {
        public:
            int findChampion(int n, vector<vector<int>>& edges);
    };

    int Program::findChampion(int n, vector<vector<int>>& edges) {
        vector<int> teamWin;
        unordered_map<int, vector<int>> map; // key = team, value = teams stronger then team
        for (vector<int> edge : edges) {
            if (map.contains(edge[1]))
                map[edge[1]].push_back(edge[0]);
            else
                map.insert({ edge[1], vector<int> {edge[0]} });
        }

        // If its not in the map then its one of the stronger teams
        for (int i=0; i<n; i++)
            if (!map.contains(i)) teamWin.push_back(i);
        
        if (teamWin.size() > 1) return -1;

        return teamWin.front();
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.findChampion(n, edges) << endl;
    cout << obj.findChampion(n1, edges1) << endl;
    return 0;
}