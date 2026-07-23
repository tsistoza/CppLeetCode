// LeetCode 3499
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::string, std::vector, std::max;

static string s = "0100";

namespace Solution {
    class Program {
        private:
            void prettyPrint(vector<int>& len);
            int sumRest(vector<int>& len, int index);
        public:
            int maxActiveSectionsAfterTrade(string s);
    };

    void Program::prettyPrint(vector<int>& ans) {
        cout << "{ ";
        for (int i : ans) cout << i << " ";
        cout << "}" << endl;
        return;
    }

    int Program::sumRest(vector<int>& len, int index) {
        int sum = 0;
        for (int i=0; i<len.size(); i+=2) {
            if (i == index) continue;
            if (i == len.size()-1 || i == 0) {
                sum += len[i]-1;
                continue;
            }
            sum += len[i];
        }
        return sum;
    }

    int Program::maxActiveSectionsAfterTrade(string s) {
        char lastSection = '1';
        vector<int> len;
        for (int i=0, length=1; i<s.size(); i++, length++) {
            if (s[i] != lastSection) {
                lastSection = s[i];
                len.push_back(length);
                length = 0;
                continue;
            }

            if (i == s.size()-1)
                len.push_back(length+1);
        }
        len.push_back(1);

        //prettyPrint(len);

        int ans = INT_MIN;
        for (int i=2, sum=0; i<len.size(); i+=2) {
            if (i+1>=len.size()) continue;
            int currAns = len[i-1] + len[i+1] + len[i];
            currAns += sumRest(len, i);
            ans = max(ans, currAns);
        }

        // no trade
        int sum=0;
        for (int i=2; i<len.size(); i+=2)
            sum += len[i];

        ans = max(ans, sum);
        return ans;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.maxActiveSectionsAfterTrade(s) << endl;
    return 0;
}