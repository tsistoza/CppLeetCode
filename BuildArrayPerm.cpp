// LeetCode 1920
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static vector<int> nums { 5, 0, 1, 2, 3, 4 };

namespace Solution {
    class Program {
        private:
            void prettyPrint(vector<int> arr);
        public:
            vector<int> buildArray(vector<int>& nums);
    };

    void Program::prettyPrint(vector<int> arr) {
        cout << "{ ";
        for (int i=0; i<arr.size(); i++)
            cout << arr[i] << ", ";
        cout << "}" << endl;
        return;
    }

    vector<int> Program::buildArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        for (int i=0; i<nums.size(); i++)
            ans[i] = nums[nums[i]];
        prettyPrint(ans);
        return ans;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    obj.buildArray(nums);
    return 0;
}