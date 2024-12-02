// LeetCode 1455
#include <iostream>
#include <string>
#include <vector>

using std::cout, std::endl;
using std::string, std::vector;

static string sentence = "i love eating burger";
static string searchWord = "burg";
static string sentence1 = "this problem is an easy problem";
static string searchWord1 = "pro";
static string sentence2 = "i am tired";
static string searchWord2 = "you";

namespace Solution {
    class Program {
        public:
            int isPrefixOfWord(string sentence, string searchWord);
    };
    int Program::isPrefixOfWord(string sentence, string searchWord) {
        int word;
        int index;
        for(string::iterator it=sentence.begin(); it!=sentence.end(); it++) {
            if (index == searchWord.size()-1) return word+1;
            if (*it == searchWord[index] && *it != ' ') index++;
            else index = 0;
            if (*it == ' ') {
                word++;
                continue;
            }
        }
        return -1;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.isPrefixOfWord(sentence, searchWord) << endl;
    cout << obj.isPrefixOfWord(sentence1, searchWord1) << endl;
    cout << obj.isPrefixOfWord(sentence2, searchWord2) << endl;
    return 0;
}