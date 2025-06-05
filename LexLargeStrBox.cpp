// LeetCode 3403
#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

static string word = "aann";
static int numFriends = 2;

namespace Solution {
    class Program {
        public:
            string answerString(string word, int numFriends);
    };

    string Program::answerString(string word, int numFriends){
        if (numFriends == 1) return word;
        string ans = "";
        for (int i=0; i<word.size(); i++) {
            string currSplit = word.substr(i, word.size() - numFriends + 1); // Since we have numFriends, we already know the maximum length of the possible split
            ans = (ans.size() < currSplit.size()) ? currSplit : ans; // Find lexographically largest split
            if (ans.size() == currSplit.size()) {
                int j=0;
                while(j<ans.size() && ans[j] != currSplit[j]) j++;
                if (j == ans.size()) continue;
                ans = (ans[j] < currSplit[j]) ? currSplit : ans; 
            }
        }
        return ans;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.answerString(word, numFriends) << endl;
    return 0;
}