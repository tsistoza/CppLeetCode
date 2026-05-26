// LeetCode 3120
#include <iostream>
#include <string>
#include <unordered_map>

using std::cout, std::string, std::endl, std::unordered_map;

static string word = "abBCab";

namespace Solution {
    class Program {
        public:
            int numberofSpecialChars(string word);
    };

    int Program::numberofSpecialChars(string word) {
        int numSpecial = 0;
        int offset = 'a' - 'A';
        unordered_map<int, int> count;
        for (char c : word) {
            if (count[(int)c] > 0) continue; // removes duplicate tracking
            count[(int)c]++;

            if (c > 'Z' && count[((int)c - offset)] > 0)
                numSpecial++;
            if (c <= 'Z' && count[((int)c + offset)] > 0)
                numSpecial++;
        }

        return numSpecial;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.numberofSpecialChars(word) << endl;
    return 0;
}