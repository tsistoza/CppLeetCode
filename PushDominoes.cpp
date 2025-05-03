// LeetCode 838
#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

static string dominoes = "R.L.R.L";

namespace Solution {
    class Program {
        public:
            string pushDominoes(string dominoes);
    };

    string Program::pushDominoes(string dominoes) {
        for (int i=0; i<dominoes.size();) { // This is still O(n)
            if (dominoes[i] == 'R' || dominoes[i] == 'L') { // dont care if domino is pushed
                i++;
                continue;
            }

            int currPtr = i;
            if (i==0) { // begin case, ...L
                while (dominoes[i] == '.' && i<dominoes.size()) i++;
                if (dominoes[i] == 'L') dominoes.replace(currPtr, i, string(i, 'L'));
                continue;
            }

            while (dominoes[i] == '.' && i<dominoes.size()) i++;

            // End Case
            if (i == dominoes.size() && dominoes[currPtr-1] == 'R') { // R...., replace to end 'R'
                dominoes.replace(currPtr, i-currPtr, string(i-currPtr, 'R'));
                break;
            }

            int mid = currPtr + (i-currPtr) / 2;
            if (dominoes[currPtr-1] == 'R' && dominoes[i] == 'L' && (i-currPtr)%2 == 1) { // R.....L, '.' = odd -> mean middle one is untouched
                dominoes.replace(currPtr, i-currPtr, string(mid-currPtr, 'R') + string(1, '.') + string(mid-currPtr, 'L'));
                continue;
            }

            if (dominoes[currPtr-1] == 'R' && dominoes[i] == 'L' && (i-currPtr)%2 == 0) { // R....L, '.' = even -> mean 1st half dots are 'R' other half are 'L'
                dominoes.replace(currPtr, i-currPtr, string(mid-currPtr, 'R') + string(mid-currPtr, 'L'));
                continue;
            }

            if (dominoes[i] == 'L') dominoes.replace(currPtr, i-currPtr, string(i-currPtr, 'L')); // L...L
        }
        string newDom(dominoes);
        return newDom;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.pushDominoes(dominoes) << endl;
}