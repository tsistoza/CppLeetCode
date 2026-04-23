// LeetCode 2615
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using std::cout, std::endl, std::vector, std::unordered_map, std::abs;

static vector<int> nums { 0, 5, 3 };

namespace Solution {
    class Program {
        private:
            static void prettyPrint(vector<long long>& result);
        public:
            vector<long long> distance(vector<int>& nums);
    };

    void Program::prettyPrint(vector<long long>& result) {
        cout << "{ ";
        for (long long i : result) cout << i << " ";
        cout << "}\n\n" << endl;
        return;
    }

    vector<long long> Program::distance(vector<int>& nums) {
        unordered_map<int, vector<int>> map;
        for (int i=0; i<nums.size(); i++)
            map[nums[i]].push_back(i);

        vector<long long> result(nums.size(), 0);
        for (int i=0; i<nums.size(); i++) {
            long long sum = 0;
            for (int j=0; j<map[nums[i]].size(); j++) {
                int index = map[nums[i]][j];
                if (index == i) continue;
                sum += abs(i - index);
            }
            result[i] = sum;
        }

        prettyPrint(result);
        return result;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    obj.distance(nums);
    return 0;
}