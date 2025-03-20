// LeetCode 399
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using std::cout, std::endl, std::vector;
using std::string, std::unordered_map, std::pair;
using std::unordered_set;

static vector<vector<string>> equations { { "a", "b" }, { "b", "c" }, { "bc", "cd" } };
static vector<double> values { 1.5, 2.5, 5.0 };
static vector<vector<string>> queries { { "a", "c" }, { "c", "b" }, { "bc", "cd" }, { "cd", "bc"} };

namespace Solution {
    class Program {
        private:
            void findPath(string curr, double ansCurr, double& ans, string dstB, unordered_set<string> vis, unordered_map<string, vector<pair<string, double>>>& adjList);
        public:
            static void prettyPrint(vector<double> ans);
            vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries);
    };

    void Program::findPath(string curr, double ansCurr, double& ans, string dstB, unordered_set<string> vis, unordered_map<string, vector<pair<string, double>>>& adjList) {
        if (curr == dstB) {
            ans = ansCurr;
            return;
        }
        if (vis.contains(curr)) return;
        vis.insert(curr);
        
        for (int i=0; i<adjList[curr].size(); i++) {
            double newAnsCurr = ansCurr;
            if (vis.contains(adjList[curr][i].first)) continue;
            if (newAnsCurr == -1) newAnsCurr = adjList[curr][i].second;
            else newAnsCurr *= adjList[curr][i].second;
            findPath(adjList[curr][i].first, newAnsCurr, ans, dstB, vis, adjList);
            if (adjList[curr][i].first == dstB) break;
        }
        return;
    }

    void Program::prettyPrint(vector<double> ans) {
        cout << "{ ";
        for (int i=0; i<ans.size(); i++)
            cout << ans[i] << ", ";
        cout << "}" << endl;
        return;
    }

    vector<double> Program::calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> results;
        unordered_map<string, vector<pair<string, double>>> adjList;
        for (int i=0; i<equations.size(); i++) {
            adjList[equations[i][0]].push_back({ equations[i][1], values[i] });
            adjList[equations[i][1]].push_back({ equations[i][0], 1.0/values[i] });
        }

        for (int i=0; i<queries.size(); i++) {
            double ans = -1.0;
            findPath(queries[i][0], -1, ans, queries[i][1], unordered_set<string> (), adjList);
            if (queries[i][0] == queries[i][1]) ans = 1.0;
            results.push_back(ans);
        }

        return results;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    Program::prettyPrint(obj.calcEquation(equations, values, queries));
    return 0;
}