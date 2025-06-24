// LeetCode 2200
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static vector<int> nums { 2, 2, 2, 2, 2 };
static int key = 2;
static int k = 2;

namespace Solution {
    class Program {
        public:
            static inline void prettyPrint(vector<int> ans) {
                cout << "{ ";
                for (int i : ans) cout << i << " ";
                cout << "}" << endl;
                return;
            }
            vector<int> findKDistantIndices(vector<int>& nums, int key, int k);
    };

    vector<int> Program::findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> idx;
        for (int i=0; i<nums.size(); i++) if (nums[i] == key) idx.push_back(i);

        int j=0;
        vector<int> result;
        for (int i : idx) {
            if (j < i-k) j = i-k;
            for (; j>-1 && j<nums.size() && j<=i+k; j++)
                result.push_back(j);
        }

        return result;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    Program::prettyPrint(obj.findKDistantIndices(nums, key, k));
    return 0;
}