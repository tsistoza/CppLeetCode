#include <iostream>
#include <vector>
#include <algorithm>
using std::cout, std::cin, std::endl;
using std::vector;

static vector<int> list = {2, 1, 1, 5, 6, 2, 3, 1};

namespace Solution {
    class Program {
        public:
            int minimumMountainRemovals(vector<int>& nums);
            void removeNumsLeftOfIndex(vector<int>& nums,int val);
            void removeNumsRightOfIndex(vector<int>& nums, int val);
            vector<vector<int>::iterator> findIndex(vector<int>& nums);
            void printVector(vector<int>& nums);
            vector<int> findMinList(vector<vector<int>> list);
    };

    int Program::minimumMountainRemovals(vector<int>& nums) {
        vector<vector<int>> removeList;
        vector<vector<int>::iterator> list = this->findIndex(nums);
        for(auto it=list.begin(); it!=list.end(); it++) {
            vector<int> removeNums;
            for(vector<int>::iterator it2=(*it); it2!=nums.begin(); it2--) // move left from index
                if( !(*(it2-1) < *it2) || !(*(it2-1) < *(*it)) )
                    removeNums.push_back(*(it2-1));
            removeNums.push_back((int) NULL);
            for(vector<int>::iterator it2=(*it); it2!=nums.end()-1; it2++) // move right from index
                if(!(*it2 > *(it2+1)) || !*(*it) > *(it2+1)) 
                    removeNums.push_back(*(it2+1));
            removeList.push_back(removeNums);
            removeNums.clear();
        }

        vector<int> minList = this->findMinList(removeList);
        for(vector<int>::iterator it=minList.begin(); *it!=0; it++)
            this->removeNumsLeftOfIndex(nums, *it);
        for(vector<int>::reverse_iterator itr=minList.rbegin(); *itr!=0; itr++)
            this->removeNumsRightOfIndex(nums, *itr);
        this->printVector(nums);
        return this->findMinList(removeList).size()-1;
    }

    // Find all indexes from which i-1 < i > i+1
    vector<vector<int>::iterator> Program::findIndex(vector<int>& nums) {
        vector<vector<int>::iterator> listOfIndexes;
        for(vector<int>::iterator it2=nums.begin(); it2!=nums.end(); it2++) {
            if(it2 == nums.end()-1) break;
            if(it2 == nums.begin()) continue;
            if(*(it2-1) < *it2 && *it2 > *(it2+1)) listOfIndexes.push_back(it2);
        }
        return listOfIndexes;
    }

    void Program::printVector(vector<int>& nums) {
        cout << "Printing Vector: {";
        for (vector<int>::iterator it=nums.begin(); it!=nums.end(); it++)
            cout << *it << ", ";
        cout << "}" << endl;
        return;
    }

    void Program::removeNumsLeftOfIndex(vector<int>& nums, int val) {
        for(vector<int>::iterator it=nums.begin(); it!=nums.end(); it++)
            if(*it == val) {
                nums.erase(it);
                break;
            }
        return;
    }

    void Program::removeNumsRightOfIndex(vector<int>& nums, int val) {
        for(vector<int>::iterator it=nums.end()-1; it!=nums.begin(); it--)
            if(*it==val) {
                nums.erase(it);
                break;
            }
        return;
    }

    vector<int> Program::findMinList(vector<vector<int>> list) {
        auto it=list.begin();
        vector<int> nums = (*it);
        int size = (*it).size();
        for(auto it=list.begin()+1; it!=list.end(); it++)
            if (size > (*it).size()) nums = (*it);
        return nums;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.minimumMountainRemovals(list);
    return 0;
}