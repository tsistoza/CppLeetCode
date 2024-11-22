// LeetCode 2848
#include <iostream>
#include <vector>
#include <map>

using std::cout, std::endl;
using std::vector, std::map;

static vector<vector<int>> nums { {3, 6}, {1, 5}, {4, 7} };
static vector<vector<int>> nums1 { {1, 3}, {5, 8} };

namespace Solution {
   class Program {
       public:
           int numberOfPoints(vector<vector<int>>& nums);
   };

   int Program::numberOfPoints(vector<vector<int>>& nums) {
        map<int, int> line;
        for (vector<int> car : nums)
            for (int i=car[0]; i<=car[1]; i++)
                ++line[i];
        // all points on the map are covered by a car, so return the container size
        return line.size();
   }
}

int main () {
    using namespace Solution;
    Program obj;
    cout << obj.numberOfPoints(nums) << endl;
    cout << obj.numberOfPoints(nums1) << endl;
    return 0;
}