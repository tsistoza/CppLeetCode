// LeetCode 22
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using std::cout, std::endl;
using std::vector, std::string;
using std::unordered_map;

static int n = 3;

namespace Solution {
    class Program {
        private:
            void dfs(int pairs, int n, string clone, vector<string>& count, unordered_map<string,int>& dict);
        public:
            vector<string> generateParenthesis(int n);
    };
    vector<string> Program::generateParenthesis(int n) {
        unordered_map<string, int> dict;
        vector<string> count;
        dfs(1, n, "()", count,dict);
        return count;
    }

    void Program::dfs(int pairs, int n, string clone, vector<string>& count, unordered_map<string,int>& dict) {
        if (pairs == n) {
            if (dict.contains(clone)) return;
            dict[clone]++;
            count.push_back(clone);
            return;
        }

        // Add Cover
        string temp = "(";
        temp += clone + ")";
        dfs(pairs+1, n, temp, count, dict);

        // Add Out

        // Front
        string temp1 = "()";
        temp1 += clone;
        dfs(pairs+1, n, temp1, count, dict);

        // Back
        string temp2(clone);
        temp2 += "()";
        dfs(pairs+1, n, temp2, count, dict);
        return;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    for (string s : obj.generateParenthesis(n))
        cout << s << ", ";
    cout << endl;
    return 0;
}