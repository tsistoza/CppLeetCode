// LeetCode 836
#include <iostream>
#include <vector>
#include <ios>

using std::cout, std::endl, std::vector;

static vector<int> rec1 { 0, 0, 1, 1 };
static vector<int> rec2 { 2, 2, 3, 3 };

namespace Solution {
    class Program {
        public:
            bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2);
    };

    bool Program::isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (rec2[0] <= rec1[0] && rec2[2] <= rec1[0]) return false;
        if (rec2[0] >= rec1[2] && rec2[2] >= rec1[2]) return false;
        if (rec2[1] <= rec1[1] && rec2[3] <= rec1[1]) return false;
        if (rec2[1] >= rec1[3] && rec2[3] >= rec1[3]) return false;
        return true;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << std::boolalpha << obj.isRectangleOverlap(rec1, rec2) << endl;
    return 0;
}