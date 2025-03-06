// LeetCode 2161
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static vector<int> nums { 9, 12, 5, 10, 14, 3, 10 };
static int pivot = 10;
static vector<int> nums1 { -3, 4, 3, 2 };
static int pivot1 = 2;

namespace Solution {
    class Program {
        public:
            static void prettyPrint(vector<int> nums);
            vector<int> pivotArray(vector<int>& nums, int pivot);
    };

    void Program::prettyPrint(vector<int> nums) {
        cout << "{ ";
        for (int i : nums)
            cout << i << ", ";
        cout << "}" << endl;
    }

    vector<int> Program::pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        vector<int> more;
        for (int i : nums) {
            if (i < pivot) less.push_back(i);
            if (i > pivot) more.push_back(i);
            if (i == pivot) more.insert(more.begin(), pivot);
        }

        for (int i : more) less.push_back(i);
        more.clear();
        return less;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    Program::prettyPrint(obj.pivotArray(nums, pivot));
    Program::prettyPrint(obj.pivotArray(nums1, pivot1));
    return 0;
}