#include <iostream>
#include <vector>
#include <cmath>

using std::cout, std::cin, std::endl;
using std::vector, std::sqrt;


static vector<int> nums = {2, 3, 5, 6, 7};

namespace Solution {
    class Program {
        private:
            vector<vector<int>> allSubsequences;

        public:

            int longestSquareStreak(vector<int>& nums);
            void getSubsequence(vector<int>& nums);
            bool isSquareStreak(vector<int>& subsequence, int val);
            void deleteInt(vector<int>& nums, int val);
    };

    int Program::longestSquareStreak(vector<int>& nums) {
        while (nums.size() > 0) this->getSubsequence(nums);
        if (this->allSubsequences.size() == 0) return -1;
        int max=2;
        for(auto it=this->allSubsequences.begin(); it!=this->allSubsequences.end(); it++)
            if (max < it->size()) max=it->size();
        return max;
    }

    void Program::getSubsequence(vector<int>& nums) {
        vector<int> subsequence;
        vector<int>::iterator it=nums.begin();
        subsequence.push_back(*it);
        for (vector<int>::iterator it2=nums.begin(); it2!=nums.end(); it2++) {
            if(*it2 == *it) continue;
            if(isSquareStreak(subsequence, *it2)) subsequence.push_back(*it2);
        }

        vector<int> sub;
        for (auto it = subsequence.begin(); it<subsequence.end(); it++)
        {
            sub.push_back(*it);
            deleteInt(nums, *it);
        }
        if(sub.size() > 1) allSubsequences.push_back(sub);
        return;
    }

    bool Program::isSquareStreak(vector<int>& subsequence, int val) {
        for(vector<int>::iterator it=subsequence.begin(); it!=subsequence.end(); it++) {
            if ((*it) * (*it) == val) return true;
            else if (val == (int)sqrt(*it)) return true;
        }
        return false;
    }

    void Program::deleteInt(vector<int>& nums, int val) {
        vector<int>::iterator it = nums.begin();
        for(; it!=nums.end(); it++) if (val == *it) break;
        nums.erase(it);
        return;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.longestSquareStreak(nums) << endl;
    return 0;
}