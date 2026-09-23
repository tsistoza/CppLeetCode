// LeetCode 3524
#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

static vector<int> nums { 1, 2, 3, 4, 5 };
static int k = 3;

namespace Solution {
    class Program {
        private:
            static void prettyPrint(vector<long long>& results);
        public:
            vector<long long> resultArray(vector<int>& nums, int k);
    };

    void Program::prettyPrint(vector<long long>& results) {
        cout << "{ ";
        for (int i : results) cout << i << " ";
        cout << "}\n" << endl;
        return;
    }

    vector<long long> Program::resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> results(k);
        vector<int> freq(5, 0);
        for (int i=0; i<nums.size(); i++) {
            vector<int> currX(5, 0);
            currX[nums[i] % k]++;

            for (int x=0; x<k; x++)
                currX[nums[i] * x % k] += freq[x];

            for (int x=0; x<k; x++) {
                freq[x] = currX[x];
                results[x] += freq[x];
            }
        }
        
        prettyPrint(results);
        return results;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    obj.resultArray(nums, k);
    return 0;
}