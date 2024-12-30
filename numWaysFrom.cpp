// LeetCode 1639
#include <iostream>
#include <vector>
#include <string>

using std::cout, std::endl;
using std::vector, std::string;

static vector<string> words { "acca", "bbbb", "caca" };
static string target = "aba";
static vector<string> words1 { "abba", "baab" };
static string target1 = "bab";

namespace Solution {
    class Program {
        private:
            void dfs(vector<string>& words, vector<string>& ways, string target, string ans, int indexTarget, int index);
        public:
            int numWays(vector<string>& words, string target);
    };

    void Program::dfs(vector<string>& words, vector<string>& ways, string target, string ans, int indexTarget, int index) {
        if (ans == target) {
            ways.push_back(ans);
            return;
        }
        
        if ((index >= target.size() && ans != target) || target.size() < ans.size()) return;

        for (string word : words) {
            for (int i=index+1; i<word.size(); i++) {
                if (word[i] == target[indexTarget]) {
                    string temp(ans);
                    temp += word[i];
                    dfs (words, ways, target, temp, indexTarget+1, i);
                }
            }
        }
        return;
    }

    int Program::numWays(vector<string>& words, string target) {
        vector<string> ways;
        string start(1, target[0]);

        for (string word : words) {
            for (int i=0; i<word.size(); i++) {
                if (start[0] == word[i]) {
                    this->dfs(words, ways, target, start, 1, i);
                }
            }
        }
        
        return ways.size();
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.numWays(words, target) << endl;
    cout << obj.numWays(words1, target1) << endl;
    return 0;
}