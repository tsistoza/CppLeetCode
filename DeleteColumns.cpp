// LeetCode 944
#include <iostream>
#include <vector>
#include <string>

using std::cout, std::endl, std::vector;
using std::string;

static vector<string> strs { "zyx","wvu","tsr" };

class Program {
    public:
        int minDeletionSize(vector<string>& strs);
};

int Program::minDeletionSize(vector<string>& strs) {
    int strLength = strs[0].size();
    int numDelete = 0;
    for (int i=0; i<strLength; i++) {
        for (int j=1; j<strs.size(); j++) {
            if (strs[j-1][i] > strs[j][i]) {
                numDelete++;
                break;
            }
        }
    }
    return numDelete;
}

int main() {
    Program obj;
    cout << obj.minDeletionSize(strs) << endl;
    return 0;
}