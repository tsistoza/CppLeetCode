// LeetCode 2683
#include <iostream>
#include <vector>

using std::cout, std::endl;
using std:: vector;

static vector<int> derived = { 1, 1, 0 }; // Note Derived values are only 1 or 0
static vector<int> derived1 = { 1, 1 };
static vector<int> derived2 = { 1, 0 };

namespace Solution {
    class Program {
        public:
            bool doesValidArrayExist(vector<int>& derived);
    };

    bool Program::doesValidArrayExist(vector<int>& derived)  {
        vector<int> original(derived.size(), 0);

        for(int i=0; i<derived.size(); i++) {
            if (i == derived.size()-1) {
                int check = derived[i] ^ original[i];
                if (original[0] != check) return false;
                continue;
            }
            original[i+1] = derived[i] ^ original[i];
        }
        return true;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.doesValidArrayExist(derived) << endl;
    cout << obj.doesValidArrayExist(derived1) << endl;
    cout << obj.doesValidArrayExist(derived2) << endl;
    return 0;
}