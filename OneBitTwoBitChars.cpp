// LeetCode 717
#include <iostream>
#include <vector>
#include <ios>

using std::cout, std::endl, std::vector, std::boolalpha;

static vector<int> bits { 1, 1, 1, 0 };

namespace Solution {
    class Program {
        public:
            bool isOneBitCharacter(vector<int>& bits);
    };

    bool Program::isOneBitCharacter(vector<int>& bits) {
        vector<int> characters;
        bool isOneBit = false;
        for (int i=0; i<bits.size(); i++) {
            characters.push_back(bits[i]);
            if (characters[0] == 0) {
                characters.clear();
                isOneBit = true;
                continue;
            }
            if (characters.size() == 2) {
                characters.clear();
                isOneBit = false;
            }
        }
        return isOneBit;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << boolalpha << obj.isOneBitCharacter(bits) << endl;
    return 0;
}