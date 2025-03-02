// LeetCode 1157
#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout, std::endl, std::vector;
using std::unordered_map;

static vector<int> arr { 1, 1, 2, 2, 1, 1 };

namespace Solution {
    class MajorityChecker {
        private:
            vector<int> arr;
        public:
            int query(int left, int right, int threshold);

            MajorityChecker(vector<int>& _arr) : arr(_arr) {}
            ~MajorityChecker() { this->arr.clear(); }
    };

    int MajorityChecker::query(int left, int right, int threshold) {
        unordered_map<int, int> dict;

        for (int i=left; i<right+1; i++)
            dict[this->arr[i]]++;
        
        for (unordered_map<int,int>::iterator it = dict.begin(); it!=dict.end(); it++)
            if (it->second >= threshold) return it->first;
        return -1;
    }
}

int main() {
    using namespace Solution;
    MajorityChecker* majorityChecker = new MajorityChecker(arr);
    cout << majorityChecker->query(0, 5, 4) << endl;
    cout << majorityChecker->query(0, 3, 3) << endl;
    cout << majorityChecker->query(2, 3, 2) << endl;
    delete majorityChecker;
    return 0;
}