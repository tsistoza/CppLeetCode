// LeetCode 2386
#include <iostream>
#include <vector>
#include <queue>

using std::cout, std::endl;
using std::vector, std::priority_queue;

static vector<int> nums { 2, 4, -2 };
static int k = 5;
static vector<int> nums1 { 1, -2, 3, 4, -10, 12 };
static int k1 = 16;

namespace Solution {
    class Program {
        private:
            long long sum(vector<int>& v1);
            void getAllSubseq(vector<int> subseq, vector<int>& nums, vector<vector<int>>& subseqs, int index);
        public:
            long long kSum(vector<int>& nums, int k);
    };

    long long Program::kSum(vector<int>& nums, int k) {
        if (nums.size() == 1) 
            return nums[0];
        
        vector<vector<int>> subseqs;
        this->getAllSubseq(vector<int> (), nums, subseqs, 0);
        priority_queue<long long> heap;

        for (vector<int> subseq : subseqs) // We'll use a heap to sort the sums
            heap.push(this->sum(subseq));
        for (int i=0; i<k-1; i++) // pop the heap to get to the kth largest element
            heap.pop();
        return heap.top();
    }

    // Note that we are passing a copy of subseq, not a reference
    void Program::getAllSubseq(vector<int> subseq, vector<int>& nums, vector<vector<int>>& subseqs, int index) {
        if (!subseq.empty())
            subseqs.push_back(subseq);
        if (index >= nums.size()) return;
        
        // Add Element
        vector<int> temp(subseq);
        temp.push_back(nums[index]);
        getAllSubseq(temp, nums, subseqs, index+1);

        // Delete Element
        if (!subseq.empty()) {
            vector<int> temp(subseq);
            temp.pop_back();
            temp.push_back(nums[index]);
            getAllSubseq(temp, nums, subseqs, index+1);
        }
        return;
    }

    long long Program::sum(vector<int>& v1) {
        long long sum=0;
        for (int i : v1) sum+=i;
        return sum;
    }
}

int main () {
    using namespace Solution;
    Program obj;
    cout << obj.kSum(nums, k) << endl;
    cout << obj.kSum(nums1, k1) << endl;
    return 0;
}