// LeetCode 3066
#include <iostream>
#include <vector>
#include <map>

using std::cout, std::endl, std::vector;
using std::map, std::min, std::max;

static vector<int> nums { 2, 11, 10, 1, 3 };
static int k = 10;
static vector<int> nums1 { 1, 1, 2, 4, 9 };
static int k1 = 20;

int minOperations(vector<int>& nums, int k);
void operation(map<int,int>& dict, int& operations);
bool allValuesGtK(map<int,int>& dict, int k);

int minOperations(vector<int>& nums, int k) {
    int operations = 0;
    map<int,int> dict;
    for (int i=0; i<nums.size(); i++)
        dict[nums[i]]++;

    while(!allValuesGtK(dict, k))
        operation(dict, operations);

    return operations;
}

void operation(map<int,int>& dict, int& operations) {
    int x=0, y=0;
    for (map<int,int>::iterator it=dict.begin(); it!=dict.end() && x==0;) {
        x = it->first;
        dict[it->first]--;

        if (dict[it->first] == 0)
            dict.erase(it->first);
        else
            it++;
    }

    for (map<int,int>::iterator it=dict.begin(); it!=dict.end() && y==0;) {
        y = it->first;
        dict[it->first]--;
        
        if (dict[it->first] == 0)
            dict.erase(it->first);
        else
            it++;
    }

    dict[(min(x,y) * 2) + max(x,y)]++;
    operations++;
    return;
}

bool allValuesGtK(map<int,int>& dict, int k) {
    for (map<int,int>::iterator it=dict.begin(); it!=dict.end(); it++)
        if (it->first < k) return false;
    return true;
}

int main() {
    cout << minOperations(nums, k) << endl;
    cout << minOperations(nums1, k1) << endl;
    return 0;
}