// LeetCode 2125
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using std::cout, std::endl, std::vector, std::string;
using std::unordered_set;

static vector<string> bank { "011001","000000","010100","001000" };

namespace Solution {
    class Program {
        public:
            int numberOfBeams(vector<string>& bank);
    };

    int Program::numberOfBeams(vector<string>& bank) {
        int devices = 0;
        for (int j=bank[0].size()-1; j>=0; j--)
            devices += (bank[bank.size()-1][j] == '1') ? 1 : 0;

        int numLasers = 0;
        for (int i=bank.size()-2; i>=0; i--) {
            int currDevices = 0;
            for (int j=bank[i].size()-1; j>=0; j--)
                currDevices += (bank[i][j] == '1') ? 1 : 0;

            numLasers += (currDevices * devices);
            if (currDevices == 0) continue;

            devices = currDevices;
        }
        return numLasers;
    }
}

int main() {
    Solution::Program obj;
    cout << obj.numberOfBeams(bank) << endl;
    return 0;
}