#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>

using std::cout, std::cin, std::endl;
using std::vector, std::unordered_map, std::pair;
using std::make_pair;

static vector<int> nums = {-1,0,1,2,-1,-4};

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums);
        void createHashMap(unordered_map<int, vector<int>>& map, vector<int>& nums);
        void readMap(unordered_map<int, vector<int>>& map);
        void readResult(vector<vector<int>>& triplets);
        pair<bool, int> checkIndex(int index1, int index2, vector<int>& val);
        bool checkRepeat(vector<vector<int>>& triplets, vector<int>& triples);
        bool vectorContainsInt(vector<int>& compare, int val);
};

vector<vector<int>> Solution::threeSum(vector<int>& nums) {
    int index3;
    vector<vector<int>> triplets;
    vector<int> triples;
    unordered_map<int, vector<int>> hashMap;
    createHashMap(hashMap, nums);
    //readMap(hashMap);
    for (int i=0 ;i<nums.size()-1 ;i++) {
        for (int j=i+1; j<nums.size()-1 ;j++) {
            int index3 = -nums[i]-nums[j];
            auto search = hashMap.find(index3);
            pair<bool,int> p;
            if (search != hashMap.end()) {
                p = checkIndex(i, j, search->second);
                if (p.first) {
                    triples.push_back(nums[i]);
                    triples.push_back(nums[j]);
                    triples.push_back(nums[p.second]);
                    if (!checkRepeat(triplets, triples))
                        triplets.push_back(triples);
                    triples.clear();
                }
            }
        }
    }
    return triplets;
}

void Solution::createHashMap(unordered_map<int, vector<int>>& map, vector<int>& nums) {
    for (int i=0 ;i<nums.size()-1 ; i++){
        if(map.find(nums[i]) == map.end()) map.insert({nums[i], {i}});
        else map.find(nums[i])->second.push_back(i);
    }
    return;
}

void Solution::readMap(unordered_map<int, vector<int>>& map) {
    cout << "Hash Map" << endl;
    for (auto it = map.begin(); it != map.end(); it++) {
        cout << "{" << it->first << ", {";
        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
            cout << *it2 << ", ";
        }
        cout << "}}" << endl;
    }
    return;
}

void Solution::readResult(vector<vector<int>>& triplets) {
    cout << "Triplets: { {";
    for(vector<vector<int>>::iterator it=triplets.begin(); it!=triplets.end(); it++) {
        for(vector<int>::iterator it2=it->begin(); it2!=it->end(); it2++) {
            cout << *it2 << ", ";
        }
        cout << "}, {" << endl;
    }
    cout << "}" << endl;
    return;
}

pair<bool,int> Solution::checkIndex(int index1, int index2, vector<int>& val) {
    bool result;
    int value;
    for (vector<int>::iterator it=val.begin(); it!=val.end(); it++) {
        if (*it != index1 && *it != index2) {
            value = *it;
            result = true;
            break;
        } else {
            result = false;
            value = (int)NULL;
        }
    }
    pair<bool,int> p {result, value};
    return p;
}

bool Solution::checkRepeat(vector<vector<int>>& triplets, vector<int>& triples) {
    bool flag = false;
    for (auto it = triplets.begin(); it!=triplets.end(); it++) {
        for(vector<int>::iterator it2=triples.begin(); it2!=triples.end(); it2++) {
            if (this->vectorContainsInt(*it, *it2)) flag = true;
            else {
                flag = false;
                break;
            }
        }
        if(flag) break;
    }
    return flag;
}

bool Solution::vectorContainsInt(vector<int>& compare, int val) {
    for (vector<int>::iterator it = compare.begin(); it!=compare.end(); it++)
        if (*it == val) return true;
    return false;
}


int main() {
    Solution object;
    vector<vector<int>> result = object.threeSum(nums);
    object.readResult(result);
    return 0;
}