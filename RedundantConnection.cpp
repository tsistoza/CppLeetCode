// LeetCode 684
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using std::cout, std::endl, std::vector;
using std::unordered_map, std::unordered_set;

static vector<vector<int>> edges = { { 1, 2 }, { 1, 3 }, { 2, 3 } };
static vector<vector<int>> edges1 = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 1, 4 }, { 1, 5 } };

namespace Solution {
    class Program {
        public:
            vector<int> findRedundantConnection(vector<vector<int>>& edges);
    };

    vector<int> Program::findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> pairs;
        
        for (vector<int> edge : edges) {
            pairs[edge[0]].insert(edge[1]);
            pairs[edge[1]].insert(edge[0]);
        }
        
        for (unordered_map<int, unordered_set<int>>::iterator it = pairs.begin(); it!=pairs.end(); ) {
            if(it->second.size() == 1) {
                pairs.erase(it);
                continue;
            }
            it++;
        }

        for (vector<vector<int>>::reverse_iterator itr = edges.rbegin(); itr != edges.rend(); itr++) {
            if (pairs.contains((*itr)[0]) && pairs.contains((*itr)[1]))
                return *itr;
        }

        return edges.back();
    }
}

int main() {
    using namespace Solution;
    Program obj;

    cout << "{ ";
    for (int i : obj.findRedundantConnection(edges))
        cout << i << " ";
    cout << "}" << endl;

    
    cout << "{ ";
    for (int i : obj.findRedundantConnection(edges1))
        cout << i << " ";
    cout << "}" << endl;
    return 0;
}