// LeetCode 3394
#include <iostream>
#include <vector>
#include <utility>
#include <ios>

using std::cout, std::endl, std::vector;
using std::pair;

static int n = 4;
static vector<vector<int>> rectangles { { 0, 2, 2, 4 }, { 1, 0, 3, 2 }, { 2, 2, 3, 4 }, { 3, 0, 4, 2 }, { 3, 2, 4, 4 } };

namespace Solution {
    class Program {
        private:
            bool validCutX(int i, vector<vector<int>>& rectangles);
            bool validCutY(int i, vector<vector<int>>& rectangles);
        public:
            bool checkValidCuts(int n, vector<vector<int>>& rectangles);
    };

    bool Program::validCutX(int i, vector<vector<int>>& rectangles) {
        for (int j=0; j<rectangles.size(); j++) {
            if (i <= rectangles[j][0] || i >= rectangles[j][2]) continue;
            return false;
        }
        return true;
    }

    bool Program::validCutY(int i, vector<vector<int>>& rectangles) {
        for (int j=0; j<rectangles.size(); j++) {
            if (i <= rectangles[j][1] || i >= rectangles[j][3]) continue;
            return false;
        }
        return true;
    }

    bool Program::checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int cut = 0;

        // Check x
        for (int i=1; i<n; i++)
            if (validCutX(i, rectangles)) cut++;

        if (cut >= 2) return true;
        cut = 0;

        // Check y
        for (int i=1; i<n; i++)
            if (validCutY(i, rectangles)) cut++;

        return (cut >= 2) ? true : false;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << std::boolalpha << obj.checkValidCuts(n, rectangles) << endl;
}