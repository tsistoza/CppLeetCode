// LeetCode 3542
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using std::cout, std::endl, std::vector;
using std::stack, std::unordered_map;

static vector<int> nums { 0, 2 };

namespace Solution {
    class Program {
        private:
            int countOps(unordered_map<int,int>& dict);
        public:
            int minOperations(vector<int>& nums);
    };

    int Program::minOperations(vector<int>& nums) {
        int operations = 0;
        stack<int> monoStack;
        monoStack.push(nums[0]);
        for (int i=1; i<nums.size(); i++) {
            unordered_map<int, int> dict;

            while(monoStack.size() > 0) {
                if (nums[i] > monoStack.top()) break;
                dict[monoStack.top()]++;
                monoStack.pop();
            }
            
            operations += countOps(dict);
            if (!dict.contains(nums[i]))
                monoStack.push(nums[i]);
        }

        return (monoStack.size() > 0) ? operations+1 : operations;
    }

    int Program::countOps(unordered_map<int,int>& dict) {
        int currOperations = 0;
        for (unordered_map<int,int>::iterator it = dict.begin(); it!=dict.end(); it++) {
            if (it->first == 0) continue;
            currOperations++;
        }
        return currOperations;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.minOperations(nums) << endl;
    return 0;
}