// LeetCode 2966
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::vector, std::endl, std::sort;

static vector<int> nums { 2, 4, 2, 2, 5, 2 };
static int k = 2;

namespace Solution {
    class Program {
        public:
            static inline void prettyPrint(vector<vector<int>> result) {
                cout << "result = { ";
                for (int i=0; i<result.size(); i++) {
                    cout << "{ ";
                    for (int j=0; j<result[i].size(); j++) {
                        cout << result[i][j] << " ";
                    }
                    cout << "} ";
                }
                cout << "}" << endl;
                return;
            }
            vector<vector<int>> divideArray(vector<int>& nums, int k);
    };

    vector<vector<int>> Program::divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i=0; i<nums.size(); ) {
            vector<int> div;
            for (int start=nums[i], itr=nums[i]; itr<=start+k && div.size()<3 && i<nums.size(); itr=nums[i]) {
                div.push_back(itr);
                i++;
            }
            if (div.size() <= 1) continue;
            else result.push_back(div);
        }

        if (result.size() == 3) return result;
        return vector<vector<int>>();
    }
}

int main() {
    using namespace Solution;
    Program obj;
    Program::prettyPrint(obj.divideArray(nums, k));
    return 0;
}