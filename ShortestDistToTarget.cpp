// LeetCode 2515
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout, std::endl, std::vector, std::string, std::min;

static vector<string> words { "hello","i","am","leetcode","hello" };
static string target = "hello";
static int startIndex = 1;

namespace Solution {
    class Program {
        private:
            void dfs_forward(vector<string>& words, string target, int index, int currDistance, int& minDistance);
            void dfs_backward(vector<string>& words, string target, int index, int currDistance, int& minDistance);
        public:
            int closestTarget(vector<string>& words, string target, int startIndex);
    };

    int Program::closestTarget(vector<string>& words, string target, int startIndex) {
        int minDistance = words.size();
        dfs_forward(words, target, startIndex, 0, minDistance);
        if (minDistance == words.size()) return -1; // did not find word, during loop.
        dfs_backward(words, target, startIndex, 0, minDistance);
        return minDistance;
    }

    void Program::dfs_forward(vector<string>& words, string target, int index, int currDistance, int& minDistance) {
        if (currDistance > minDistance) return;
        if (words[index] == target)
            minDistance = min(currDistance, minDistance);

        int newIndex = (index + 1 >= words.size()) ? 0 : index + 1;
        dfs_forward(words, target, newIndex, currDistance+1, minDistance);
        return;
    }

    void Program::dfs_backward(vector<string>& words, string target, int index, int currDistance, int& minDistance) {
        if (currDistance > minDistance) return;
        if (words[index] == target)
            minDistance = min(currDistance, minDistance);
        
        int newIndex = (index - 1 < 0) ? words.size() - 1 : index - 1;
        dfs_backward(words, target, newIndex, currDistance+1, minDistance);
        return;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.closestTarget(words, target, startIndex) << endl;
    return 0;
}
