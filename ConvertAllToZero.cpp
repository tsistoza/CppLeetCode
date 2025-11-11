// LeetCode 3542
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using std::cout, std::endl, std::vector;
using std::stack, std::unordered_map;

static vector<int> nums { 0, 0, 0 ,0 };

namespace Solution {
    class Program {
        private:
            int countOps(unordered_map<int,int>& dict);
            unordered_map<int,int> poppedOffStack(stack<int>& monoStack, int num);
        public:
            int minOperations(vector<int>& nums);
    };

    int Program::minOperations(vector<int>& nums) {
        int operations = 0;
        stack<int> monoStack;
        monoStack.push(nums[0]);
        unordered_map<int,int> dict;

        for (int i=1; i<nums.size() + 1; i++) {
            unordered_map<int,int> dict = (i < nums.size()) ? poppedOffStack(monoStack, nums[i]) 
                                                            : poppedOffStack(monoStack, INT_MIN);
            operations += countOps(dict);

            if (i==nums.size()) continue;
            monoStack.push(nums[i]);
        }

        return operations;
    }

    unordered_map<int,int> Program::poppedOffStack(stack<int>& monoStack, int num) {
        if (num == monoStack.top()) return unordered_map<int,int>();

        unordered_map<int,int> dict;
        while (monoStack.size() > 0) {
            if (num > monoStack.top()) break;
            if (num == monoStack.top()) break;
            dict[monoStack.top()]++;
            monoStack.pop();
        }

        return dict;
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