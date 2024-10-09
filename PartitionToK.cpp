#include <iostream>
#include <vector> //vector
#include <numeric> //accumulate
#include <algorithm> //iter_swap

using std::cout, std::cin, std::endl;
using std::vector, std::accumulate, std::iter_swap;

// Controllable Variables
vector<int> v = {4, 3, 2, 3, 5, 2, 1}; // array to partition
int k = 4; // subsets

namespace solution 
{
    class Program {
        public:
            bool canPartitionKSubsets(vector<int>& nums, int k);
            void sort(vector<int>& nums);
            bool canPartition(vector<bool>&visited, vector<int>& nums, int k, int subset_sum, int cur_sum, int nxt_ind);
    }; // Program

    bool Program::canPartitionKSubsets(vector<int>& nums, int k) {
        int sumOfArray = accumulate(nums.begin(), nums.end(), 0);
        cout << sumOfArray << endl;
        if (sumOfArray % k != 0) return false; // Check if array is compatible with k subsets
        int subset_sum = sumOfArray / k; // Find the sum of each subset
        sort(nums);

        vector<bool> visited; //check if you visited index in array
        for (int i=0 ; i<nums.size() ; i++) //init visited array
            visited.push_back(false); 

        return canPartition(visited, nums, k, subset_sum, 0, 0);
    }

    bool Program::canPartition(vector<bool>& visited, vector<int>& nums, int k, int subset_sum, 
    int cur_sum, int nxt_ind) {
        if (k==1) return true;
        if (cur_sum == subset_sum) return canPartition(visited, nums, k-1,subset_sum, 0, 0);
        for (int i=nxt_ind ; i<v.size() ; i++) {
            if ( (!visited[i] && (cur_sum+nums[i])) <= subset_sum) { //check if can subset
                visited[i] = true;
                if (canPartition(visited, nums, k, subset_sum, cur_sum+nums[i], nxt_ind=i+1)) return true; //check for other numbers that can be included in the current subset
            }
            visited[i] = false;
        }
        return false;
    }
    void Program::sort(vector<int>& nums) {
        int position=0;
        // Bubble Sort Array
        for (vector<int>::iterator it = nums.begin() ; it<nums.end() ; it++) {
            for(auto it2 = it+1 ; it2<nums.end() ; it2++) {
                if( *it < *it2 ) iter_swap(it, it2);
            }
        }
    }
} //Namespace

int main() {
    solution::Program soln;
    cout << soln.canPartitionKSubsets(v, k);
    return 0;
}