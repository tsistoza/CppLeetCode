// LeetCode 1574
#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

static vector<int> arr = { 1, 2, 3, 10, 4, 2, 3, 5 };
static vector<int> arr1 = { 5, 4, 3, 2, 1 };
static vector<int> arr2 = { 1, 2, 3 };
static vector<int> arr3 = { 1, 2, 3, 10, 0, 7, 8, 9 };

namespace Solution {
    class Program {
        public:
            int findLengthOfShortestSubarray(vector<int>& arr);
            bool isNonDecreasing(vector<int>& arr);
    };
    
    int Program::findLengthOfShortestSubarray(vector<int>& arr){
        if (isNonDecreasing(arr)) return 0;
        vector<int> subarray;
        vector<int> prefix;
        vector<int> suffix;

        int prefixEnd=0;
        int suffixBegin=arr.size()-1;

        // Get Prefix
        for (; prefixEnd<arr.size(); prefixEnd++) {
            if(prefix.size() == 0) {
                prefix.push_back(arr[prefixEnd]);
                continue;
            }
            if(prefix.back() > arr[prefixEnd]) break;
            prefix.push_back(arr[prefixEnd]);
        }

        // Get Suffix
        for (; suffixBegin>=0; suffixBegin--) {
            if (suffix.size() == 0) {
                suffix.push_back(arr[suffixBegin]);
                continue;
            }
            if(suffix.back() < arr[suffixBegin]) break;
            suffix.push_back(arr[suffixBegin]);
        }

        // Erase anything not in suffix or prefix, push that to subarray
        for(vector<int>::iterator it=arr.begin()+prefixEnd; it!=arr.begin()+suffixBegin+1; it++)
            subarray.push_back(*it);

        // checks if prefix and suffix can smoothly concatenate
        int size = (prefix.size() > suffix.size()) ? prefix.size() : suffix.size();
        for (int i=0; i<size; i++) {
            int indexPrefix = i;
            int indexSuffix = i;
            if (i > prefix.size()-1) indexPrefix = prefix.size()-1;
            if (i > suffix.size()-1) indexSuffix = suffix.size()-1;

            // Choose any number to push, because we know that a number needs to removed regardless.
            // If size is same remove two number
            if (prefix[indexPrefix] >= suffix[indexSuffix]) {
                subarray.push_back(prefix[indexPrefix]);
                if (prefix.size() == suffix.size()) subarray.push_back(suffix[indexSuffix]);
            }

        }
        return subarray.size();
    }
            
    bool Program::isNonDecreasing(vector<int>& arr) {
        for(vector<int>::iterator it=arr.begin()+1; it!=arr.end(); it++)
            if(*(it-1) > *it) return false;
        return true;
    }

}


int main() {
    using namespace Solution;
    Program obj;
    cout << obj.findLengthOfShortestSubarray(arr) << endl;
    cout << obj.findLengthOfShortestSubarray(arr1) << endl;
    cout << obj.findLengthOfShortestSubarray(arr2) << endl;
    cout << obj.findLengthOfShortestSubarray(arr3) << endl;
    return 0;
}
