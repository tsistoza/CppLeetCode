// LeetCode 1813
#include <iostream>
#include <string>
#include <unordered_map>

using std::cout, std::endl, std::string;
using std::unordered_map;

static string sentence1 = "My name is Haley";
static string sentence2 = "My Haley";
static string sentence1a = "of";
static string sentence2b = "A lot of words";
static string sentence1c = "Eating right now";
static string sentence2c = "Eating";

namespace Solution {
    class Program {
        public:
            bool areSentencesSimilar(string sentence1, string sentence2);
    };

    bool Program::areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.size() == sentence2.size() && sentence1 == sentence2) return true;
        if (sentence1.size() == sentence2.size() && sentence1 != sentence2) return false;

        string bigger;
        string smaller;

        // Insertion always goes into the smaller sentence.
        if (sentence1.size() < sentence2.size()) {
            bigger = sentence2;
            smaller = sentence1;
        }
        else {
            bigger = sentence1;
            smaller = sentence2;
        }

        // Find the insertion point for smaller
        int i=0,j=0;
        for (; i<bigger.size(); i++) {
            if (bigger[i] == smaller[i]) continue;
            j=i;
            break;
        }


        // all we care about is inserting, we only need to know the insertions window size
        string smallerSubstring = smaller.substr(j, smaller.size()-j);
        int windowSize = 0;
        for (; i<bigger.size(); i++) {
            if (bigger[i] != smaller[j]) {
                windowSize++;
                continue;
            }

            if (smallerSubstring != bigger.substr(i, smaller.size()-j)) continue;
            break;
        }


        if (smaller.size() + windowSize == bigger.size()) return true;
        return false;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.areSentencesSimilar(sentence1, sentence2) << endl;
    cout << obj.areSentencesSimilar(sentence1a, sentence2b) << endl;
    cout << obj.areSentencesSimilar(sentence1c, sentence2c) << endl;
    return 0;
}