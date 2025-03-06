// LeetCode 2965
#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout, std::endl, std::vector;
using std::unordered_map;

static vector<vector<int>> grid { { 1, 3 }, { 2, 2 } };
static vector<vector<int>> grid1 { { 9, 1, 7 }, { 8, 9, 2 }, { 3, 4, 6 } };


namespace Solution {
    class Program {
        public:
            static void prettyPrint(vector<int> ans);
            vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid);
    };

    void Program::prettyPrint(vector<int> ans) {
        cout << "{ ";
        for (int i : ans) cout << i << ", ";
        cout << "}" << endl;
        return;
    }

    vector<int> Program::findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> dict;
        for (int i=1; i<=grid.size()*grid.size(); i++) dict.insert({i, 0});

        for (vector<int> vec : grid)
            for (int i : vec)
                dict[i]++;
        
        int a=0, b=0;
        for (unordered_map<int,int>::iterator it = dict.begin(); it!=dict.end(); it++) {
            if (a>0 && b>0) break;
            if (it->second > 1) a = it->first;
            if (it->second < 1) b = it->first;
        }
        
        return vector<int> { a, b };
    }
}

int main() {
    using namespace Solution;
    Program obj;
    Program::prettyPrint(obj.findMissingAndRepeatedValues(grid));
    Program::prettyPrint(obj.findMissingAndRepeatedValues(grid1));
    return 0;
}