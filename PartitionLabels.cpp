// LeetCode 763
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::cout, std::endl, std::vector;
using std::unordered_map, std::string;

static string s = "ababcc";

namespace Solution {
    class Program {
        private:
            bool checkPartition(unordered_map<char, int>& dict1, unordered_map<char,int>& dict2);
        public:
            static void prettyPrint(vector<int> arr);
            vector<int> partitionLabels(string s);
    };

    void Program::prettyPrint(vector<int> arr) {
        cout << "{ ";
        for (int i : arr)
            cout << i << ", ";
        cout << "}" << endl;
        return;
    }

    bool Program::checkPartition(unordered_map<char,int>& dict1, unordered_map<char,int>& dict2) {
        for (unordered_map<char,int>::iterator it=dict2.begin(); it!=dict2.end(); it++)
            if (dict1[it->first] != dict2[it->first]) return false;
        return true;
    }

    vector<int> Program::partitionLabels(string s) {
        unordered_map<char, int> dict1;
        for (int i=0; i<s.size(); i++)
            dict1[s[i]]++;
        
        vector<int> result;
        for (int i=0; i<s.size();) { // RunTime is stil (O(n))
            unordered_map<char, int> dict2{ {s[i], 1} };
            int j=i+1;
            for (; j<s.size() && !checkPartition(dict1, dict2); j++)
                dict2[s[j]]++;
            string substring = s.substr(i, j-i);
            i=j;
            result.push_back(substring.size());
        }
        return result;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    Program::prettyPrint(obj.partitionLabels(s));
}
