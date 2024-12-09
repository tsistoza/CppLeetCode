// LeetCode 3152
#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

static vector<int> nums { 3, 4, 1, 2, 6 };
static vector<vector<int>> queries { {0, 4} };
static vector<int> nums1 { 4, 3, 1, 6 };
static vector<vector<int>> queries1 { {0, 2}, {2, 3} };

namespace Solution {
    class Program {
        public:
            vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries);
    };

    vector<bool> Program::isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> result;
        for(vector<int> query : queries) {
            for(int i=query[0]; i<query[1]; i++) {
                if ( !(nums[i] % 2) && (nums[i+1] % 2) || ((nums[i] % 2) && !(nums[i+1] % 2)) ) {
                    if (i == query[1]-1) result.push_back(true);
                    continue;
                }
                result.push_back(false);
                break;
            }
        }
        return result;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    for (bool ans : obj.isArraySpecial(nums, queries)) cout << ans << " ";
    cout << endl;
    for (bool ans : obj.isArraySpecial(nums1, queries1)) cout << ans << " ";
    cout << endl;
    return 0;
}