// LeetCode 1200
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using std::cout, std::endl, std::vector;
using std::sort, std::abs;

static vector<int> arr { 3,8,-10,23,19,-4,-14,27 };

namespace Solution {
    class Program {
        public:
            static void prettyPrint(vector<vector<int>> ans);
            vector<vector<int>> minimumAbsDifference(vector<int>& arr);
    };

    vector<vector<int>> Program::minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        vector<vector<int>> result;
        int minAbs = INT_MAX;
        for (int begin=0,end=1; end<arr.size(); begin++,end++) {
            int difference = abs(arr[end] - arr[begin]);
            if (difference < minAbs) {
                result.clear();
                minAbs = difference;
            }
            if (minAbs == difference)
                result.push_back(vector<int> { arr[begin], arr[end] });
        }

        return result;
    }

    void Program::prettyPrint(vector<vector<int>> ans) {
        for (int i=0; i<ans.size(); i++) {
            cout << "{ ";
            for (int j=0; j<ans[i].size(); j++) {
                cout << ans[i][j] << " ";
                if (j == ans[i].size()-1) cout << "}, " << endl;
                else cout << ", ";
            }
        }
        return;
    }
};

int main() {
    using namespace Solution;
    Program obj;
    Program::prettyPrint(obj.minimumAbsDifference(arr));
    return 0;
}