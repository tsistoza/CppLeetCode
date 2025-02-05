// LeetCode 1281
#include <iostream>
#include <string>

using std::cout, std::endl, std::string;
using std::to_string;

static int n = 234;
static int n1 = 4421;

namespace Solution {
    class Program {
        public:
            int subtractProductAndSum(int n);
    };

    int Program::subtractProductAndSum(int n) {
        int sum = 0;
        int product = 1;

        string num = to_string(n);
        for (string::iterator it = num.begin(); it!=num.end(); it++) {
            sum += (int) (*it - 48);
            product *= (int) (*it - 48);
        }

        return product - sum;
    }
}

int main() {
    using namespace Solution;
    Program obj;
    cout << obj.subtractProductAndSum(n) << endl;
    cout << obj.subtractProductAndSum(n1) << endl;
    return 0;
}