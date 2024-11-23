// LeetCode 1893
// Compile with -std=c++20
#include <iostream>
#include <vector>
#include <map>

using std::cout, std::endl;
using std::vector, std::map;

static vector<vector<int>> ranges
{
    { 1, 2 },
    { 3, 4 },
    { 5, 6 }
};
static const int left = 2;
static const int right = 5;

static vector<vector<int>> ranges1
{
    { 1, 10 },
    { 10, 20 }
};
static const int left1 = 21;
static const int right1 = 21;

namespace Solution {
    class Program {
        private:
            map<int, int> line;
        public:
            bool isCovered(vector<vector<int>>& ranges, int left, int right);

            ~Program() {
                line.clear();
            }
    };

    bool Program::isCovered(vector<vector<int>>& ranges, int left, int right) {
        for (vector<int> range : ranges)
            for (int i=range[0]; i<=range[1]; i++)
                ++this->line[i];

        for (int i=left; i<=right; i++)
            if (!this->line.contains(i)) return false;
        return true;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.isCovered(ranges, left, right) << endl;
    cout << obj.isCovered(ranges1, left1, right1) << endl;
    return 0;
}