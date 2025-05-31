// LeetCode 3372
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using std::cout, std::endl, std::vector;
using std::unordered_set, std::queue;

static vector<vector<int>> edges1 { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 } };
static vector<vector<int>> edges2 { { 0, 1 }, { 1, 2 }, { 2, 3 } };
static int k = 1;

namespace Solution {
    class Program {
        public:
            static void inline prettyPrint(vector<int> ans) {
                cout << "{ ";
                for (int i : ans) cout << i << ", ";
                cout << "}" << endl;
                return;
            }
            vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k);
    };

    vector<int> Program::maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size();
        int m = edges2.size();
        int offset = n + 1;

        vector<vector<int>> adjList(n+m+2, vector<int> ());
        for (int i=0; i<edges1.size(); i++) {
            adjList[edges1[i][0]].push_back(edges1[i][1]);
            adjList[edges1[i][1]].push_back(edges1[i][0]);
        }
        for (int i=0; i<edges2.size(); i++) {
            adjList[edges2[i][0]+offset].push_back(edges2[i][1]+offset);
            adjList[edges2[i][1]+offset].push_back(edges2[i][0]+offset);
        }

        vector<int> ans(n+1, 0);
        for (int i=0; i<=n; i++) {
            int numTargetNodes = 0;

            for (int j=offset; j<m+1+offset; j++) {
                queue<vector<int>> bfsQ;
                int tempTargetNodes = 0;
                adjList[i].push_back(j);
                unordered_set<int> vis;
                
                bfsQ.push(vector<int> { i, 0 });
                while (!bfsQ.empty()) {
                    vector<int> curr = bfsQ.front();

                    bfsQ.pop();
                    vis.insert(curr[0]);

                    if (curr[1] > k) 
                        break;

                    tempTargetNodes++;
                    for (int adj : adjList[curr[0]]) {
                        if (vis.contains(adj)) continue;
                        bfsQ.push(vector<int> {adj, curr[1]+1});
                    }

                    numTargetNodes = (tempTargetNodes > numTargetNodes) ? tempTargetNodes : numTargetNodes;
                }
                adjList[i].pop_back();
            }
            ans[i] = numTargetNodes;
        }

        return ans;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    Program::prettyPrint(obj.maxTargetNodes(edges1, edges2, k));
}