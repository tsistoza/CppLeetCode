// LeetCode 3499
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::string, std::vector, std::max, std::min;

static string s = "00100111011";

namespace Solution {
    class Program {
        private:
            void prettyPrint(vector<int>& len);
            int stateMachine(int type, int condition);
        public:
            int maxActiveSectionsAfterTrade(string s);
    };

    void Program::prettyPrint(vector<int>& ans) {
        cout << "{ ";
        for (int i : ans) cout << i << " ";
        cout << "}" << endl;
        return;
    }

    int Program::stateMachine(int type, int condition) {
        int currType = type;
        switch (type) {
            case 0: if (condition == (int)'0') currType++;
                    if (condition == (int)'2') currType=5;
                break;
            case 1: if (condition == (int)'1') currType++;
                break;
            case 2: if (condition == (int)'0') currType++;
                    if (condition == (int)'2') currType=5;
                break;
            case 3: if (condition == (int)'1' || condition == (int)'2') currType++;
                break;
            case 4: if (condition == (int)'0') currType--;
                    else if (condition == (int)'1') currType=2;
                    else if (condition == (int)'2') currType++;
                break;
        }

        return currType;
    }

    int Program::maxActiveSectionsAfterTrade(string s) {
        s.insert(0, "1");
        s += "12";

        int numOnes = 0, currMax = INT_MIN;
        int length1 = 0, length2 = 0, length3 = 0;
        int type = 0;
        for (int i=0; i<s.size(); i++) {
            cout << "type = " << type << ", currChar = " << s[i] << endl;
            switch (type) {
                case 0: numOnes++;
                    break;
                case 1: length1++;
                    break;
                case 2: length2++;
                        numOnes++;
                    break;
                case 3: length3++;
                    break;
                case 4: currMax = max(currMax, length1+length3);
                        length1 = length3;
                        length2 = 1;
                        length3 = 0;
                        numOnes++;
                    break;
                default:
                    break;
            }

            if (s.size() == i) break;
            type = stateMachine(type, (int)s[i + 1]);
        }

        cout << "currMax = " << currMax << ", numOnes = " << numOnes << endl;
        return (currMax > INT_MIN) ? (currMax+numOnes-2) : numOnes-2;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.maxActiveSectionsAfterTrade(s) << endl;
    return 0;
}