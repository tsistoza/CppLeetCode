// LeetCode 3731
#include <iostream>
#include <vector>
#include <unordered_set>

using std::cout, std::endl, std::vector, std::unordered_set;

static vector<int> nums { 5, 1 };

namespace Solution {
    class Program {
        private: 
            static void prettyPrint(vector<int>& result);
        public:
            vector<int> findMissingElements(vector<int>& nums);
    };

    void Program::prettyPrint(vector<int>& result) {
        cout << "{ ";
        for (int i : result) cout << i << " ";
        cout << "}\n\n" << endl;
        return;
    }

    vector<int> Program::findMissingElements(vector<int>& nums) {
        unordered_set<int> dict;
        int low = INT_MAX, high = INT_MIN;
        for (int i : nums) {
            low = (low > i) ? i : low;
            high = (high < i) ? i : high;
            if (dict.contains(i)) continue;
            else dict.insert(i);
        }

        vector<int> result;
        for (int i=low+1; i<=high; i++)
            if (!dict.contains(i)) result.push_back(i);
        //prettyPrint(result);
        return result;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    obj.findMissingElements(nums);
    return 0;
}