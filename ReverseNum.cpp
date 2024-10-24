#include <iostream>
#include <vector>
#include <string>

using std::cout, std::cin, std::endl;
using std::vector, std::string, std::to_string;
using std::stoi;

static vector<int> nums = {1,13,10,12,31};


namespace Solution {
    class Program {
        public:
            int countDistinctIntegers(vector<int>& nums);
            void reverseNums(vector<int>& nums);
            bool vectorContains(int val, vector<int>& list);
    };

    int Program::countDistinctIntegers(vector<int>& nums) {
        int numDistinct=0;
        vector<int> list;
        this->reverseNums(nums);
        for(vector<int>::iterator it=nums.begin(); it!=nums.end(); it++) {
            if(!(vectorContains(*it, list))) {
                list.push_back(*it);
                numDistinct++;
            }
        }
        return numDistinct;
    }

    bool Program::vectorContains(int val, vector<int>& list) {
        for(vector<int>::iterator it=list.begin(); it!=list.end(); it++)
            if(val == *it) return true;
        return false;
    }

    void Program::reverseNums(vector<int>& nums) {
        string::size_type sz;
        vector<int> reverseNums;
        for(vector<int>::iterator it=nums.begin(); it!=nums.end(); it++) {
            bool beginIsZero = true;
            string reverse = "";
            string s = to_string(*it);
            for(string::reverse_iterator it2=s.rbegin(); it2!=s.rend(); it2++) {
                if(!beginIsZero) reverse += (*it2);
                if(*it2 != '0' && beginIsZero) {
                    beginIsZero = false;
                    reverse += (*it2);
                }
            }
            int number = stoi(reverse);
            reverseNums.push_back(number);
            reverse.clear();
            s.clear();
        }
        for(vector<int>::iterator it=reverseNums.begin(); it!=reverseNums.end(); it++) nums.push_back(*it);
        return;
    }
}

int main () {
    using namespace Solution;
    Program obj;
    cout << obj.countDistinctIntegers(nums) << endl;
    return 0;
}